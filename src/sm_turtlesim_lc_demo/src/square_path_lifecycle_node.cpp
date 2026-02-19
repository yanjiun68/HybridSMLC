#include <cmath>
#include <memory>
#include <string>

#include <geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>
#include <rclcpp_lifecycle/lifecycle_publisher.hpp>
#include <turtlesim/msg/pose.hpp>
#include <turtlesim_lc_interfaces/msg/mission_snapshot.hpp>

using rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface;

class SquarePathLifecycleNode : public rclcpp_lifecycle::LifecycleNode
{
public:
  SquarePathLifecycleNode()
  : rclcpp_lifecycle::LifecycleNode("square_path_lifecycle_node")
  {
  }

private:
  enum class MotionPhase
  {
    MOVE_STRAIGHT,
    TURN_90,
    FINISHED
  };

  static constexpr double kHalfPi = 1.5707963267948966;

  LifecycleNodeInterface::CallbackReturn on_configure(const rclcpp_lifecycle::State &)
  {
    side_length_ = this->declare_parameter<double>("side_length", 2.0);
    linear_speed_ = this->declare_parameter<double>("linear_speed", 1.5);
    angular_speed_ = this->declare_parameter<double>("angular_speed", 1.2);
    distance_tolerance_ = this->declare_parameter<double>("distance_tolerance", 0.05);
    angle_tolerance_ = this->declare_parameter<double>("angle_tolerance", 0.03);
    laps_target_ = this->declare_parameter<int>("laps_target", 5);
    publish_rate_hz_ = this->declare_parameter<double>("publish_rate_hz", 20.0);

    cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 20);
    mission_pub_ =
      this->create_publisher<turtlesim_lc_interfaces::msg::MissionSnapshot>(
      "/turtlesim_lc/mission_stream", 20);

    pose_sub_ = this->create_subscription<turtlesim::msg::Pose>(
      "/turtle1/pose", 20,
      std::bind(&SquarePathLifecycleNode::onPose, this, std::placeholders::_1));

    auto period = std::chrono::duration<double>(1.0 / std::max(1.0, publish_rate_hz_));
    control_timer_ = this->create_wall_timer(
      std::chrono::duration_cast<std::chrono::nanoseconds>(period),
      std::bind(&SquarePathLifecycleNode::controlLoop, this));
    control_timer_->cancel();

    resetMissionState();

    RCLCPP_INFO(get_logger(), "Configured lifecycle node");
    return LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  LifecycleNodeInterface::CallbackReturn on_activate(const rclcpp_lifecycle::State &)
  {
    cmd_vel_pub_->on_activate();
    mission_pub_->on_activate();

    resetMissionState();
    control_timer_->reset();

    geometry_msgs::msg::Twist zeroCmd;
    publishSnapshot(zeroCmd, phaseToString(phase_), "STARTING", false);

    RCLCPP_INFO(get_logger(), "Activated lifecycle node");
    return LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  LifecycleNodeInterface::CallbackReturn on_deactivate(const rclcpp_lifecycle::State &)
  {
    if (control_timer_)
    {
      control_timer_->cancel();
    }

    publishStopCommand();

    if (cmd_vel_pub_)
    {
      cmd_vel_pub_->on_deactivate();
    }
    if (mission_pub_)
    {
      mission_pub_->on_deactivate();
    }

    RCLCPP_INFO(get_logger(), "Deactivated lifecycle node");
    return LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  LifecycleNodeInterface::CallbackReturn on_cleanup(const rclcpp_lifecycle::State &)
  {
    if (control_timer_)
    {
      control_timer_->cancel();
      control_timer_.reset();
    }

    pose_sub_.reset();
    cmd_vel_pub_.reset();
    mission_pub_.reset();

    resetMissionState();

    RCLCPP_INFO(get_logger(), "Cleaned up lifecycle node");
    return LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  LifecycleNodeInterface::CallbackReturn on_shutdown(const rclcpp_lifecycle::State &)
  {
    if (control_timer_)
    {
      control_timer_->cancel();
    }

    publishStopCommand();

    RCLCPP_INFO(get_logger(), "Shut down lifecycle node");
    return LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  void onPose(const turtlesim::msg::Pose::SharedPtr msg)
  {
    current_pose_ = *msg;
    if (!has_pose_)
    {
      has_pose_ = true;
      segment_start_x_ = current_pose_.x;
      segment_start_y_ = current_pose_.y;
      turn_start_theta_ = current_pose_.theta;
      turn_target_theta_ = normalizeAngle(turn_start_theta_ + kHalfPi);
    }
  }

  void controlLoop()
  {
    if (!isReadyToPublish())
    {
      return;
    }

    geometry_msgs::msg::Twist cmd;

    if (!has_pose_)
    {
      publishSnapshot(cmd, phaseToString(phase_), "STARTING", mission_done_);
      return;
    }

    if (mission_done_)
    {
      cmd_vel_pub_->publish(cmd);
      publishSnapshot(cmd, "FINISHED", "MISSION_COMPLETE", true);
      return;
    }

    switch (phase_)
    {
      case MotionPhase::MOVE_STRAIGHT:
      {
        const double dx = current_pose_.x - segment_start_x_;
        const double dy = current_pose_.y - segment_start_y_;
        const double traveled = std::hypot(dx, dy);

        if (traveled >= (side_length_ - distance_tolerance_))
        {
          phase_ = MotionPhase::TURN_90;
          turn_start_theta_ = current_pose_.theta;
          turn_target_theta_ = normalizeAngle(turn_start_theta_ + kHalfPi);

          cmd.linear.x = 0.0;
          cmd.angular.z = angular_speed_;
        }
        else
        {
          cmd.linear.x = linear_speed_;
          cmd.angular.z = 0.0;
        }
        break;
      }

      case MotionPhase::TURN_90:
      {
        const double angleError = angularDistance(current_pose_.theta, turn_target_theta_);

        if (std::abs(angleError) <= angle_tolerance_)
        {
          cmd.linear.x = 0.0;
          cmd.angular.z = 0.0;

          if (current_side_ >= 4)
          {
            completed_laps_++;
            current_side_ = 1;
          }
          else
          {
            current_side_++;
          }

          segment_start_x_ = current_pose_.x;
          segment_start_y_ = current_pose_.y;

          if (completed_laps_ >= static_cast<uint32_t>(laps_target_))
          {
            mission_done_ = true;
            phase_ = MotionPhase::FINISHED;
          }
          else
          {
            phase_ = MotionPhase::MOVE_STRAIGHT;
          }
        }
        else
        {
          cmd.linear.x = 0.0;
          cmd.angular.z = (angleError >= 0.0) ? angular_speed_ : -angular_speed_;
        }
        break;
      }

      case MotionPhase::FINISHED:
      default:
      {
        cmd.linear.x = 0.0;
        cmd.angular.z = 0.0;
        mission_done_ = true;
        break;
      }
    }

    cmd_vel_pub_->publish(cmd);

    if (mission_done_)
    {
      publishSnapshot(cmd, "FINISHED", "MISSION_COMPLETE", true);
    }
    else
    {
      publishSnapshot(cmd, phaseToString(phase_), "RUNNING", false);
    }
  }

  void publishStopCommand()
  {
    if (!isReadyToPublish())
    {
      return;
    }

    geometry_msgs::msg::Twist zero;
    cmd_vel_pub_->publish(zero);

    const std::string status = mission_done_ ? "MISSION_COMPLETE" : "RUNNING";
    publishSnapshot(zero, phaseToString(phase_), status, mission_done_);
  }

  void publishSnapshot(
    const geometry_msgs::msg::Twist & cmd,
    const std::string & phase,
    const std::string & status,
    bool missionDone)
  {
    if (!mission_pub_ || !mission_pub_->is_activated())
    {
      return;
    }

    turtlesim_lc_interfaces::msg::MissionSnapshot msg;
    msg.header.stamp = now();
    msg.header.frame_id = "world";
    msg.cmd_vel = cmd;
    msg.trajectory_vector.x = has_pose_ ? current_pose_.x : 0.0;
    msg.trajectory_vector.y = has_pose_ ? current_pose_.y : 0.0;
    msg.trajectory_vector.z = has_pose_ ? current_pose_.theta : 0.0;
    msg.completed_laps = completed_laps_;
    msg.current_side = current_side_;
    msg.phase = phase;
    msg.status = status;
    msg.mission_done = missionDone;

    mission_pub_->publish(msg);
  }

  bool isReadyToPublish() const
  {
    return cmd_vel_pub_ && cmd_vel_pub_->is_activated() && mission_pub_ && mission_pub_->is_activated();
  }

  void resetMissionState()
  {
    has_pose_ = false;
    mission_done_ = false;

    phase_ = MotionPhase::MOVE_STRAIGHT;
    completed_laps_ = 0;
    current_side_ = 1;

    segment_start_x_ = 0.0;
    segment_start_y_ = 0.0;
    turn_start_theta_ = 0.0;
    turn_target_theta_ = 0.0;
  }

  std::string phaseToString(MotionPhase phase) const
  {
    switch (phase)
    {
      case MotionPhase::MOVE_STRAIGHT:
        return "MOVE_STRAIGHT";
      case MotionPhase::TURN_90:
        return "TURN_90";
      case MotionPhase::FINISHED:
      default:
        return "FINISHED";
    }
  }

  static double normalizeAngle(double angle)
  {
    while (angle > M_PI)
    {
      angle -= 2.0 * M_PI;
    }
    while (angle < -M_PI)
    {
      angle += 2.0 * M_PI;
    }
    return angle;
  }

  static double angularDistance(double from, double to)
  {
    return normalizeAngle(to - from);
  }

  double side_length_{2.0};
  double linear_speed_{1.5};
  double angular_speed_{1.2};
  double distance_tolerance_{0.05};
  double angle_tolerance_{0.03};
  int laps_target_{5};
  double publish_rate_hz_{20.0};

  rclcpp_lifecycle::LifecyclePublisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
  rclcpp_lifecycle::LifecyclePublisher<turtlesim_lc_interfaces::msg::MissionSnapshot>::SharedPtr
    mission_pub_;
  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_sub_;
  rclcpp::TimerBase::SharedPtr control_timer_;

  turtlesim::msg::Pose current_pose_;
  bool has_pose_{false};

  MotionPhase phase_{MotionPhase::MOVE_STRAIGHT};
  bool mission_done_{false};

  uint32_t completed_laps_{0};
  uint32_t current_side_{1};

  double segment_start_x_{0.0};
  double segment_start_y_{0.0};
  double turn_start_theta_{0.0};
  double turn_target_theta_{0.0};
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SquarePathLifecycleNode>();
  rclcpp::spin(node->get_node_base_interface());
  rclcpp::shutdown();
  return 0;
}

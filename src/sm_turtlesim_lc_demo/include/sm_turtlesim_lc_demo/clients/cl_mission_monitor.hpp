#pragma once

#include <mutex>
#include <string>

#include <geometry_msgs/msg/twist.hpp>
#include <smacc2/smacc.hpp>
#include <turtlesim_lc_interfaces/msg/mission_snapshot.hpp>

namespace sm_turtlesim_lc_demo
{
class OrMissionMonitor;

template <typename TSource, typename TOrthogonal>
struct EvMissionCompleted : sc::event<EvMissionCompleted<TSource, TOrthogonal>>
{
};

class ClMissionMonitor : public smacc2::ISmaccClient
{
public:
  using MissionSnapshot = turtlesim_lc_interfaces::msg::MissionSnapshot;

  void onInitialize() override
  {
    auto node = getNode();

    node->declare_parameter<std::string>("mission_topic", "/turtlesim_lc/mission_stream");
    node->get_parameter("mission_topic", mission_topic_);

    mission_sub_ = node->create_subscription<MissionSnapshot>(
      mission_topic_,
      rclcpp::QoS(20),
      std::bind(&ClMissionMonitor::onMissionSnapshot, this, std::placeholders::_1));

    mission_pub_ = node->create_publisher<MissionSnapshot>(mission_topic_, rclcpp::QoS(20));
  }

  void resetMissionDoneEvent()
  {
    std::lock_guard<std::mutex> lock(mutex_);
    mission_done_event_sent_ = false;
  }

  void publishTerminalStatus(const std::string & status, bool missionDone)
  {
    MissionSnapshot msg;
    {
      std::lock_guard<std::mutex> lock(mutex_);
      if (has_latest_snapshot_)
      {
        msg = latest_snapshot_;
      }
    }

    msg.header.stamp = getNode()->now();
    msg.header.frame_id = "world";
    msg.status = status;
    msg.mission_done = missionDone;
    msg.phase = (status == "ERROR") ? "ERROR" : "FINISHED";
    msg.cmd_vel = geometry_msgs::msg::Twist();

    mission_pub_->publish(msg);
  }

private:
  void onMissionSnapshot(const MissionSnapshot::SharedPtr msg)
  {
    bool shouldEmit = false;
    {
      std::lock_guard<std::mutex> lock(mutex_);
      latest_snapshot_ = *msg;
      has_latest_snapshot_ = true;

      if (msg->mission_done && !mission_done_event_sent_)
      {
        mission_done_event_sent_ = true;
        shouldEmit = true;
      }
    }

    if (shouldEmit)
    {
      this->postEvent<EvMissionCompleted<ClMissionMonitor, OrMissionMonitor>>();
    }
  }

  std::string mission_topic_;

  rclcpp::Subscription<MissionSnapshot>::SharedPtr mission_sub_;
  rclcpp::Publisher<MissionSnapshot>::SharedPtr mission_pub_;

  std::mutex mutex_;
  MissionSnapshot latest_snapshot_;
  bool has_latest_snapshot_{false};
  bool mission_done_event_sent_{false};
};
}  // namespace sm_turtlesim_lc_demo

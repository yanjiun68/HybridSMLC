// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtlesim_lc_interfaces:msg/MissionSnapshot.idl
// generated code does not contain a copyright notice

#ifndef TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__BUILDER_HPP_
#define TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtlesim_lc_interfaces/msg/detail/mission_snapshot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtlesim_lc_interfaces
{

namespace msg
{

namespace builder
{

class Init_MissionSnapshot_mission_done
{
public:
  explicit Init_MissionSnapshot_mission_done(::turtlesim_lc_interfaces::msg::MissionSnapshot & msg)
  : msg_(msg)
  {}
  ::turtlesim_lc_interfaces::msg::MissionSnapshot mission_done(::turtlesim_lc_interfaces::msg::MissionSnapshot::_mission_done_type arg)
  {
    msg_.mission_done = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_lc_interfaces::msg::MissionSnapshot msg_;
};

class Init_MissionSnapshot_status
{
public:
  explicit Init_MissionSnapshot_status(::turtlesim_lc_interfaces::msg::MissionSnapshot & msg)
  : msg_(msg)
  {}
  Init_MissionSnapshot_mission_done status(::turtlesim_lc_interfaces::msg::MissionSnapshot::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MissionSnapshot_mission_done(msg_);
  }

private:
  ::turtlesim_lc_interfaces::msg::MissionSnapshot msg_;
};

class Init_MissionSnapshot_phase
{
public:
  explicit Init_MissionSnapshot_phase(::turtlesim_lc_interfaces::msg::MissionSnapshot & msg)
  : msg_(msg)
  {}
  Init_MissionSnapshot_status phase(::turtlesim_lc_interfaces::msg::MissionSnapshot::_phase_type arg)
  {
    msg_.phase = std::move(arg);
    return Init_MissionSnapshot_status(msg_);
  }

private:
  ::turtlesim_lc_interfaces::msg::MissionSnapshot msg_;
};

class Init_MissionSnapshot_current_side
{
public:
  explicit Init_MissionSnapshot_current_side(::turtlesim_lc_interfaces::msg::MissionSnapshot & msg)
  : msg_(msg)
  {}
  Init_MissionSnapshot_phase current_side(::turtlesim_lc_interfaces::msg::MissionSnapshot::_current_side_type arg)
  {
    msg_.current_side = std::move(arg);
    return Init_MissionSnapshot_phase(msg_);
  }

private:
  ::turtlesim_lc_interfaces::msg::MissionSnapshot msg_;
};

class Init_MissionSnapshot_completed_laps
{
public:
  explicit Init_MissionSnapshot_completed_laps(::turtlesim_lc_interfaces::msg::MissionSnapshot & msg)
  : msg_(msg)
  {}
  Init_MissionSnapshot_current_side completed_laps(::turtlesim_lc_interfaces::msg::MissionSnapshot::_completed_laps_type arg)
  {
    msg_.completed_laps = std::move(arg);
    return Init_MissionSnapshot_current_side(msg_);
  }

private:
  ::turtlesim_lc_interfaces::msg::MissionSnapshot msg_;
};

class Init_MissionSnapshot_trajectory_vector
{
public:
  explicit Init_MissionSnapshot_trajectory_vector(::turtlesim_lc_interfaces::msg::MissionSnapshot & msg)
  : msg_(msg)
  {}
  Init_MissionSnapshot_completed_laps trajectory_vector(::turtlesim_lc_interfaces::msg::MissionSnapshot::_trajectory_vector_type arg)
  {
    msg_.trajectory_vector = std::move(arg);
    return Init_MissionSnapshot_completed_laps(msg_);
  }

private:
  ::turtlesim_lc_interfaces::msg::MissionSnapshot msg_;
};

class Init_MissionSnapshot_cmd_vel
{
public:
  explicit Init_MissionSnapshot_cmd_vel(::turtlesim_lc_interfaces::msg::MissionSnapshot & msg)
  : msg_(msg)
  {}
  Init_MissionSnapshot_trajectory_vector cmd_vel(::turtlesim_lc_interfaces::msg::MissionSnapshot::_cmd_vel_type arg)
  {
    msg_.cmd_vel = std::move(arg);
    return Init_MissionSnapshot_trajectory_vector(msg_);
  }

private:
  ::turtlesim_lc_interfaces::msg::MissionSnapshot msg_;
};

class Init_MissionSnapshot_header
{
public:
  Init_MissionSnapshot_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MissionSnapshot_cmd_vel header(::turtlesim_lc_interfaces::msg::MissionSnapshot::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MissionSnapshot_cmd_vel(msg_);
  }

private:
  ::turtlesim_lc_interfaces::msg::MissionSnapshot msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_lc_interfaces::msg::MissionSnapshot>()
{
  return turtlesim_lc_interfaces::msg::builder::Init_MissionSnapshot_header();
}

}  // namespace turtlesim_lc_interfaces

#endif  // TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__BUILDER_HPP_

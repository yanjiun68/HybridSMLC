// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlesim_lc_interfaces:msg/MissionSnapshot.idl
// generated code does not contain a copyright notice

#ifndef TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__TRAITS_HPP_
#define TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtlesim_lc_interfaces/msg/detail/mission_snapshot__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'cmd_vel'
#include "geometry_msgs/msg/detail/twist__traits.hpp"
// Member 'trajectory_vector'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace turtlesim_lc_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MissionSnapshot & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: cmd_vel
  {
    out << "cmd_vel: ";
    to_flow_style_yaml(msg.cmd_vel, out);
    out << ", ";
  }

  // member: trajectory_vector
  {
    out << "trajectory_vector: ";
    to_flow_style_yaml(msg.trajectory_vector, out);
    out << ", ";
  }

  // member: completed_laps
  {
    out << "completed_laps: ";
    rosidl_generator_traits::value_to_yaml(msg.completed_laps, out);
    out << ", ";
  }

  // member: current_side
  {
    out << "current_side: ";
    rosidl_generator_traits::value_to_yaml(msg.current_side, out);
    out << ", ";
  }

  // member: phase
  {
    out << "phase: ";
    rosidl_generator_traits::value_to_yaml(msg.phase, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: mission_done
  {
    out << "mission_done: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_done, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MissionSnapshot & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: cmd_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_vel:\n";
    to_block_style_yaml(msg.cmd_vel, out, indentation + 2);
  }

  // member: trajectory_vector
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trajectory_vector:\n";
    to_block_style_yaml(msg.trajectory_vector, out, indentation + 2);
  }

  // member: completed_laps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "completed_laps: ";
    rosidl_generator_traits::value_to_yaml(msg.completed_laps, out);
    out << "\n";
  }

  // member: current_side
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_side: ";
    rosidl_generator_traits::value_to_yaml(msg.current_side, out);
    out << "\n";
  }

  // member: phase
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "phase: ";
    rosidl_generator_traits::value_to_yaml(msg.phase, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: mission_done
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mission_done: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_done, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MissionSnapshot & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace turtlesim_lc_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtlesim_lc_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtlesim_lc_interfaces::msg::MissionSnapshot & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtlesim_lc_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtlesim_lc_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const turtlesim_lc_interfaces::msg::MissionSnapshot & msg)
{
  return turtlesim_lc_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<turtlesim_lc_interfaces::msg::MissionSnapshot>()
{
  return "turtlesim_lc_interfaces::msg::MissionSnapshot";
}

template<>
inline const char * name<turtlesim_lc_interfaces::msg::MissionSnapshot>()
{
  return "turtlesim_lc_interfaces/msg/MissionSnapshot";
}

template<>
struct has_fixed_size<turtlesim_lc_interfaces::msg::MissionSnapshot>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<turtlesim_lc_interfaces::msg::MissionSnapshot>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<turtlesim_lc_interfaces::msg::MissionSnapshot>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__TRAITS_HPP_

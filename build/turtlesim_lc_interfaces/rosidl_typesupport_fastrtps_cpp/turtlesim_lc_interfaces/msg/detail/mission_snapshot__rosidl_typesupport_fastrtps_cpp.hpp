// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from turtlesim_lc_interfaces:msg/MissionSnapshot.idl
// generated code does not contain a copyright notice

#ifndef TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "turtlesim_lc_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "turtlesim_lc_interfaces/msg/detail/mission_snapshot__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace turtlesim_lc_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtlesim_lc_interfaces
cdr_serialize(
  const turtlesim_lc_interfaces::msg::MissionSnapshot & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtlesim_lc_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  turtlesim_lc_interfaces::msg::MissionSnapshot & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtlesim_lc_interfaces
get_serialized_size(
  const turtlesim_lc_interfaces::msg::MissionSnapshot & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtlesim_lc_interfaces
max_serialized_size_MissionSnapshot(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace turtlesim_lc_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_turtlesim_lc_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, turtlesim_lc_interfaces, msg, MissionSnapshot)();

#ifdef __cplusplus
}
#endif

#endif  // TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

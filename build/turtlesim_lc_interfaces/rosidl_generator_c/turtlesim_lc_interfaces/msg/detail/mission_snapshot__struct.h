// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtlesim_lc_interfaces:msg/MissionSnapshot.idl
// generated code does not contain a copyright notice

#ifndef TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__STRUCT_H_
#define TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'cmd_vel'
#include "geometry_msgs/msg/detail/twist__struct.h"
// Member 'trajectory_vector'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'phase'
// Member 'status'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MissionSnapshot in the package turtlesim_lc_interfaces.
typedef struct turtlesim_lc_interfaces__msg__MissionSnapshot
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Twist cmd_vel;
  geometry_msgs__msg__Vector3 trajectory_vector;
  uint32_t completed_laps;
  uint32_t current_side;
  rosidl_runtime_c__String phase;
  rosidl_runtime_c__String status;
  bool mission_done;
} turtlesim_lc_interfaces__msg__MissionSnapshot;

// Struct for a sequence of turtlesim_lc_interfaces__msg__MissionSnapshot.
typedef struct turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence
{
  turtlesim_lc_interfaces__msg__MissionSnapshot * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__STRUCT_H_

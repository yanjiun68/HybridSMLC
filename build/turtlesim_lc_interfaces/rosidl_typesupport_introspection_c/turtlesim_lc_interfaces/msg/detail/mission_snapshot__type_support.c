// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from turtlesim_lc_interfaces:msg/MissionSnapshot.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "turtlesim_lc_interfaces/msg/detail/mission_snapshot__rosidl_typesupport_introspection_c.h"
#include "turtlesim_lc_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "turtlesim_lc_interfaces/msg/detail/mission_snapshot__functions.h"
#include "turtlesim_lc_interfaces/msg/detail/mission_snapshot__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `cmd_vel`
#include "geometry_msgs/msg/twist.h"
// Member `cmd_vel`
#include "geometry_msgs/msg/detail/twist__rosidl_typesupport_introspection_c.h"
// Member `trajectory_vector`
#include "geometry_msgs/msg/vector3.h"
// Member `trajectory_vector`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"
// Member `phase`
// Member `status`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void turtlesim_lc_interfaces__msg__MissionSnapshot__rosidl_typesupport_introspection_c__MissionSnapshot_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlesim_lc_interfaces__msg__MissionSnapshot__init(message_memory);
}

void turtlesim_lc_interfaces__msg__MissionSnapshot__rosidl_typesupport_introspection_c__MissionSnapshot_fini_function(void * message_memory)
{
  turtlesim_lc_interfaces__msg__MissionSnapshot__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtlesim_lc_interfaces__msg__MissionSnapshot__rosidl_typesupport_introspection_c__MissionSnapshot_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_lc_interfaces__msg__MissionSnapshot, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cmd_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_lc_interfaces__msg__MissionSnapshot, cmd_vel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "trajectory_vector",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_lc_interfaces__msg__MissionSnapshot, trajectory_vector),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "completed_laps",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_lc_interfaces__msg__MissionSnapshot, completed_laps),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_side",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_lc_interfaces__msg__MissionSnapshot, current_side),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "phase",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_lc_interfaces__msg__MissionSnapshot, phase),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_lc_interfaces__msg__MissionSnapshot, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mission_done",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_lc_interfaces__msg__MissionSnapshot, mission_done),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers turtlesim_lc_interfaces__msg__MissionSnapshot__rosidl_typesupport_introspection_c__MissionSnapshot_message_members = {
  "turtlesim_lc_interfaces__msg",  // message namespace
  "MissionSnapshot",  // message name
  8,  // number of fields
  sizeof(turtlesim_lc_interfaces__msg__MissionSnapshot),
  turtlesim_lc_interfaces__msg__MissionSnapshot__rosidl_typesupport_introspection_c__MissionSnapshot_message_member_array,  // message members
  turtlesim_lc_interfaces__msg__MissionSnapshot__rosidl_typesupport_introspection_c__MissionSnapshot_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlesim_lc_interfaces__msg__MissionSnapshot__rosidl_typesupport_introspection_c__MissionSnapshot_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlesim_lc_interfaces__msg__MissionSnapshot__rosidl_typesupport_introspection_c__MissionSnapshot_message_type_support_handle = {
  0,
  &turtlesim_lc_interfaces__msg__MissionSnapshot__rosidl_typesupport_introspection_c__MissionSnapshot_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_lc_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_lc_interfaces, msg, MissionSnapshot)() {
  turtlesim_lc_interfaces__msg__MissionSnapshot__rosidl_typesupport_introspection_c__MissionSnapshot_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  turtlesim_lc_interfaces__msg__MissionSnapshot__rosidl_typesupport_introspection_c__MissionSnapshot_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Twist)();
  turtlesim_lc_interfaces__msg__MissionSnapshot__rosidl_typesupport_introspection_c__MissionSnapshot_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!turtlesim_lc_interfaces__msg__MissionSnapshot__rosidl_typesupport_introspection_c__MissionSnapshot_message_type_support_handle.typesupport_identifier) {
    turtlesim_lc_interfaces__msg__MissionSnapshot__rosidl_typesupport_introspection_c__MissionSnapshot_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlesim_lc_interfaces__msg__MissionSnapshot__rosidl_typesupport_introspection_c__MissionSnapshot_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

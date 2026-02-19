// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from turtlesim_lc_interfaces:msg/MissionSnapshot.idl
// generated code does not contain a copyright notice
#include "turtlesim_lc_interfaces/msg/detail/mission_snapshot__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `cmd_vel`
#include "geometry_msgs/msg/detail/twist__functions.h"
// Member `trajectory_vector`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `phase`
// Member `status`
#include "rosidl_runtime_c/string_functions.h"

bool
turtlesim_lc_interfaces__msg__MissionSnapshot__init(turtlesim_lc_interfaces__msg__MissionSnapshot * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    turtlesim_lc_interfaces__msg__MissionSnapshot__fini(msg);
    return false;
  }
  // cmd_vel
  if (!geometry_msgs__msg__Twist__init(&msg->cmd_vel)) {
    turtlesim_lc_interfaces__msg__MissionSnapshot__fini(msg);
    return false;
  }
  // trajectory_vector
  if (!geometry_msgs__msg__Vector3__init(&msg->trajectory_vector)) {
    turtlesim_lc_interfaces__msg__MissionSnapshot__fini(msg);
    return false;
  }
  // completed_laps
  // current_side
  // phase
  if (!rosidl_runtime_c__String__init(&msg->phase)) {
    turtlesim_lc_interfaces__msg__MissionSnapshot__fini(msg);
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    turtlesim_lc_interfaces__msg__MissionSnapshot__fini(msg);
    return false;
  }
  // mission_done
  return true;
}

void
turtlesim_lc_interfaces__msg__MissionSnapshot__fini(turtlesim_lc_interfaces__msg__MissionSnapshot * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // cmd_vel
  geometry_msgs__msg__Twist__fini(&msg->cmd_vel);
  // trajectory_vector
  geometry_msgs__msg__Vector3__fini(&msg->trajectory_vector);
  // completed_laps
  // current_side
  // phase
  rosidl_runtime_c__String__fini(&msg->phase);
  // status
  rosidl_runtime_c__String__fini(&msg->status);
  // mission_done
}

bool
turtlesim_lc_interfaces__msg__MissionSnapshot__are_equal(const turtlesim_lc_interfaces__msg__MissionSnapshot * lhs, const turtlesim_lc_interfaces__msg__MissionSnapshot * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // cmd_vel
  if (!geometry_msgs__msg__Twist__are_equal(
      &(lhs->cmd_vel), &(rhs->cmd_vel)))
  {
    return false;
  }
  // trajectory_vector
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->trajectory_vector), &(rhs->trajectory_vector)))
  {
    return false;
  }
  // completed_laps
  if (lhs->completed_laps != rhs->completed_laps) {
    return false;
  }
  // current_side
  if (lhs->current_side != rhs->current_side) {
    return false;
  }
  // phase
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->phase), &(rhs->phase)))
  {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  // mission_done
  if (lhs->mission_done != rhs->mission_done) {
    return false;
  }
  return true;
}

bool
turtlesim_lc_interfaces__msg__MissionSnapshot__copy(
  const turtlesim_lc_interfaces__msg__MissionSnapshot * input,
  turtlesim_lc_interfaces__msg__MissionSnapshot * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // cmd_vel
  if (!geometry_msgs__msg__Twist__copy(
      &(input->cmd_vel), &(output->cmd_vel)))
  {
    return false;
  }
  // trajectory_vector
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->trajectory_vector), &(output->trajectory_vector)))
  {
    return false;
  }
  // completed_laps
  output->completed_laps = input->completed_laps;
  // current_side
  output->current_side = input->current_side;
  // phase
  if (!rosidl_runtime_c__String__copy(
      &(input->phase), &(output->phase)))
  {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  // mission_done
  output->mission_done = input->mission_done;
  return true;
}

turtlesim_lc_interfaces__msg__MissionSnapshot *
turtlesim_lc_interfaces__msg__MissionSnapshot__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlesim_lc_interfaces__msg__MissionSnapshot * msg = (turtlesim_lc_interfaces__msg__MissionSnapshot *)allocator.allocate(sizeof(turtlesim_lc_interfaces__msg__MissionSnapshot), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtlesim_lc_interfaces__msg__MissionSnapshot));
  bool success = turtlesim_lc_interfaces__msg__MissionSnapshot__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtlesim_lc_interfaces__msg__MissionSnapshot__destroy(turtlesim_lc_interfaces__msg__MissionSnapshot * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtlesim_lc_interfaces__msg__MissionSnapshot__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__init(turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlesim_lc_interfaces__msg__MissionSnapshot * data = NULL;

  if (size) {
    data = (turtlesim_lc_interfaces__msg__MissionSnapshot *)allocator.zero_allocate(size, sizeof(turtlesim_lc_interfaces__msg__MissionSnapshot), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtlesim_lc_interfaces__msg__MissionSnapshot__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtlesim_lc_interfaces__msg__MissionSnapshot__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__fini(turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtlesim_lc_interfaces__msg__MissionSnapshot__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence *
turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence * array = (turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence *)allocator.allocate(sizeof(turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__destroy(turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__are_equal(const turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence * lhs, const turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtlesim_lc_interfaces__msg__MissionSnapshot__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__copy(
  const turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence * input,
  turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtlesim_lc_interfaces__msg__MissionSnapshot);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtlesim_lc_interfaces__msg__MissionSnapshot * data =
      (turtlesim_lc_interfaces__msg__MissionSnapshot *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtlesim_lc_interfaces__msg__MissionSnapshot__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtlesim_lc_interfaces__msg__MissionSnapshot__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtlesim_lc_interfaces__msg__MissionSnapshot__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

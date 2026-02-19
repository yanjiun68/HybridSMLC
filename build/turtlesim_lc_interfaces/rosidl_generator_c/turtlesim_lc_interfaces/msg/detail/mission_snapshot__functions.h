// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from turtlesim_lc_interfaces:msg/MissionSnapshot.idl
// generated code does not contain a copyright notice

#ifndef TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__FUNCTIONS_H_
#define TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "turtlesim_lc_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "turtlesim_lc_interfaces/msg/detail/mission_snapshot__struct.h"

/// Initialize msg/MissionSnapshot message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * turtlesim_lc_interfaces__msg__MissionSnapshot
 * )) before or use
 * turtlesim_lc_interfaces__msg__MissionSnapshot__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_lc_interfaces
bool
turtlesim_lc_interfaces__msg__MissionSnapshot__init(turtlesim_lc_interfaces__msg__MissionSnapshot * msg);

/// Finalize msg/MissionSnapshot message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_lc_interfaces
void
turtlesim_lc_interfaces__msg__MissionSnapshot__fini(turtlesim_lc_interfaces__msg__MissionSnapshot * msg);

/// Create msg/MissionSnapshot message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * turtlesim_lc_interfaces__msg__MissionSnapshot__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_lc_interfaces
turtlesim_lc_interfaces__msg__MissionSnapshot *
turtlesim_lc_interfaces__msg__MissionSnapshot__create();

/// Destroy msg/MissionSnapshot message.
/**
 * It calls
 * turtlesim_lc_interfaces__msg__MissionSnapshot__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_lc_interfaces
void
turtlesim_lc_interfaces__msg__MissionSnapshot__destroy(turtlesim_lc_interfaces__msg__MissionSnapshot * msg);

/// Check for msg/MissionSnapshot message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_lc_interfaces
bool
turtlesim_lc_interfaces__msg__MissionSnapshot__are_equal(const turtlesim_lc_interfaces__msg__MissionSnapshot * lhs, const turtlesim_lc_interfaces__msg__MissionSnapshot * rhs);

/// Copy a msg/MissionSnapshot message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_lc_interfaces
bool
turtlesim_lc_interfaces__msg__MissionSnapshot__copy(
  const turtlesim_lc_interfaces__msg__MissionSnapshot * input,
  turtlesim_lc_interfaces__msg__MissionSnapshot * output);

/// Initialize array of msg/MissionSnapshot messages.
/**
 * It allocates the memory for the number of elements and calls
 * turtlesim_lc_interfaces__msg__MissionSnapshot__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_lc_interfaces
bool
turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__init(turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence * array, size_t size);

/// Finalize array of msg/MissionSnapshot messages.
/**
 * It calls
 * turtlesim_lc_interfaces__msg__MissionSnapshot__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_lc_interfaces
void
turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__fini(turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence * array);

/// Create array of msg/MissionSnapshot messages.
/**
 * It allocates the memory for the array and calls
 * turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_lc_interfaces
turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence *
turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__create(size_t size);

/// Destroy array of msg/MissionSnapshot messages.
/**
 * It calls
 * turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_lc_interfaces
void
turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__destroy(turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence * array);

/// Check for msg/MissionSnapshot message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_lc_interfaces
bool
turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__are_equal(const turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence * lhs, const turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence * rhs);

/// Copy an array of msg/MissionSnapshot messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlesim_lc_interfaces
bool
turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence__copy(
  const turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence * input,
  turtlesim_lc_interfaces__msg__MissionSnapshot__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__FUNCTIONS_H_

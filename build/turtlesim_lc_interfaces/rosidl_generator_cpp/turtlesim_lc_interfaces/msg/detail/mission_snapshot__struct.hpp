// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtlesim_lc_interfaces:msg/MissionSnapshot.idl
// generated code does not contain a copyright notice

#ifndef TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__STRUCT_HPP_
#define TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'cmd_vel'
#include "geometry_msgs/msg/detail/twist__struct.hpp"
// Member 'trajectory_vector'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__turtlesim_lc_interfaces__msg__MissionSnapshot __attribute__((deprecated))
#else
# define DEPRECATED__turtlesim_lc_interfaces__msg__MissionSnapshot __declspec(deprecated)
#endif

namespace turtlesim_lc_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MissionSnapshot_
{
  using Type = MissionSnapshot_<ContainerAllocator>;

  explicit MissionSnapshot_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    cmd_vel(_init),
    trajectory_vector(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->completed_laps = 0ul;
      this->current_side = 0ul;
      this->phase = "";
      this->status = "";
      this->mission_done = false;
    }
  }

  explicit MissionSnapshot_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    cmd_vel(_alloc, _init),
    trajectory_vector(_alloc, _init),
    phase(_alloc),
    status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->completed_laps = 0ul;
      this->current_side = 0ul;
      this->phase = "";
      this->status = "";
      this->mission_done = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _cmd_vel_type =
    geometry_msgs::msg::Twist_<ContainerAllocator>;
  _cmd_vel_type cmd_vel;
  using _trajectory_vector_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _trajectory_vector_type trajectory_vector;
  using _completed_laps_type =
    uint32_t;
  _completed_laps_type completed_laps;
  using _current_side_type =
    uint32_t;
  _current_side_type current_side;
  using _phase_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _phase_type phase;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;
  using _mission_done_type =
    bool;
  _mission_done_type mission_done;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__cmd_vel(
    const geometry_msgs::msg::Twist_<ContainerAllocator> & _arg)
  {
    this->cmd_vel = _arg;
    return *this;
  }
  Type & set__trajectory_vector(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->trajectory_vector = _arg;
    return *this;
  }
  Type & set__completed_laps(
    const uint32_t & _arg)
  {
    this->completed_laps = _arg;
    return *this;
  }
  Type & set__current_side(
    const uint32_t & _arg)
  {
    this->current_side = _arg;
    return *this;
  }
  Type & set__phase(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->phase = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__mission_done(
    const bool & _arg)
  {
    this->mission_done = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtlesim_lc_interfaces::msg::MissionSnapshot_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtlesim_lc_interfaces::msg::MissionSnapshot_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtlesim_lc_interfaces::msg::MissionSnapshot_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtlesim_lc_interfaces::msg::MissionSnapshot_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtlesim_lc_interfaces::msg::MissionSnapshot_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtlesim_lc_interfaces::msg::MissionSnapshot_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtlesim_lc_interfaces::msg::MissionSnapshot_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtlesim_lc_interfaces::msg::MissionSnapshot_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtlesim_lc_interfaces::msg::MissionSnapshot_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtlesim_lc_interfaces::msg::MissionSnapshot_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtlesim_lc_interfaces__msg__MissionSnapshot
    std::shared_ptr<turtlesim_lc_interfaces::msg::MissionSnapshot_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtlesim_lc_interfaces__msg__MissionSnapshot
    std::shared_ptr<turtlesim_lc_interfaces::msg::MissionSnapshot_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MissionSnapshot_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->cmd_vel != other.cmd_vel) {
      return false;
    }
    if (this->trajectory_vector != other.trajectory_vector) {
      return false;
    }
    if (this->completed_laps != other.completed_laps) {
      return false;
    }
    if (this->current_side != other.current_side) {
      return false;
    }
    if (this->phase != other.phase) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    if (this->mission_done != other.mission_done) {
      return false;
    }
    return true;
  }
  bool operator!=(const MissionSnapshot_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MissionSnapshot_

// alias to use template instance with default allocator
using MissionSnapshot =
  turtlesim_lc_interfaces::msg::MissionSnapshot_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace turtlesim_lc_interfaces

#endif  // TURTLESIM_LC_INTERFACES__MSG__DETAIL__MISSION_SNAPSHOT__STRUCT_HPP_

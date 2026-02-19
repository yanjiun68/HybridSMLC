cmake_minimum_required(VERSION 3.8)
project(sm_turtlesim_lc_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(smacc2 REQUIRED)
find_package(nav2_msgs REQUIRED)
find_package(nav2_lifecycle_manager REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(turtlesim REQUIRED)
find_package(turtlesim_lc_interfaces REQUIRED)
find_package(Boost COMPONENTS thread REQUIRED)

include_directories(
  include
  ${smacc2_INCLUDE_DIRS}
)

add_executable(sm_turtlesim_lc_demo_node
  src/sm_turtlesim_lc_demo_node.cpp
)

target_link_libraries(sm_turtlesim_lc_demo_node
  ${smacc2_LIBRARIES}
  ${Boost_LIBRARIES}
)

ament_target_dependencies(sm_turtlesim_lc_demo_node
  rclcpp
  smacc2
  nav2_msgs
  std_msgs
  geometry_msgs
  turtlesim_lc_interfaces
)

add_executable(square_path_lifecycle_node
  src/square_path_lifecycle_node.cpp
)

ament_target_dependencies(square_path_lifecycle_node
  rclcpp
  rclcpp_lifecycle
  geometry_msgs
  std_msgs
  turtlesim
  turtlesim_lc_interfaces
)

install(DIRECTORY include/
  DESTINATION include
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

install(TARGETS
  sm_turtlesim_lc_demo_node
  square_path_lifecycle_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

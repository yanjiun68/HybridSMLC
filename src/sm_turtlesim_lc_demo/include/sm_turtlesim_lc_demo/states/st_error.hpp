#pragma once

#include <smacc2/smacc.hpp>

#include "../clients/cl_mission_monitor.hpp"

namespace sm_turtlesim_lc_demo
{
struct StError : smacc2::SmaccState<StError, SmTurtlesimLcDemo>
{
  using SmaccState::SmaccState;

  static void staticConfigure() {}

  void onEntry()
  {
    ClMissionMonitor * missionMonitor = nullptr;
    this->requiresClient(missionMonitor);
    missionMonitor->publishTerminalStatus("ERROR", false);

    RCLCPP_ERROR(getLogger(), "State: StError. Requesting ROS shutdown.");
    rclcpp::shutdown();
  }
};
}  // namespace sm_turtlesim_lc_demo

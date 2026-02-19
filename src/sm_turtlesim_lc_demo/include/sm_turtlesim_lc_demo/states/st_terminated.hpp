#pragma once

#include <smacc2/smacc.hpp>

#include "../client_behaviors/cb_publish_termination.hpp"
#include "../clients/cl_mission_monitor.hpp"
#include "../orthogonals/or_mission_monitor.hpp"

namespace sm_turtlesim_lc_demo
{
struct StTerminated : smacc2::SmaccState<StTerminated, SmTurtlesimLcDemo>
{
  using SmaccState::SmaccState;

  static void staticConfigure()
  {
    configure_orthogonal<OrMissionMonitor, CbPublishTermination>();
  }

  void onEntry()
  {
    ClMissionMonitor * missionMonitor = nullptr;
    this->requiresClient(missionMonitor);
    missionMonitor->publishTerminalStatus("TERMINATED", true);

    RCLCPP_INFO(getLogger(), "State: StTerminated. Requesting ROS shutdown.");
    rclcpp::shutdown();
  }
};
}  // namespace sm_turtlesim_lc_demo

#pragma once

#include <boost/mpl/list.hpp>
#include <smacc2/smacc.hpp>

#include "../clients/cl_mission_monitor.hpp"
#include "../orthogonals/or_mission_monitor.hpp"

namespace sm_turtlesim_lc_demo
{
struct StShutdown;

struct StMonitorMission : smacc2::SmaccState<StMonitorMission, SmTurtlesimLcDemo>
{
  using SmaccState::SmaccState;

  typedef boost::mpl::list<
    smacc2::Transition<EvMissionCompleted<ClMissionMonitor, OrMissionMonitor>, StShutdown, smacc2::SUCCESS>
  > reactions;

  static void staticConfigure() {}

  void onEntry()
  {
    ClMissionMonitor * missionMonitor = nullptr;
    this->requiresClient(missionMonitor);
    missionMonitor->resetMissionDoneEvent();

    RCLCPP_INFO(getLogger(), "State: StMonitorMission (waiting for mission_done=true)");
  }

  void onExit() { RCLCPP_INFO(getLogger(), "Leaving StMonitorMission"); }
};
}  // namespace sm_turtlesim_lc_demo

#pragma once

#include <boost/mpl/list.hpp>
#include <smacc2/smacc.hpp>

#include "../client_behaviors/cb_startup_managed_nodes.hpp"
#include "../orthogonals/or_lifecycle_manager.hpp"

namespace sm_turtlesim_lc_demo
{
struct StMonitorMission;
struct StError;

struct StStartup : smacc2::SmaccState<StStartup, SmTurtlesimLcDemo>
{
  using SmaccState::SmaccState;

  typedef boost::mpl::list<
    smacc2::Transition<smacc2::EvCbSuccess<CbStartupManagedNodes, OrLifecycleManager>, StMonitorMission, smacc2::SUCCESS>,
    smacc2::Transition<smacc2::EvCbFailure<CbStartupManagedNodes, OrLifecycleManager>, StError, smacc2::ABORT>
  > reactions;

  static void staticConfigure()
  {
    configure_orthogonal<OrLifecycleManager, CbStartupManagedNodes>();
  }

  void onEntry() { RCLCPP_INFO(getLogger(), "State: StStartup"); }
  void onExit() { RCLCPP_INFO(getLogger(), "Leaving StStartup"); }
};
}  // namespace sm_turtlesim_lc_demo

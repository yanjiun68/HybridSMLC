#pragma once

#include <boost/mpl/list.hpp>
#include <smacc2/smacc.hpp>

#include "../client_behaviors/cb_shutdown_managed_nodes.hpp"
#include "../orthogonals/or_lifecycle_manager.hpp"

namespace sm_turtlesim_lc_demo
{
struct StTerminated;
struct StError;

struct StShutdown : smacc2::SmaccState<StShutdown, SmTurtlesimLcDemo>
{
  using SmaccState::SmaccState;

  typedef boost::mpl::list<
    smacc2::Transition<smacc2::EvCbSuccess<CbShutdownManagedNodes, OrLifecycleManager>, StTerminated, smacc2::SUCCESS>,
    smacc2::Transition<smacc2::EvCbFailure<CbShutdownManagedNodes, OrLifecycleManager>, StError, smacc2::ABORT>
  > reactions;

  static void staticConfigure()
  {
    configure_orthogonal<OrLifecycleManager, CbShutdownManagedNodes>();
  }

  void onEntry() { RCLCPP_INFO(getLogger(), "State: StShutdown"); }
  void onExit() { RCLCPP_INFO(getLogger(), "Leaving StShutdown"); }
};
}  // namespace sm_turtlesim_lc_demo

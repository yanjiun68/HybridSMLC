#pragma once

#include <smacc2/smacc.hpp>

#include "orthogonals/or_lifecycle_manager.hpp"
#include "orthogonals/or_mission_monitor.hpp"

namespace sm_turtlesim_lc_demo
{
struct StStartup;

struct SmTurtlesimLcDemo : public smacc2::SmaccStateMachineBase<SmTurtlesimLcDemo, StStartup>
{
  using SmaccStateMachineBase::SmaccStateMachineBase;

  void onInitialize() override
  {
    this->createOrthogonal<OrLifecycleManager>();
    this->createOrthogonal<OrMissionMonitor>();
  }
};
}  // namespace sm_turtlesim_lc_demo

#include "states/st_error.hpp"
#include "states/st_monitor_mission.hpp"
#include "states/st_shutdown.hpp"
#include "states/st_startup.hpp"
#include "states/st_terminated.hpp"

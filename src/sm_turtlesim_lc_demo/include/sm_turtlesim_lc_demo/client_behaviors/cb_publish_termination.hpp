#pragma once

#include <smacc2/smacc.hpp>

#include "../clients/cl_mission_monitor.hpp"
#include "../orthogonals/or_mission_monitor.hpp"

namespace sm_turtlesim_lc_demo
{
class CbPublishTermination : public smacc2::SmaccClientBehavior
{
public:
  void onEntry() override
  {
    ClMissionMonitor * missionMonitor = nullptr;
    this->requiresClient(missionMonitor);

    missionMonitor->publishTerminalStatus("TERMINATED", true);
    this->postEvent<smacc2::EvCbSuccess<CbPublishTermination, OrMissionMonitor>>();
  }
};
}  // namespace sm_turtlesim_lc_demo

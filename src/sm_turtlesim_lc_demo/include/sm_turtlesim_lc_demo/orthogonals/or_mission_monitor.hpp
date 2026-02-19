#pragma once

#include <smacc2/smacc.hpp>

#include "../clients/cl_mission_monitor.hpp"

namespace sm_turtlesim_lc_demo
{
class OrMissionMonitor : public smacc2::Orthogonal<OrMissionMonitor>
{
public:
  void onInitialize() override
  {
    this->createClient<ClMissionMonitor>();
  }
};
}  // namespace sm_turtlesim_lc_demo

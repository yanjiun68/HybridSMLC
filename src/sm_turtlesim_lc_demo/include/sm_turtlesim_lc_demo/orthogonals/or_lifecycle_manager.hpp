#pragma once

#include <smacc2/smacc.hpp>

#include "../clients/cl_lifecycle_manager.hpp"

namespace sm_turtlesim_lc_demo
{
class OrLifecycleManager : public smacc2::Orthogonal<OrLifecycleManager>
{
public:
  void onInitialize() override
  {
    this->createClient<ClLifecycleManager>();
  }
};
}  // namespace sm_turtlesim_lc_demo

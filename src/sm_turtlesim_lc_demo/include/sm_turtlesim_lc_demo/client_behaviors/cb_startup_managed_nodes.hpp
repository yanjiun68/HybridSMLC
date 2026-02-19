#pragma once

#include <smacc2/smacc.hpp>

#include "../clients/cl_lifecycle_manager.hpp"
#include "../orthogonals/or_lifecycle_manager.hpp"

namespace sm_turtlesim_lc_demo
{
class CbStartupManagedNodes : public smacc2::SmaccClientBehavior
{
public:
  void onEntry() override
  {
    ClLifecycleManager * lifecycleManager = nullptr;
    this->requiresClient(lifecycleManager);

    lifecycleManager->sendCommand(
      nav2_msgs::srv::ManageLifecycleNodes::Request::STARTUP,
      [this](bool success, const std::string & message)
      {
        if (success)
        {
          RCLCPP_INFO(getLogger(), "Lifecycle STARTUP succeeded: %s", message.c_str());
          this->postEvent<smacc2::EvCbSuccess<CbStartupManagedNodes, OrLifecycleManager>>();
        }
        else
        {
          RCLCPP_ERROR(getLogger(), "Lifecycle STARTUP failed: %s", message.c_str());
          this->postEvent<smacc2::EvCbFailure<CbStartupManagedNodes, OrLifecycleManager>>();
        }
      });
  }
};
}  // namespace sm_turtlesim_lc_demo

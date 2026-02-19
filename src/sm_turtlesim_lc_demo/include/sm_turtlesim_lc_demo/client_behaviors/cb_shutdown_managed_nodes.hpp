#pragma once

#include <smacc2/smacc.hpp>

#include "../clients/cl_lifecycle_manager.hpp"
#include "../orthogonals/or_lifecycle_manager.hpp"

namespace sm_turtlesim_lc_demo
{
class CbShutdownManagedNodes : public smacc2::SmaccClientBehavior
{
public:
  void onEntry() override
  {
    ClLifecycleManager * lifecycleManager = nullptr;
    this->requiresClient(lifecycleManager);

    lifecycleManager->sendCommand(
      nav2_msgs::srv::ManageLifecycleNodes::Request::SHUTDOWN,
      [this](bool success, const std::string & message)
      {
        if (success)
        {
          RCLCPP_INFO(getLogger(), "Lifecycle SHUTDOWN succeeded: %s", message.c_str());
          this->postEvent<smacc2::EvCbSuccess<CbShutdownManagedNodes, OrLifecycleManager>>();
        }
        else
        {
          RCLCPP_ERROR(getLogger(), "Lifecycle SHUTDOWN failed: %s", message.c_str());
          this->postEvent<smacc2::EvCbFailure<CbShutdownManagedNodes, OrLifecycleManager>>();
        }
      });
  }
};
}  // namespace sm_turtlesim_lc_demo

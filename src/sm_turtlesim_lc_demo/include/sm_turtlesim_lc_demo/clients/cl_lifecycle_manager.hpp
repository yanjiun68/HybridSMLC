#pragma once

#include <functional>
#include <memory>
#include <string>

#include <nav2_msgs/srv/manage_lifecycle_nodes.hpp>
#include <rclcpp/rclcpp.hpp>
#include <smacc2/smacc_client.hpp>

namespace sm_turtlesim_lc_demo
{
class ClLifecycleManager : public smacc2::ISmaccClient
{
public:
  using ManageSrv = nav2_msgs::srv::ManageLifecycleNodes;
  using ResponseCallback = std::function<void(bool, const std::string &)>;

  void onInitialize() override
  {
    auto node = getNode();
    node->declare_parameter<std::string>(
      "lifecycle_manager_service", "/lifecycle_manager_turtlesim/manage_nodes");
    node->get_parameter("lifecycle_manager_service", lifecycle_manager_service_);

    client_ = node->create_client<ManageSrv>(lifecycle_manager_service_);
  }

  void sendCommand(uint8_t command, ResponseCallback callback)
  {
    if (client_ == nullptr)
    {
      callback(false, "Lifecycle manager client is not initialized");
      return;
    }

    if (!client_->wait_for_service(std::chrono::seconds(2)))
    {
      callback(
        false,
        "Lifecycle manager service not available: " + lifecycle_manager_service_);
      return;
    }

    auto request = std::make_shared<ManageSrv::Request>();
    request->command = command;

    auto futureCallback =
      [callback](rclcpp::Client<ManageSrv>::SharedFuture responseFuture)
      {
        try
        {
          auto response = responseFuture.get();
          if (response->success)
          {
            callback(true, "Lifecycle manager command succeeded");
          }
          else
          {
            callback(false, "Lifecycle manager command failed");
          }
        }
        catch (const std::exception & ex)
        {
          callback(false, std::string("Lifecycle manager request exception: ") + ex.what());
        }
      };

    client_->async_send_request(request, futureCallback);
  }

private:
  std::string lifecycle_manager_service_;
  rclcpp::Client<ManageSrv>::SharedPtr client_;
};
}  // namespace sm_turtlesim_lc_demo

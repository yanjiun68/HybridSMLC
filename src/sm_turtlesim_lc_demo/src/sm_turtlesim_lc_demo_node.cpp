#include "sm_turtlesim_lc_demo/sm_turtlesim_lc_demo.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  smacc2::run<sm_turtlesim_lc_demo::SmTurtlesimLcDemo>();
  return 0;
}

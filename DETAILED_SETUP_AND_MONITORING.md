# Turtlesim Lifecycle + SMACC2 Demo: Detailed Setup and Monitoring Guide

This guide explains the full plan and exact commands for the ROS 2 Humble demo in:

`~/workspace/Turtlesim_lc_demo`

## 1) Prerequisites

1. Ubuntu with ROS 2 Humble installed at `/opt/ros/humble`.
2. Packages available in your ROS installation:
   - `smacc2`
   - `nav2_lifecycle_manager`
   - `turtlesim`
3. `colcon` installed.

## 2) Workspace Creation (from scratch)

```bash
cd ~/workspace
mkdir -p Turtlesim_lc_demo/src
cd Turtlesim_lc_demo/src
```

## 3) Create Packages

### 3.1 Interface package

```bash
ros2 pkg create turtlesim_lc_interfaces --build-type ament_cmake --dependencies std_msgs geometry_msgs builtin_interfaces
```

### 3.2 Main SMACC2 package

```bash
ros2 pkg create sm_turtlesim_lc_demo --build-type ament_cmake --dependencies rclcpp rclcpp_lifecycle smacc2 std_msgs geometry_msgs turtlesim nav2_msgs nav2_lifecycle_manager turtlesim_lc_interfaces
```

## 4) Build

```bash
cd ~/workspace/Turtlesim_lc_demo
source /opt/ros/humble/setup.bash
colcon build --symlink-install --cmake-args -DPython3_EXECUTABLE=/usr/bin/python3
source install/setup.bash
```

## 5) Run the Demo

```bash
ros2 launch sm_turtlesim_lc_demo turtlesim_lc_demo.launch.py
```

Launch starts:
1. `turtlesim_node`
2. `square_path_lifecycle_node` (lifecycle node)
3. `lifecycle_manager_turtlesim` (`nav2_lifecycle_manager`)
4. `sm_turtlesim_lc_demo_node` (SMACC2 state machine)

## 6) SMACC2 Plan Flow

1. `StStartup`
   - Sends `STARTUP` command to `/lifecycle_manager_turtlesim/manage_nodes`.
2. `StMonitorMission`
   - Listens to `/turtlesim_lc/mission_stream`.
   - Waits for `mission_done=true`.
3. `StShutdown`
   - Sends `SHUTDOWN` command to lifecycle manager.
4. `StTerminated`
   - Publishes final terminal message on `/turtlesim_lc/mission_stream` with `status=TERMINATED`.
   - Calls `rclcpp::shutdown()`.
5. `StError` (failure path)
   - Publishes terminal message with `status=ERROR`.
   - Calls `rclcpp::shutdown()`.

## 7) Lifecycle Node Mission Logic

1. Activated by lifecycle manager.
2. Subscribes to `/turtle1/pose`.
3. Publishes velocity to `/turtle1/cmd_vel`.
4. Publishes mission snapshots to `/turtlesim_lc/mission_stream`.
5. Performs closed-loop square tracking:
   - `MOVE_STRAIGHT` then `TURN_90`
   - 4 sides = 1 lap
   - stop after 5 laps
6. Publishes `MISSION_COMPLETE` and `mission_done=true`.

## 8) Highlight: How to Monitor the Specific Publishing Topic

Target topic:

`/turtlesim_lc/mission_stream`

Message type:

`turtlesim_lc_interfaces/msg/MissionSnapshot`

### 8.1 Confirm topic type and endpoints

```bash
ros2 topic info /turtlesim_lc/mission_stream -v
```

### 8.2 Live stream monitoring (main command)

```bash
ros2 topic echo /turtlesim_lc/mission_stream
```

### 8.3 Watch only mission status transitions

```bash
ros2 topic echo /turtlesim_lc/mission_stream | grep "status:"
```

Expected sequence:
1. `status: STARTING`
2. many `status: RUNNING`
3. `status: MISSION_COMPLETE`
4. final `status: TERMINATED`

### 8.4 Watch mission completion flag

```bash
ros2 topic echo /turtlesim_lc/mission_stream | grep "mission_done:"
```

Expected:
1. mostly `mission_done: false`
2. final phase includes `mission_done: true`

### 8.5 Monitor publishing rate

```bash
ros2 topic hz /turtlesim_lc/mission_stream
```

Default target is around `20 Hz` (controlled by `publish_rate_hz`).

## 9) Mission Snapshot Field Meaning

1. `cmd_vel`: current command sent to turtle.
2. `trajectory_vector.x`: turtle x.
3. `trajectory_vector.y`: turtle y.
4. `trajectory_vector.z`: turtle theta.
5. `completed_laps`: completed square laps.
6. `current_side`: current side index (1..4).
7. `phase`: `MOVE_STRAIGHT`, `TURN_90`, `FINISHED`, or terminal/error context.
8. `status`: `STARTING`, `RUNNING`, `MISSION_COMPLETE`, `TERMINATED`, `ERROR`.
9. `mission_done`: true when target laps are finished.

## 10) Useful Validation Commands

### 10.1 Verify lifecycle manager service exists

```bash
ros2 service list | grep lifecycle_manager_turtlesim
```

### 10.2 Verify the lifecycle node current state

```bash
ros2 lifecycle get /square_path_lifecycle_node
```

### 10.3 Check turtle velocity and pose

```bash
ros2 topic echo /turtle1/cmd_vel
ros2 topic echo /turtle1/pose
```

## 11) End Condition

1. Turtle completes 5 square laps.
2. `MISSION_COMPLETE` is published.
3. SM sends lifecycle `SHUTDOWN`.
4. Final `TERMINATED` message is published on `/turtlesim_lc/mission_stream`.
5. Launch exits and all nodes stop.


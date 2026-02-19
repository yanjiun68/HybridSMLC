# Modification 01: Pause/Stop Control + Rotation Report

## Summary
Create a new Markdown file at:

`/home/yanjiun68/workspace/Turtlesim_lc_demo/modification_01.md`

It will sit alongside `DETAILED_SETUP_AND_MONITORING.md` and contain:
1. The agreed modification plan (`pause` toggle, `stop` terminate, `/report` on each 90-degree turn).
2. A ROS 2 command cheat sheet for launching and monitoring topics.

## File Content Specification (`modification_01.md`)
1. **Title**
   - `# Modification 01: Pause/Stop Control + Rotation Report`

2. **Scope**
   - Add `/turtlesim_lc/control_cmd` (`std_msgs/String`) with `pause` and `stop`.
   - Add `/report` with custom `RotationReport`.
   - Keep existing SMACC2 lifecycle flow.

3. **Behavior Rules**
   - `pause`: toggle pause/resume.
   - `stop`: immediate halt + mission termination path.
   - Publish one `/report` message per completed 90-degree turn.

4. **Required Message Definition**
   - `turtlesim_lc_interfaces/msg/RotationReport.msg`:
     - `std_msgs/Header header`
     - `uint32 completed_laps`
     - `uint32 current_side`
     - `uint32 completed_rotations`

5. **Implementation Notes**
   - Lifecycle node adds control subscriber, report publisher, state flags/counters.
   - Publish `PAUSED` and `STOPPED_BY_USER` status in mission stream.
   - On turn completion, increment `completed_rotations` and publish `/report`.

6. **ROS 2 Command Cheat Sheet**
   - Source env:
     ```bash
     source /opt/ros/humble/setup.bash
     source ~/workspace/Turtlesim_lc_demo/install/setup.bash
     ```
   - Launch demo:
     ```bash
     ros2 launch sm_turtlesim_lc_demo turtlesim_lc_demo.launch.py
     ```
   - Run keyboard command node (separate terminal):
     ```bash
     ros2 run sm_turtlesim_lc_demo keyboard_command_node
     ```
   - Monitor mission stream:
     ```bash
     ros2 topic echo /turtlesim_lc/mission_stream
     ros2 topic echo /turtlesim_lc/mission_stream | grep "status:\|mission_done:"
     ```
   - Monitor control topic:
     ```bash
     ros2 topic echo /turtlesim_lc/control_cmd
     ```
   - Monitor rotation reports:
     ```bash
     ros2 topic echo /report
     ros2 topic hz /report
     ```
   - Verify types:
     ```bash
     ros2 topic info /report -v
     ros2 interface show turtlesim_lc_interfaces/msg/RotationReport
     ```

7. **Expected Runtime Signals**
   - Mission status progression: `STARTING -> RUNNING -> PAUSED (if commanded) -> RUNNING -> MISSION_COMPLETE -> TERMINATED`
   - `/report` count target for 5 laps: `20` messages.

8. **Acceptance Checklist**
   - `pause` toggles movement without resetting progress.
   - `stop` triggers clean mission termination.
   - `/report` publishes once per completed turn.
   - Existing launch shutdown behavior remains clean.

## Public Interfaces/Types Affected
1. New topic: `/turtlesim_lc/control_cmd` (`std_msgs/msg/String`)
2. New message: `turtlesim_lc_interfaces/msg/RotationReport`
3. New topic: `/report` (`turtlesim_lc_interfaces/msg/RotationReport`)

## Test Scenarios
1. Pause/resume twice mid-lap and verify side/lap continuity.
2. Stop during movement and verify mission ends cleanly.
3. Full 5-lap run and verify `/report` publishes 20 entries.

## Assumptions and Defaults
1. Filename is `modification_01.md`.
2. Location is workspace root beside `DETAILED_SETUP_AND_MONITORING.md`.
3. Content includes both detailed plan and command summary (as requested).

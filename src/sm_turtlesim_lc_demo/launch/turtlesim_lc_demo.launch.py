from launch import LaunchDescription
from launch.actions import EmitEvent, RegisterEventHandler
from launch.event_handlers import OnProcessExit
from launch.events import Shutdown
from launch_ros.actions import Node


def generate_launch_description():
    turtlesim_node = Node(
        package='turtlesim',
        executable='turtlesim_node',
        name='turtlesim',
        output='screen',
    )

    lifecycle_square_node = Node(
        package='sm_turtlesim_lc_demo',
        executable='square_path_lifecycle_node',
        name='square_path_lifecycle_node',
        output='screen',
    )

    lifecycle_manager_node = Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        name='lifecycle_manager_turtlesim',
        output='screen',
        parameters=[
            {'autostart': False},
            {'node_names': ['square_path_lifecycle_node']},
            {'bond_timeout': 0.0},
            {'attempt_respawn_reconnection': False},
        ],
    )

    sm_node = Node(
        package='sm_turtlesim_lc_demo',
        executable='sm_turtlesim_lc_demo_node',
        name='sm_turtlesim_lc_demo_node',
        output='screen',
    )

    shutdown_on_sm_exit = RegisterEventHandler(
        OnProcessExit(
            target_action=sm_node,
            on_exit=[
                EmitEvent(event=Shutdown(reason='SMACC2 mission finished')),
            ],
        )
    )

    return LaunchDescription([
        turtlesim_node,
        lifecycle_square_node,
        lifecycle_manager_node,
        sm_node,
        shutdown_on_sm_exit,
    ])

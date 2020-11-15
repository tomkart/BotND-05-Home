#!/bin/sh
export TURTLEBOT_3D_SENSOR=hokuyo

xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
xterm  -e  " roslaunch turtlebot_gazebo amcl_demo.launch " & 
sleep 5
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 10
xterm -e " rosrun pick_markers pick_markers " &
sleep 1
xterm -e " rosrun pick_objects pick_objects_node " &
sleep 5

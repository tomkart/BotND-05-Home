#!/bin/sh
export TURTLEBOT_3D_SENSOR=hokuyo

xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
xterm  -e  " roslaunch turtlebot_gazebo gmapping_demo.launch " & 
sleep 5

xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5

xterm -e "roslaunch turtlebot_navigation gmapping.launch " &
sleep 5
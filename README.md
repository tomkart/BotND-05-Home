# BotND-04-Map

Project: Map My World

Install rtabmap
```
sudo apt-get install ros-kinetic-rtabmap-ros
```

**To run**
First, launch the Gazebo world and RViz, spawn the robot in the environment:
```
cd ~/BotND-04-Map
cd src
catkin_init_workspace

cd ..
catkin_make
source devel/setup.bash
roslaunch my_robot world.launch
```
![Gazebo and RViz](BotND-04-Map-Gazebo.png)

Open another terminal
Then, launch the teleop node:
```
cd ~/BotND-04-Map
source devel/setup.bash
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```
Open another terminal
Finally, launch your mapping node:
```
cd ~/BotND-04-Map
source devel/setup.bash
roslaunch my_robot mapping.launch
```
Navigate the robot in the simulation to create map for the environment! When you are all set, terminal the node and you could find your map db file in the place you specified in the launch file. It will be located in the ~/.ros/ folder.




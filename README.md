# BotND-05-Home

Project: Home Service Robot

**Setup**
```
cd ~/BotND-05-Home
catkin_make
source devel/setup.bash

```

**Mapping**
```
./src/scripts/test_slam.sh 

```
![Gazebo and RViz](BotND-04-Map-Gazebo.png)

Open another terminal
Then, launch the teleop node:
```
cd ~/BotND-05-Map
source devel/setup.bash
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```




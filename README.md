# BotND-05-Home

Project: Home Service Robot

**Setup**
```
cd ~/BotND-05-Home
catkin_make
source devel/setup.bash
export TURTLEBOT_GAZEBO_WORLD_FILE=~/BotND-05-Home/src/turtlebot_simulator/turtlebot_gazebo/worlds/playground.world
export TURTLEBOT_GAZEBO_MAP_FILE=~/BotND-05-Home/src/turtlebot_simulator/turtlebot_gazebo/maps/playground.yaml


```

**1. Mapping**
```
./src/scripts/test_slam.sh 

```
Drive the robot around to scan the map
![Mapping](test_slam.gif)

**2. Localization and Navigation**
Part 1 - Navigation stack 

Kill all previous terminals and open a new one
```
./src/scripts/test_navigation.sh 
```
Using "2D Nav Goal" 
![Navigation](test_navigation.gif)

Part 2 - Goal node function 
```
./src/scripts/pick_objects.sh 
```
**3. Home Service Functions**
Part 1 - Create virtual object with markers
```
./src/scripts/add_marker.sh 
```
![Add Maker](add_marker.png)
Part 2 - Home service 
```
./src/scripts/home_service.sh 
```


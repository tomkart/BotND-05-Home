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
Gmapping is used for mapping. We can drive the robot around to scan the map and use map server to save the map for next section.

![Mapping](test_slam.gif)

**2. Localization and Navigation**
Part 1 - Navigation stack 

amcl is used here for localization and navigating the robot on the saved 2D map.

Kill all previous terminals and open a new one
```
./src/scripts/test_navigation.sh 
```
Using "2D Nav Goal" 
![Navigation](test_navigation.gif)

Part 2 - Goal node function 
Inside pick_objects.sh, pick_objects_node is called and sending goal requests to the move_base server through a SimpleActionClient

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

<a href="http://www.youtube.com/watch?feature=player_embedded&v=0ej-wyt03KI
" target="_blank"><img src="http://img.youtube.com/vi/0ej-wyt03KI/0.jpg" 
alt="Home Service" border="5" /></a>

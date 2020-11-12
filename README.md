# BotND-05-Home

Project: Home Service Robot

**Setup**
```
cd ~/BotND-05-Home
catkin_make
source devel/setup.bash

```

**1. Mapping**
```
./src/scripts/test_slam.sh 

```
Drive the robot around to scan the map
![Mapping](test_slam.gif)

**2. Localization and Navigation
Kill all previous terminals and open a new one
```
cd ~/BotND-05-Map
source devel/setup.bash
./src/scripts/test_navigation.sh 
```
Using "2D Nav Goal" 
![Navigation](test_navigation.gif)


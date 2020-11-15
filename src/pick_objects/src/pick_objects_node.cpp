#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <std_msgs/UInt8.h>

enum State { start, arrived_pickup, arrived_dropoff };

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  std_msgs::UInt8 state;

  // Initialize the pick_objects node
  ros::init(argc, argv, "pick_objects");

  // pub
  ros::NodeHandle n;
  ros::Publisher state_pub = n.advertise<std_msgs::UInt8>("state", 100);
  state.data = start;
  state_pub.publish(state);

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

 
  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "base_link";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 3.0;
  goal.target_pose.pose.orientation.w = 1.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Going to pickup: %f,%f",goal.target_pose.pose.position.x,goal.target_pose.pose.position.y);
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("Arrived pickup: %f,%f",goal.target_pose.pose.position.x,goal.target_pose.pose.position.y);
    state.data = arrived_pickup;
    state_pub.publish(state);
  }  
  else
  {
    ROS_INFO("The base failed to move to pickup");
  }
  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for pickup");
  }


 // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 0.0;
  goal.target_pose.pose.position.y =  -3.0;
  goal.target_pose.pose.orientation.w = 1.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Going to drop off point: %f,%f",goal.target_pose.pose.position.x,goal.target_pose.pose.position.y);
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("Arrived drop off point: %f,%f",goal.target_pose.pose.position.x,goal.target_pose.pose.position.y);
    state.data = arrived_dropoff;
    state_pub.publish(state);
  }
  else
  {
    ROS_INFO("The base failed to move to drop off point");
  }

  return 0;
}

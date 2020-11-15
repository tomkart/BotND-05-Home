#include <ros/ros.h>
#include "std_msgs/String.h"
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/UInt8.h>

enum State { start, arrived_pickup, arrived_dropoff };
visualization_msgs::Marker marker;
ros::Publisher marker_pub;

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
 	//ROS_INFO("odom: [%f,%f,%f]", msg->pose.pose.position.x,msg->pose.pose.position.y,msg->pose.pose.position.z);
}

void stateCallback(const std_msgs::UInt8::ConstPtr& msg)
{
  uint8_t state = msg->data;

  ROS_INFO("state: [%d]", state);
  
  switch(state)
  {
    case start:  
		break;

    case arrived_pickup:
        marker.action = visualization_msgs::Marker::DELETE;
		marker_pub.publish(marker);
        break;

    case arrived_dropoff:
        ROS_INFO("Marker Dropoff");
		marker.action = visualization_msgs::Marker::ADD;        
		marker.pose.position.x = 0.2;
        marker.pose.position.y = 0;
        marker_pub.publish(marker);
		break;

	default:
		break;

  }
}

int main( int argc, char** argv )
{
	ros::init(argc, argv, "base_shapes");

	//subscribe to robot's odom and state
	ros::NodeHandle n;
	ros::Rate r(1);
	marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

	ros::Subscriber subodom = n.subscribe("odom", 1000, odomCallback);
	ros::Subscriber substate = n.subscribe("state", 100, stateCallback);
 
	// Set the frame ID and timestamp.  See the TF tutorials for information on these.
	marker.header.frame_id = "/base_link";
	marker.header.stamp = ros::Time::now();


	// Set the namespace and id for this marker.  This serves to create a unique ID
	// Any marker sent with the same namespace and id will overwrite the old one
	marker.ns = "basic_shapes";
	marker.id = 0;

	// Set our initial shape type to be a cube
    uint32_t shape = visualization_msgs::Marker::CUBE;
	// Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
	marker.type = shape;

	// Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::DELETEALL;
    marker_pub.publish(marker);

	marker.action = visualization_msgs::Marker::ADD;

	// Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
	marker.pose.position.x = 3.0;
	marker.pose.position.y = 0.0;
	marker.pose.position.z = 0.1;
	marker.pose.orientation.x = 0.0;
	marker.pose.orientation.y = 0.0;
	marker.pose.orientation.z = 0.0;
	marker.pose.orientation.w = 1.0;

	// Set the scale of the marker -- 1x1x1 here means 1m on a side
	marker.scale.x = 0.2;
	marker.scale.y = 0.2;
	marker.scale.z = 0.2;

	// Set the color -- be sure to set alpha to something non-zero!
	marker.color.r = 0.0f;
	marker.color.g = 1.0f;
	marker.color.b = 0.0f;
	marker.color.a = 1.0;


	// Publish the marker
	while (marker_pub.getNumSubscribers() < 1)
	{
		if (!ros::ok())
		{
			return 0;
		}
		ROS_WARN_ONCE("Please create a subscriber to the marker");
		sleep(1);
	}
    ROS_WARN_ONCE("Publish marker at Pickup");
    marker_pub.publish(marker);

	ros::spin();

	return 0;

}

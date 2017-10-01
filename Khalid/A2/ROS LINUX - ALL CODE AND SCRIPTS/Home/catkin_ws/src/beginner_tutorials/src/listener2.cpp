
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

void listen2(const geometry_msgs::Twist::ConstPtr& vel)
{
  ROS_INFO("LINEAR : x: [%f] y: [%f] z: [%f]", vel->linear.x, vel->linear.y, vel->linear.z);
  ROS_INFO("ANGULAR: x: [%f] y: [%f] z: [%f]", vel->angular.x, vel->angular.y, vel->angular.z);
  //ROS_INFO(“Linear Vel: %0.2f, Angular Vel: %0.2f”, msg->twist.twist.linear.x,msg>twist.twist.angular.z)};
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "odom_listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("cmd_vel", 1000, listen2);
  ros::spin();
  return 0;
}


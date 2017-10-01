
#include "ros/ros.h"
#include "nav_msgs/Odometry.h"

int boundary_x = false;
int boundary_y = false;

void chatterCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  if(msg->pose.pose.position.x < 5 && boundary_x){
    ROS_INFO("in range of x axis");
    boundary_x = true;
  }
  if(msg->pose.pose.position.x < 5 && boundary_y){
    ROS_INFO("in range of y axis");
    boundary_y = true;
  }
  if(msg->pose.pose.position.x > 5 && boundary_x){
    ROS_INFO("5m mark has been exceeded along the x axis");
    boundary_x = false; 
  }
  if(msg->pose.pose.position.x > 5 && boundary_y){
    ROS_INFO("5m mark has been exceeded along the x axis");
    boundary_y = false; 
  }
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("odom", 1000, chatterCallback);
  ros::spin();
  return 0;

}


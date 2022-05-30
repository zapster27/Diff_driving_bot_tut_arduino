#include "ros/ros.h"
#include "std_msgs/String.h"
#include "nav_msgs/Odometry.h"

void odomCalculator(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "odom_pub");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("tick_msg", 1000, odomCalculator);


  ros::spin();

  return 0;
}

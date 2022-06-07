#include "ros/ros.h"
#include "std_msgs/String.h"
#include "nav_msgs/Odometry.h"
#include <cstring>
#include <iostream>
#include <tf/transform_broadcaster.h>

int wheelDiameter = 80;
int wheelTrack = 341;
int CPR = 494;
float dX = 0, dY = 0;
double X = 0, Y = 0;
float Theta = 0;

double VX = 0;
double W = 0;

double QW = 0, QX = 0, QY = 0, QZ = 0;
geometry_msgs::Quaternion odom_quat;

template <typename T>
const int BASE_LINK_TO_WHEELS_X = 138.67/1000;
const int BASE_LINK_TO_WHEELS_Y = 0;
const int BASE_LINK_TO_WHEELS_Z = (42-25.4)/1000;
int sign(T val)
{
  return (T(0) < val) - (val < T(0));
}

void odomCalculator(const std_msgs::String::ConstPtr &msg)
{
  int receivedTickInfo[3] = {0};
  char tickMsg[strlen(msg->data.c_str()) + 1];
  strcpy(tickMsg, msg->data.c_str());
  // std::cout << tickMsg;

  int arrayPoint = 0;

  char *msgUnit = strtok(tickMsg, ",");

  while (msgUnit != NULL)
  {
    receivedTickInfo[arrayPoint] = std::stoi(msgUnit);
    arrayPoint++;
    msgUnit = strtok(NULL, ",");
    // std::cout << msgUnit;
  }

  // for (size_t i = 0; i < 3; i++)
  // {
  //   std::cout << receivedTickInfo[i] << ' ';
  // }

  int leftCount = receivedTickInfo[0];
  int rightCount = receivedTickInfo[1];
  int deltaT = receivedTickInfo[2];

  float DLeft = 2 * M_PI * (wheelDiameter * 0.5) * leftCount / (CPR * 1000);
  float DRight = 2 * M_PI * (wheelDiameter * 0.5) * rightCount / (CPR * 1000);
  float DCenter = (DRight + DLeft) / 2;

  float VLeft = DLeft * 1000 / deltaT;
  float VRight = DRight * 1000 / deltaT;

  float dtheta = (DRight - DLeft) / wheelTrack;

  if (DLeft == DRight)
  {
    dX = DRight * cos(Theta);
    dY = DRight * sin(Theta);
  }
  else
  {
    double radius = DCenter / dtheta;

    double iccX = X - radius * sin(Theta);
    double iccY = Y + radius * cos(Theta);

    dX = radius * sin(dtheta + Theta) + iccX - X;
    dY = iccY - radius * cos(dtheta + Theta) - Y;
  }

  X += dX;
  Y += dY;
  Theta = (Theta + dtheta);

  while (Theta >= 2 * M_PI)
  {
    Theta -= 2 * M_PI;
  }

  VX = dX * 1000 / deltaT;
  W = dtheta * 1000 / deltaT;

  odom_quat = tf::createQuaternionMsgFromYaw(Theta);

  // QW = cos(abs(Theta) / 2.0f);
  // QX = 0.0f;
  // QY = 0.0f;
  // QZ = sign(Theta) * sin(abs(Theta) / 2.0f);

  dtheta = 0;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "odom_pub");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("tick_msg", 1000, odomCalculator);

  ros::Publisher odom_publisher = nh.advertise<nav_msgs::Odometry>("odom", 1000);

  nav_msgs::Odometry odom;
  tf::TransformBroadcaster odom_broadcaster;

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    ros::Time current_time = ros::Time::now();
    geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = current_time;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_link";

    odom_trans.transform.translation.x = X + BASE_LINK_TO_WHEELS_X;
    odom_trans.transform.translation.y = Y + BASE_LINK_TO_WHEELS_Y;
    odom_trans.transform.translation.z = 0.0;
    odom_trans.transform.rotation = odom_quat;

    // send the transform
    odom_broadcaster.sendTransform(odom_trans);

    odom.header.stamp = current_time;
    odom.header.frame_id = "odom";
    odom.child_frame_id = "base_link";
    odom.pose.pose.position.x = X;
    odom.pose.pose.position.y = Y;
    odom.pose.pose.position.z = 0.0;
    odom.pose.pose.orientation = odom_quat;

    odom.twist.twist.linear.x = VX;
    odom.twist.twist.linear.y = 0.0;
    odom.twist.twist.angular.z = W;

    odom_publisher.publish(odom);
    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}

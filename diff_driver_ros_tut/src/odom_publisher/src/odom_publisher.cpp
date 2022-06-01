#include "ros/ros.h"
#include "std_msgs/String.h"
#include "nav_msgs/Odometry.h"
#include <cstring>
#include <iostream>

void odomCalculator(const std_msgs::String::ConstPtr& msg)
{
  char tickMsg[strlen(msg->data.c_str()) + 1];
  strcpy(tickMsg, msg->data.c_str());
  std::cout << tickMsg;



   char *msgUnit;
   int iCurName = 0;

   /* get the first token */
   msgUnit = strtok(tickMsg, ",");
   char * newName[4]; 
   
   while( msgUnit != NULL ) 
   {
      std::cout << msgUnit;
      newName[iCurName] = malloc (char *) (strlen(msgUnit) + 1);
      strcpy(newName[iCurName],msgUnit);
      iCurName ++;

      msgUnit = strtok(NULL, ",");
   }


}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "odom_pub");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("tick_msg", 1000, odomCalculator);


  ros::spin();

  return 0;
}

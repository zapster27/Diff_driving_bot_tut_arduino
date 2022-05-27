#include <Wire.h>
#include <MPU6050.h>
#include "TimerOne.h"
#include "DualVNH5019MotorShield.h"
#include <PID.h>


#include <ros.h>
#include <tf/tf.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>

ros::NodeHandle  nh;
nav_msgs::Odometry odom;
ros::Publisher odom_publisher("odom", &odom);


float X = 0;
float Y = 0;
float Theta = 0;

float QX = 0;
float QY = 0;
float QZ = 0;
float QW = 0;

float VX = 0;
float W = 0;
double DT = 0;

double RSTtime = 0;
const int default_vel = 100;
float aX = 0, aY = 0, aZ = 0, gX = 0, gY = 0, gZ = 0;

int oldMillis = 0;
int imuSeqCounter = 1;
void cmd_vel_cb(const geometry_msgs::Twist & msg) {
  // Read the message. Act accordingly.
  // We only care about the linear x, and the rotational z.
  const float x = msg.linear.x;
  const float z_rotation = msg.angular.z;
  int right_cmd = x * default_vel * min(1, max(z_rotation * 1.5 + 1, -1));
  int left_cmd =  x * default_vel * min(1, max(-z_rotation * 1.5 + 1 , -1));

  SetSpeedLeft(left_cmd);
  SetSpeedRight(right_cmd);
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", cmd_vel_cb);

template <typename type>
type sign(type value) {
    return type((value>0)-(value<0));
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting init...");

  //  IMUInit();
  Serial.println("IMU initialized");
  oldMillis = millis();

  EncoderInit();
  Serial.println("Encoder initialized");
  nh.initNode();
  nh.advertise(odom_publisher);
  Serial.println("Advertising Topics");

  delay(500);
  RSTtime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - oldMillis >= 100) {
    //    readData();

    // feed odom message
    odom.header.stamp = nh.now();
    odom.header.frame_id = "odom";
    odom.child_frame_id = "base_link";
    odom.pose.pose.position.x = X;
    odom.pose.pose.position.y = Y;
    odom.pose.pose.position.z = 0.0;
    odom.pose.pose.orientation.w = QW;
    odom.pose.pose.orientation.x = QX;
    odom.pose.pose.orientation.y = QY;
    odom.pose.pose.orientation.z = QZ;
    // Velocity expressed in base_link frame
    odom.twist.twist.linear.x = VX;
    odom.twist.twist.linear.y = 0.0f;
    odom.twist.twist.angular.z = W;

    odom_publisher.publish(&odom);

    oldMillis = millis();
    nh.spinOnce();
  }
  //  delay(1000);
}

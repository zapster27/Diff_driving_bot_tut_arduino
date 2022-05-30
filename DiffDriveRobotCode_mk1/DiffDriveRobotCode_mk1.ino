#include <Wire.h>
#include <MPU6050.h>
#include "TimerOne.h"
#include "DualVNH5019MotorShield.h"
#include <PID.h>


#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle  nh;

std_msgs::String tick_msg;
ros::Publisher tickMsg("tick_msg", &tick_msg);

double DT = 0;
double tickLeft = 0;
double tickRight = 0;
double RSTtime = 0;

float aX = 0, aY = 0, aZ = 0, gX = 0, gY = 0, gZ = 0;

int oldMillis = 0;

void cmd_vel_cb(const geometry_msgs::Twist & msg) {
  float x = msg.linear.x;
  float z_rotation = msg.angular.z;
  x = x * 11 / 0.22;
  z_rotation = z_rotation / 2.84;
  float speed_wish_right = ( z_rotation * wheelTrack ) / 2 + x;
  float speed_wish_left = x * 2 - speed_wish_right;

  SetSpeedLeft(speed_wish_left);
  SetSpeedRight(speed_wish_right);

  //    Serial2.print("x");Serial2.println(x);
  //    Serial2.print("speed_wish_right");Serial2.println(speed_wish_right);
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", cmd_vel_cb);

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);
  Serial2.println("Starting init...");

  //  IMUInit();
  Serial2.println("IMU initialized");
  oldMillis = millis();

  EncoderInit();
  Serial2.println("Encoder initialized");

  DriverInit();

  nh.initNode();
  nh.advertise(tickMsg);
  nh.subscribe(cmd_vel);
  Serial2.println("Advertising Topics");

  delay(500);
  RSTtime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - oldMillis >= 100) {
    //    readData();
    oldMillis = millis();
    nh.spinOnce();
  }
  //  delay(1000);
}

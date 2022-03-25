#include <Wire.h>
#include <MPU6050.h>
#include "TimerOne.h"
#include "DualVNH5019MotorShield.h"
#include <PID.h>


#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle  nh;
std_msgs::String str_msg;
ros::Publisher ArduinoData("Sensors", &str_msg);


float VLeft = 0;
float VRight = 0;

const int default_vel = 100;
float aX = 0, aY = 0, aZ = 0, gX = 0, gY = 0, gZ = 0;

int oldMillis = 0;

void cmd_vel_cb(const geometry_msgs::Twist & msg) {
  // Read the message. Act accordingly.
  // We only care about the linear x, and the rotational z.
  const float x = msg.linear.x;
  const float z_rotation = msg.angular.z;
  int right_cmd = x*default_vel * min(1, max(z_rotation*1.5 + 1, -1));
  int left_cmd =  x*default_vel * min(1, max(-z_rotation*1.5 + 1 , -1));

  SetSpeedLeft(left_cmd);
  SetSpeedRight(right_cmd);

}


ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", cmd_vel_cb);

void setup() {
  Serial.begin(115200);
  Serial.println("Starting init...");

  IMUInit();
  Serial.println("IMU initialized");
  oldMillis = millis();

  EncoderInit();
  Serial.println("Encoder initialized");

  nh.initNode();
  nh.advertise(ArduinoData);
  Serial.println("Advertising Topics");
  
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - oldMillis >= 100) {
    readData();

    //    Serial.print("VLeft "); Serial.print(VLeft); Serial.print("\t");
    //    Serial.print("VRight "); Serial.print(VRight); Serial.print("\t");
    //    Serial.print("aX "); Serial.print(aX); Serial.print("\t");
    //    Serial.print("aY "); Serial.print(aY); Serial.print("\t");
    //    Serial.print("aZ "); Serial.print(aZ); Serial.print("\t");
    //
    //    Serial.print("gX "); Serial.print(gX); Serial.print("\t");
    //    Serial.print("gY "); Serial.print(gY); Serial.print("\t");
    //    Serial.print("gZ "); Serial.print(gZ); Serial.print("\t\n");
    String msg = "VL" + String(VLeft, 3) + "VR" + String(VRight, 3) + "aX" + String(aX, 3) + "aY" + String(aY, 3) + "aZ" + String(aZ, 3) + "gX" + String(gX, 3) + "gY" + String(gY, 3) + "gZ" + String(gZ, 3);

    int str_len = msg.length() + 1;
    char char_array[str_len];
    msg.toCharArray(char_array, str_len);
    str_msg.data = char_array;
//    Serial.println(msg);
    oldMillis = millis();
    ArduinoData.publish( &str_msg );
    nh.spinOnce();
  }
  //  delay(1000);
}

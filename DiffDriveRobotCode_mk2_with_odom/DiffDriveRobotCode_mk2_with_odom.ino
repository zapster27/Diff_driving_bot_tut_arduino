#include <Wire.h>
#include <MPU6050.h>
#include "TimerOne.h"
#include "DualVNH5019MotorShield.h"
#include <PID.h>


#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float32MultiArray.h>

ros::NodeHandle  nh;
std_msgs::Float32MultiArray  state_msg;
std_msgs::MultiArrayDimension myDim;

ros::Publisher StateMsg("StateMsg", &state_msg);


float X = 0;
float Y = 0;
float Theta = 0;

float VX = 0;
float VY = 0;
float W = 0;
double DT = 0;


double RSTtime = 0;
const int default_vel = 100;
float aX = 0, aY = 0, aZ = 0, gX = 0, gY = 0, gZ = 0;

int oldMillis = 0;

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

char label[] =  "test";
int array_size = 6;
void initRosPub() {
  myDim.label = label;
  myDim.size = array_size;
  myDim.stride = 1 * array_size;
  state_msg.layout.data_offset = 0;
  state_msg.layout.dim[0] = myDim;
  state_msg.data_length = array_size;
  state_msg.data = (float *)malloc(sizeof(float) * array_size);
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", cmd_vel_cb);

void setup() {
  Serial.begin(115200);
  Serial.println("Starting init...");

//  IMUInit();
  Serial.println("IMU initialized");
  oldMillis = millis();

  EncoderInit();
  Serial.println("Encoder initialized");
  initRosPub();
  nh.initNode();
  nh.advertise(ArduinoData);
  nh.advertise(StateMsg);
  Serial.println("Advertising Topics");

  delay(500);
  RSTtime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - oldMillis >= 100) {
//    readData();


    //    int str_len = msg.length() + 1;
    //    char char_array[str_len];
    //    msg.toCharArray(char_array, str_len);
    //    str_msg.data = char_array;
    //    Serial.println(msg);
    
    state_msg.data[0] = X;
    state_msg.data[1] = Y;
    state_msg.data[2] = Theta;
    state_msg.data[3] = VX;
    state_msg.data[4] = W;
    state_msg.data[5] = W;
    StateMsg.publish( &state_msg );

    oldMillis = millis();
    nh.spinOnce();
  }
  //  delay(1000);
}

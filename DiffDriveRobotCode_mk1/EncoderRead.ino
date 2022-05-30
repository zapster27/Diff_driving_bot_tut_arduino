#define RH_ENCODER_A 3
#define RH_ENCODER_B 24
#define LH_ENCODER_A 19
#define LH_ENCODER_B 22

extern double VLeft;
extern double VRight;

extern double RSTtime;

extern double tickLeft = 0;
extern double tickRight = 0;

volatile int leftCount = 0;
volatile int rightCount = 0;

double timeInterval = 100000;

int wheelDiameter = 80;
extern int wheelTrack;
int CPR = 494;
//float rotaryDistance = 2 * 3.14 * wheelDiameter / 2;
double deltaT = 0;

void EncoderInit() {

  pinMode(LH_ENCODER_A, INPUT);
  pinMode(LH_ENCODER_B, INPUT);
  pinMode(RH_ENCODER_A, INPUT);
  pinMode(RH_ENCODER_B, INPUT);


  attachInterrupt(digitalPinToInterrupt(RH_ENCODER_A), rightEncoderEvent, RISING);
  attachInterrupt(digitalPinToInterrupt(LH_ENCODER_A), leftEncoderEvent, RISING);

  Timer1.initialize(timeInterval);
  Timer1.attachInterrupt( Timer_Isr );
}

// encoder event for the interrupt callS
void leftEncoderEvent() {
  if (digitalRead(LH_ENCODER_B) > 0) {
    leftCount--;
  } else {
    leftCount++;
  }
  //  Serial2.print("leftCount   "); Serial2.print(leftCount);
  //  Serial2.print("    rightCount   "); Serial2.println(rightCount);
}

void rightEncoderEvent() {
  if (digitalRead(RH_ENCODER_B) > 0) {
    rightCount++;
  } else {
    rightCount--;
  }
  //  Serial2.print("leftCount   "); Serial2.print(leftCount);
  //  Serial2.print("    rightCount   "); Serial2.println(rightCount);
}

void Timer_Isr() {
  Timer1.detachInterrupt();           // Disable the timer
  deltaT = millis() - RSTtime;

  float DLeft = 2 * PI * (wheelDiameter * 0.5) * leftCount / (CPR * 1000);
  float DRight = 2 * PI * (wheelDiameter * 0.5) * rightCount / (CPR * 1000);

  VLeft = DLeft * 1000 / deltaT;
  VRight = DRight * 1000 / deltaT;

  String msg = String(leftCount)+","+String(rightCount)+","+String(deltaT)"\n";
  int str_len = msg.length() + 1;
  char char_array[str_len];
  msg.toCharArray(char_array, str_len);
  tick_msg.data = char_array;
  Serial.println(msg);
  tick_msg.publish( &tick_msg );

  rightCount = 0;
  leftCount = 0;
  RSTtime = millis();

  //  Serial2.print("leftCount   "); Serial2.print(leftCount);
  //  Serial2.print("    rightCount   "); Serial2.println(rightCount);

  //  Serial2.print("DLeft   "); Serial2.print(DLeft);
  //  Serial2.print("    DRight   "); Serial2.println(DRight);

  //  Serial2.print("VLeft   "); Serial2.print(VLeft);
  //  Serial2.print("    VRight   "); Serial2.println(VRight);
  //  Serial2.println();

  Timer1.attachInterrupt( Timer_Isr ); // Re-enable the timer
}

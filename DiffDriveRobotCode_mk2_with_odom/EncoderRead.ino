#define RH_ENCODER_A 2
#define RH_ENCODER_B 3
#define LH_ENCODER_A 18
#define LH_ENCODER_B 19

float VLeft;
float VRight;

extern float X;
extern float Y;
extern float Theta;

extern float QX;
extern float QY;
extern float QZ;
extern float QW;

extern float VX;
extern float W;
extern double DT;

extern double RSTtime;

volatile long leftCount = 0;
volatile long rightCount = 0;

double timeInterval = 100000;

int wheelDiameter = 80;
extern int wheelTrack;
int CPR = 494;
//float rotaryDistance = 2 * 3.14 * wheelDiameter / 2;

float RPSLeft = 0;
float RPSRight = 0;
double deltaT = 0;

double dX = 0;
double dY = 0;
double dtheta = 0;

void EncoderInit() {

  pinMode(LH_ENCODER_A, INPUT);
  pinMode(LH_ENCODER_B, INPUT);
  pinMode(RH_ENCODER_A, INPUT);
  pinMode(RH_ENCODER_B, INPUT);


  attachInterrupt(digitalPinToInterrupt(LH_ENCODER_A), leftEncoderEvent, RISING);
  attachInterrupt(digitalPinToInterrupt(RH_ENCODER_A), rightEncoderEvent, RISING);

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
}

void rightEncoderEvent() {
  if (digitalRead(RH_ENCODER_B) > 0) {
      rightCount++;
    } else {
      rightCount--;
  }
}

void Timer_Isr() {
  Timer1.detachInterrupt();           // Disable the timer
  deltaT = millis() - RSTtime;


  float DLeft = 2 * PI * (wheelDiameter * 0.5) * leftCount / (CPR * 1000);
  float DRight = 2 * PI * (wheelDiameter * 0.5) * rightCount / (CPR * 1000);
  float DCenter = (DRight + DLeft) / 2;

  VLeft = DLeft / deltaT;
  VRight = DRight / deltaT;

  dtheta = (DRight - DLeft) / wheelTrack;

  if (DLeft == DRight) {
    dX = DRight * cos(Theta);
    dY = DRight * sin(Theta);
  }
  else {
    double radius = DCenter / dtheta;

    double iccX = X - radius * sin(Theta);
    double iccY = Y + radius * cos(Theta);

    dX = radius * sin(dtheta + Theta) + iccX - X;
    dY = iccY - radius * cos(dtheta + Theta) - Y;
  }

  X += dX;
  Y += dY;
  Theta = (Theta + dtheta) ;

  while (Theta >= 2 * PI) {
    Theta -= 2 * PI;
  }

  VX = dX / deltaT;
  W = dtheta / deltaT;

  QW = cos(abs(Theta) / 2.0f);
  QX = 0.0f;
  QY = 0.0f;
  QZ = sign(Theta) * sin(abs(Theta) / 2.0f);

  DT = deltaT;
  //  Serial.println(VRight);
  rightCount = 0;
  leftCount = 0;
  dtheta = 0;
  deltaT = millis();
  Timer1.attachInterrupt( Timer_Isr ); // Re-enable the timer
}

MPU6050 mpu;
extern float aX, aY, aZ, gX, gY, gZ;
float aXStart, aYStart, aZStart, gXStart, gYStart, gZStart;

Vector normAccel;
Vector normGyro;

void IMUInit() {
  Serial2.println("Initialize MPU6050");

  while (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)) {
    Serial2.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
  while (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)) {
    Serial2.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }


  // If you want, you can set accelerometer offsets
  // mpu.setAccelOffsetX();
  // mpu.setAccelOffsetY();
  // mpu.setAccelOffsetZ();

  mpu.setThreshold(3);
  mpu.calibrateGyro();

  checkSettings();

  for (int i = 0; i < 50; i++) {
    Vector normAccel = mpu.readNormalizeAccel();
    Vector normGyro = mpu.readNormalizeGyro();

    aXStart += normAccel.XAxis;
    aYStart += normAccel.YAxis;

    gXStart += normGyro.XAxis;
    gYStart += normGyro.YAxis;
    gZStart += normGyro.ZAxis;
  }

  aXStart /= 50;
  aYStart /= 50;

  gXStart /= 50;
  gYStart /= 50;
  gZStart /= 50;
}


void checkSettings() {
  Serial2.println();

  Serial2.print(" * Sleep Mode:            ");
  Serial2.println(mpu.getSleepEnabled() ? "Enabled" : "Disabled");

  Serial2.print(" * Clock Source:          ");
  switch (mpu.getClockSource()) {
    case MPU6050_CLOCK_KEEP_RESET:     Serial2.println("Stops the clock and keeps the timing generator in reset"); break;
    case MPU6050_CLOCK_EXTERNAL_19MHZ: Serial2.println("PLL with external 19.2MHz reference"); break;
    case MPU6050_CLOCK_EXTERNAL_32KHZ: Serial2.println("PLL with external 32.768kHz reference"); break;
    case MPU6050_CLOCK_PLL_ZGYRO:      Serial2.println("PLL with Z axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_YGYRO:      Serial2.println("PLL with Y axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_XGYRO:      Serial2.println("PLL with X axis gyroscope reference"); break;
    case MPU6050_CLOCK_INTERNAL_8MHZ:  Serial2.println("Internal 8MHz oscillator"); break;
  }

  Serial2.print(" * Accelerometer:         ");
  switch (mpu.getRange()) {
    case MPU6050_RANGE_16G:            Serial2.println("+/- 16 g"); break;
    case MPU6050_RANGE_8G:             Serial2.println("+/- 8 g"); break;
    case MPU6050_RANGE_4G:             Serial2.println("+/- 4 g"); break;
    case MPU6050_RANGE_2G:             Serial2.println("+/- 2 g"); break;
  }

  Serial2.print(" * Gyroscope:         ");
  switch (mpu.getScale()) {
    case MPU6050_SCALE_2000DPS:        Serial2.println("2000 dps"); break;
    case MPU6050_SCALE_1000DPS:        Serial2.println("1000 dps"); break;
    case MPU6050_SCALE_500DPS:         Serial2.println("500 dps"); break;
    case MPU6050_SCALE_250DPS:         Serial2.println("250 dps"); break;
  }

  Serial2.print(" * Accelerometer offsets: ");
  Serial2.print(mpu.getAccelOffsetX());
  Serial2.print(" / ");
  Serial2.print(mpu.getAccelOffsetY());
  Serial2.print(" / ");
  Serial2.println(mpu.getAccelOffsetZ());

  Serial2.print(" * Gyroscope offsets: ");
  Serial2.print(mpu.getGyroOffsetX());
  Serial2.print(" / ");
  Serial2.print(mpu.getGyroOffsetY());
  Serial2.print(" / ");
  Serial2.println(mpu.getGyroOffsetZ());


  Serial2.println();
}


void readData() {

  Vector normAccel = mpu.readNormalizeAccel();
  Vector normGyro = mpu.readNormalizeGyro();


  aX = normAccel.XAxis - aXStart;
  aY = normAccel.YAxis - aYStart;
  aZ = normAccel.ZAxis - aZStart;

  gX = normGyro.XAxis - gXStart;
  gY = normGyro.YAxis - gYStart;
  gZ = normGyro.ZAxis - gZStart;
}

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

// Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }

  Serial.println("");
  delay(100);
}

void loop() {

  float ax, ay, az;
  float denomX_A, denomX_B, denomX_C, denomX_T;
  float denomY_A, denomY_B, denomY_C, denomY_T;
  float denomZ_A, denomZ_B, denomZ_C, denomZ_T;
  float angleX, angleY, angleZ;
/* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  ax = (a.acceleration.x/9.80665);
  ay = (a.acceleration.y/9.80665);
  az = (a.acceleration.z/9.80665);

//X-EIXO
  denomX_A = pow(ay, 2);
  denomX_B = pow(az, 2);
  denomX_C = denomX_A + denomX_B;
  denomX_T = pow(denomX_C, .5);                   //pow returns base raised to the power exponent
  angleX = atan(ax/denomX_T) * 180/PI;           //should calculate the angle on the X axis in
                                                  //degrees based on raw data
                                
  //Y-EIXO
  denomY_A = pow(ax, 2);
  denomY_B = pow(az, 2);
  denomY_C = denomY_A + denomY_B;
  denomY_T = pow(denomY_C, .5);                   //pow returns base raised to the power exponent
  angleY = atan(ay/denomY_T)* 180/PI;           //should calculate the angle on the Y axis in degrees based
                                                 // on raw data                       
 
  //Z-EIXO
  denomZ_A = pow(ax, 2);
  denomZ_B = pow(ay, 2);
  denomZ_C = denomZ_A + denomZ_B;
  denomZ_T = pow(denomZ_C, .5);                   
  angleZ = atan(az/denomY_T)* 180/PI; 
  
  Serial.print("Angulo em graus: X: ");
  Serial.print(angleX);
  Serial.print(" \t Y: ");
  Serial.print(angleY);
  Serial.print(" \t Z: ");
  Serial.print(angleZ);
  Serial.print("\r\n"  );       


  Serial.println("");
  delay(500);
}

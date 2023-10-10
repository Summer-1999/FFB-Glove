// Require libraries: Adafruit MPU6050, Adafruit Unified Sensor
#if USING_IMU
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <SensorFusion.h>
#include <Wire.h>

SF fusion;
Adafruit_MPU6050 mpu;
float deltat;
float gx, gy, gz, ax, ay, az;

void setupIMU() {
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G); // Accelerometer range set to +-8G
  mpu.setGyroRange(MPU6050_RANGE_500_DEG); // Gyro range set to +-500deg/s
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ); // Filter bandwidth set to 21Hz
}

float* getIMU() {

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  static float IMUdata[3] = {0, 0, 0}; //{yaw, pitch, roll}

  ax = a.acceleration.x;
  ay = a.acceleration.y;
  az = a.acceleration.z;
  gx = g.gyro.x;
  gy = g.gyro.y;
  gz = g.gyro.z;

  deltat = fusion.deltatUpdate();
  fusion.MahonyUpdate(gx, gy, gz, ax, ay, az, 0, 0, 0, deltat);

  IMUdata[0] = fusion.getYaw();
  IMUdata[1] = fusion.getPitch();
  IMUdata[2] = fusion.getRoll();

  return IMUdata;
}
#endif

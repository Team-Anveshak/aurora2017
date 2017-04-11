#include<ros.h>
#include <sensor_msgs/Imu.h>
#include<Arduino.h>
#include "I2Cdev.h"

#include "MPU6050_6Axis_MotionApps20.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

ros::NodeHandle nh;
sensor_msgs::Imu values;
ros::Publisher Imu("imu/data",&values);
  

MPU6050 mpu;



//#define OUTPUT_TEAPOT



#define INTERRUPT_PIN 2  
#define LED_PIN 13 

int16_t ax, ay, az;
int16_t gx, gy, gz;
bool blinkState = false;

// MPU control/status vars
bool dmpReady = false;  
uint8_t mpuIntStatus;   
uint8_t devStatus;     
uint16_t packetSize;   
uint16_t fifoCount;     
uint8_t fifoBuffer[64]; 

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector




volatile bool mpuInterrupt = false;    
void dmpDataReady() {
    mpuInterrupt = true;
}





void setup() {
    
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        Wire.setClock(400000); 
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
   //Serial.begin(115200);
    nh.initNode();
    nh.advertise(Imu);
  

    

    
   
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);

  
   

   
   
   
    
    devStatus = mpu.dmpInitialize();

    // gyro offsets here, scaled for min sensitivity
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788); 

    // make sure it worked (returns 0 if so)
    if (devStatus == 0) {
        
       
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        
        
        dmpReady = true;

        
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        
  
    }
    pinMode(LED_PIN, OUTPUT);
}




void loop() {
   
    if (!dmpReady) return;

    
    while (!mpuInterrupt && fifoCount < packetSize) {
        
    }

   
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();

   
    fifoCount = mpu.getFIFOCount();

   
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        
        mpu.resetFIFO();
        

    } else if (mpuIntStatus & 0x02) {
        
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

       
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        
        
        fifoCount -= packetSize;

       
            mpu.dmpGetQuaternion(&q, fifoBuffer);
           
            
    
    
            values.orientation.x = q.x;
            values.orientation.y = q.y;
            values.orientation.z = q.z;
            values.orientation.w = q.w;
            for(int i=0;i<9;i++)
            {values.orientation_covariance[i] = 0.0 ;}
            //values.orientation_covariance = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
            
        
             mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
        
            values.angular_velocity.x = gx;
            values.angular_velocity.y = gy;
            values.angular_velocity.z = gz;
             for(int i=0;i<9;i++)
            {values.angular_velocity_covariance[i] = 0.0 ;}
           // values.angular_velocity_covariance = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}; 
            /*Serial.print("ypr\t");
            Serial.print(ypr[0] * 180/M_PI);
            Serial.print("\t");
            Serial.print(ypr[1] * 180/M_PI);
            Serial.print("\t");
            Serial.println(ypr[2] * 180/M_PI);*/
       

  
      
            


            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetAccel(&aa, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
            mpu.dmpGetLinearAccelInWorld(&aaWorld, &aaReal, &q);
            values.linear_acceleration.x = aaWorld.x;
            values.linear_acceleration.y = aaWorld.y;
            values.linear_acceleration.z = aaWorld.z;
            for(int i=0;i<9;i++)
            {values.linear_acceleration_covariance[i] = 0.0 ;}
            
       

    
        
        // blink LED to indicate activity
        blinkState = !blinkState;
        digitalWrite(LED_PIN, blinkState);
        Imu.publish(&values);
        nh.spinOnce();;
       
    }
}

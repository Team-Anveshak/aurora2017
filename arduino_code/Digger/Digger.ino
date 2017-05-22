66666666#include<ros.h>
#include<rover_msgs/digger.h>


#include <rover_msgs/SC_task.h>

#include <OneWire.h>
#include <SFE_BMP180.h>
#include <Wire.h>

#define hum A2



int HighByte, LowByte, TReading, SignBit, Tc_100, Whole, Fract;
// DS18S20 Temperature chip i/o
OneWire ds(24);  // on pin 10

// You will need to create an SFE_BMP180 object, here called "pressure":
SFE_BMP180 pressure;
int pressure_init=1;
#define ALTITUDE 1655.0 // Altitude of SparkFun's HQ in Boulder, CO. in meters

#define Step_UD1_dir 45
#define Step_UD1_step 13
#define Step_UD2_dir 41
#define Step_UD2_step 12
#define Step_LR_dir 37
#define Step_LR_step 11
#define Step_probe_dir 33
#define Step_probe_step 10
#define n 3000
#define enable_ver_1 39
#define enable_ver_2 43
#define enable_hor 35
#define enable_probe 31
#define ena_1 46
#define ena_2 44
#define fdir1 50
#define fdir2 42
#define bdir1 48
#define bdir2 40



int delay1=2000,delay2=2000,delay3=2000;
int motorPin = 3; //check pin number
int x = 0, i = 1;
int sensor_key;




void CallBack(const rover_msgs::digger& D)
{
  
    
       
  if((D.Step_UD_step)==1 )
  {
    
    if((D.Step_UD_dir)==1)
    {
      digitalWrite(Step_UD1_dir, HIGH);
      digitalWrite(Step_UD2_dir, HIGH);
    }
    if((D.Step_UD_dir)==-1)
    {
      digitalWrite(Step_UD1_dir, LOW);
      digitalWrite(Step_UD2_dir, LOW);  
    }
    
    digitalWrite(enable_ver_1, LOW);
    digitalWrite(enable_ver_2, LOW);
    
   for(int i=0;i<50;i++)
    {
      digitalWrite(Step_UD1_step, HIGH);
      digitalWrite(Step_UD2_step, HIGH);
      delayMicroseconds(delay1);
      digitalWrite(Step_UD1_step, LOW);
      digitalWrite(Step_UD2_step, LOW);
      delayMicroseconds(delay1);

    }
   
   }
      
  if((D.LR_step)==1)
   {
    if((D.LR_dir)==1)
    {
      digitalWrite(Step_LR_dir, HIGH);
    }
    if((D.LR_dir)==-1)
    {
      digitalWrite(Step_LR_dir, LOW);
    }
  
    
    digitalWrite(enable_hor, LOW);
    for(int i=0;i<50;i++)
    {
      digitalWrite(Step_LR_step,HIGH);
      delayMicroseconds(delay3);
      digitalWrite(Step_LR_step,LOW);
      delayMicroseconds(delay3);
     
    }
    
    }
    
    if((D.probe_step)==1)
   {
    if((D.probe_dir)==1)
    {
      digitalWrite(Step_probe_dir, HIGH);
    }
    if((D.probe_dir)==-1)
    {
      digitalWrite(Step_probe_dir, LOW);
    }
  
    
    digitalWrite(enable_hor, LOW);
    for(int i=0;i<50;i++)
    {
      digitalWrite(Step_probe_step,HIGH);
      delayMicroseconds(delay3);
      digitalWrite(Step_probe_step,LOW);
      delayMicroseconds(delay3);
     
    }
    
    }
    
    if(D.drill==1)
    {
      
      digitalWrite(bdir1,HIGH);
    }
    else
    {
      digitalWrite(bdir1,LOW);
    }
    
    sensor_key=D.sensor_flag;
}

ros::NodeHandle nh;

rover_msgs::SC_task sensor_msg;
ros::Publisher sensor_pub("SC_Task_Sensors", &sensor_msg);

ros::Subscriber<rover_msgs::digger> sub("dig", &CallBack);


void setup() {
  nh.initNode();
  nh.subscribe(sub);
  
  pinMode(hum, INPUT);  //Soil moisture sensor. Humidity in percentage
  
  // Initialize the sensor (it is important to get calibration values stored on the device).
  if (pressure.begin())
    pressure_init=1;
  else
  {
    // Oops, something went wrong, this is usually a connection problem,
    //Serial.println("BMP180 init fail\n\n");
   pressure_init=0;
  }
  nh.advertise(sensor_pub);
  

  pinMode(motorPin, OUTPUT); //dc motor
  
  pinMode(Step_UD1_dir, OUTPUT);
  pinMode(Step_UD1_step, OUTPUT);
  pinMode(Step_UD2_dir, OUTPUT);
  pinMode(Step_UD2_step, OUTPUT);
  pinMode(Step_LR_dir, OUTPUT);
  pinMode(Step_LR_step, OUTPUT);
  pinMode(Step_probe_dir, OUTPUT);
  pinMode(Step_probe_step, OUTPUT);
  pinMode(enable_ver_1,OUTPUT);
  pinMode(enable_ver_2,OUTPUT);
  pinMode(enable_hor,OUTPUT);
  pinMode(enable_probe,OUTPUT);
  pinMode(ena_1,OUTPUT);
  pinMode(ena_2,OUTPUT);
  pinMode(fdir1,OUTPUT);
  pinMode(fdir2,OUTPUT);
  pinMode(bdir1,OUTPUT);
  pinMode(bdir2,OUTPUT);
  
  delay(10);
 
}


void loop() 
{
  
  
 sensor_msg.T=temp();
//Serial.print("Temperature :");
//Serial.println(T);
 //get pressure data
 sensor_msg.P=pressure_measure();
//Serial.print("Pressure:");
//Serial.println(P);
 //get humidity data
 sensor_msg.H=humidity();
 //Serial.print("Humidity :");
//Serial.println(H);
 
 //publish
 if (sensor_key==1)
 {
 sensor_pub.publish( &sensor_msg );
 }
  nh.spinOnce();
  delay(1);
}
float temp()
{
  byte i;
  byte present;
  byte data[12];
  byte addr[8];

  ds.reset_search();
  if ( !ds.search(addr)) {
      //Serial.print("No more addresses.\n");
      ds.reset_search();
      return(-1);
  }
  if ( OneWire::crc8( addr, 7) != addr[7]) {
      //Serial.print("CRC is not valid!\n");
      return(-1);
  }
  ds.reset();
  ds.select(addr);
  ds.write(0x44,1);         // start conversion, with parasite power on at the end

  delay(1000);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.

  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);         // Read Scratchpad
  
  for ( i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds.read();
    //Serial.println(data[i], HEX);
  }
  LowByte = data[0];
  HighByte = data[1];
  TReading = (HighByte << 8) + LowByte;
  SignBit = TReading & 0x8000;  // test most sig bit
  if (SignBit) // negative
  {
    TReading = (TReading ^ 0xffff) + 1; // 2's comp
  }
  Tc_100 = (6 * TReading) + TReading / 4;    // multiply by (100 * 0.0625) or 6.25
  if (SignBit) // If its negative
  {
     Tc_100*=-1;
  }
/*  Whole = Tc_100 / 100;  // separate off the whole and fractional portions
  Fract = Tc_100 % 100;
  if (SignBit) // If its negative
  {
     Serial.print("-");
  }
  Serial.print(Whole);
  Serial.print(".");
  if (Fract < 10)
  {
     Serial.print("0");
  }
  Serial.print(Fract);
  Serial.print("\n");
  */
  return(Tc_100);
}

float pressure_measure()
{
  char status;
  double T,P,p0,a;

  // Loop here getting pressure readings every 10 seconds.

  // If you want sea-level-compensated pressure, as used in weather reports,
  // you will need to know the altitude at which your measurements are taken.
  // We're using a constant called ALTITUDE in this sketch:
  
  /*Serial.println();
  Serial.print("provided altitude: ");
  Serial.print(ALTITUDE,0);
  Serial.print(" meters, ");
  Serial.print(ALTITUDE*3.28084,0);
  Serial.println(" feet");*/
  
  // If you want to measure altitude, and not pressure, you will instead need
  // to provide a known baseline pressure. This is shown at the end of the sketch.

  // You must first get a temperature measurement to perform a pressure reading.
  
  // Start a temperature measurement:
  // If request is successful, the number of ms to wait is returned.
  // If request is unsuccessful, 0 is returned.

  status = pressure.startTemperature();
  if (status != 0)
  {
    // Wait for the measurement to complete:
    delay(status);

    // Retrieve the completed temperature measurement:
    // Note that the measurement is stored in the variable T.
    // Function returns 1 if successful, 0 if failure.

    status = pressure.getTemperature(T);
    if (status != 0)
    {
      // Print out the measurement:
      /*Serial.print("temperature: ");
      Serial.print(T,2);
      Serial.print(" deg C, ");
      Serial.print((9.0/5.0)*T+32.0,2);
      Serial.println(" deg F");*/
      
      // Start a pressure measurement:
      // The parameter is the oversampling setting, from 0 to 3 (highest res, longest wait).
      // If request is successful, the number of ms to wait is returned.
      // If request is unsuccessful, 0 is returned.

      status = pressure.startPressure(3);
      if (status != 0)
      {
        // Wait for the measurement to complete:
        delay(status);

        // Retrieve the completed pressure measurement:
        // Note that the measurement is stored in the variable P.
        // Note also that the function requires the previous temperature measurement (T).
        // (If temperature is stable, you can do one temperature measurement for a number of pressure measurements.)
        // Function returns 1 if successful, 0 if failure.

        status = pressure.getPressure(P,T);
        if (status != 0)
        {
          // Print out the measurement:
          /*Serial.print("absolute pressure: ");
          Serial.print(P,2);
          Serial.print(" mb, ");
          Serial.print(P*0.0295333727,2);
          Serial.println(" inHg");*/

          // The pressure sensor returns abolute pressure, which varies with altitude.
          // To remove the effects of altitude, use the sealevel function and your current altitude.
          // This number is commonly used in weather reports.
          // Parameters: P = absolute pressure in mb, ALTITUDE = current altitude in m.
          // Result: p0 = sea-level compensated pressure in mb

          p0 = pressure.sealevel(P,ALTITUDE); // we're at 1655 meters (Boulder, CO)
          /*Serial.print("relative (sea-level) pressure: ");
          Serial.print(p0,2);
          Serial.print(" mb, ");
          Serial.print(p0*0.0295333727,2);
          Serial.println(" inHg");*/

          // On the other hand, if you want to determine your altitude from the pressure reading,
          // use the altitude function along with a baseline pressure (sea-level or other).
          // Parameters: P = absolute pressure in mb, p0 = baseline pressure in mb.
          // Result: a = altitude in m.

          a = pressure.altitude(P,p0);
         /* Serial.print("computed altitude: ");
          Serial.print(a,0);
          Serial.print(" meters, ");
          Serial.print(a*3.28084,0);
          Serial.println(" feet");*/
          return(P);
        }
        else return(-1);//Serial.println("error retrieving pressure measurement\n");
      }
      else return(-1);//Serial.println("error starting pressure measurement\n");
    }
    else return(-1);//Serial.println("error retrieving temperature measurement\n");
  }
  else return(-1);//Serial.println("error starting temperature measurement\n");
}

float humidity()
{
   int value = 1023 - analogRead(hum);
   float percentage = (float)value*(100.00/1023.00);
   return(percentage);
}

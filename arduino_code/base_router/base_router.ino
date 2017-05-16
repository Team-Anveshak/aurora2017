#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

RF24 radio(7, 8);

Servo servo_test;

const byte rxAddr[6] = "00001";


char ch;
unsigned long theta=0,phi=0,thetaprev=0,control=876,x=0,y=0,xprev=0,yprev=0,angle=0;

int c=0,pos=0;

void setup() 
{
  while (!Serial);
  
  Serial.begin(9600);
  
  radio.begin();
  radio.openReadingPipe(0, rxAddr);
  
  radio.startListening();
  delay(5000);
   
   servo_test.attach(9);
   servo_test.write(0); 
    
}


void loop()
{
  if (radio.available())
  { 
    if(c==0)
    {
      radio.read( &control, sizeof(unsigned long) );
      Serial.println(control);
      if (control == 50) {
          // Make sure not to exceed the mechanical limitation.
          if (pos < 180) {
            pos += 1;
          }
        } else if (control==49)
        {
          // Make sure not to exceed the mechanical limitation.
          if (pos > 0) {
            pos -= 1;
          }
        }
        else if(control==48)
         {c=1;} 
       

      phi=pos;
    }
    
      
    if(c==1){
    
    
      radio.read( &theta, sizeof(unsigned long) );
      delay(15);
      radio.read( &x, sizeof(unsigned long) );
      delay(15);
      radio.read( &y, sizeof(unsigned long) );
      delay(15);
      
      if((x>xprev)||(y>yprev))
    {
 for(angle = int(phi+thetaprev); angle < int(phi+theta+thetaprev); angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test.write(angle);                 //command to rotate the servo to the specified angle
     delay(5);                       
  }
 }
 if((x<xprev)||(y<yprev))
 {
 for(angle = int(phi+thetaprev); angle < int(phi-theta+thetaprev); angle -= 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test.write(angle);                 //command to rotate the servo to the specified angle
     delay(5);                       
  }
 }
      
   thetaprev=theta;
   xprev=x;
   yprev=y; 
    }
  }
 else
 {
   Serial.print("recv failed");
  }
  
  delay(10);
}


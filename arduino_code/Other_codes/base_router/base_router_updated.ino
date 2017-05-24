#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

RF24 radio(7, 8);

Servo servo_test;

const byte rxAddr[6] = "00001";

int pos=0;

char ch;
unsigned long theta=0;

void setup() 
{
  while (!Serial);
  
  Serial.begin(9600);
  
  radio.begin();
  radio.openReadingPipe(0, rxAddr);
  
  radio.startListening();
  delay(1000);
   
  servo_test.attach(9);
  servo_test.write(0); 
    
}
void loop() {
  if(radio.available()){
    radio.read(&theta,sizeof(unsigned long));
    
    Serial.print("Current angle position of servo : ");
    Serial.println(theta);
    Serial.print("\n");
    
    for (pos = 0; pos <= theta; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo_test.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 100 ms for the servo to reach the position
    }
  
  }

}

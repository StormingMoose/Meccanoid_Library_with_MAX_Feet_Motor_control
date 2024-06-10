/*
https://github.com/robotscity/meccanoid_arduino_demo/blob/master/demo_meccanoids.ino

https://github.com/MrDreamBot/MeccaChannel/tree/master

Max Feet motors

*/

#include "MeccaBrain.h"

const int chainpin1 = 19;         //   my ESP32 pin

MeccaBrain chain1(chainpin1);       // set up a chain of stuff, motors, servos ...

byte stop = 0x30;
byte wheel_instruction_byte = 0x30;   //  start stopped    you play with this down below

const int LF_Motor=0;                // position in the chain of each motor
const int RF_Motor=1; 


void GO_North(){
     chain1.wheel(LF_Motor,wheel_instruction_byte);         // what to do
     chain1.communicate();                         // do it
     Serial.println("North");                      // tell the world
}
     
     
void GO_Stop(){
     chain1.wheel(LF_Motor,stop);
     chain1.communicate();
     Serial.println("Stop");
}


void setup() {
  Serial.begin(115200);                              // your electric avenue to tell the world
  Serial.println("\n\n");

  pinMode(chainpin1, OUTPUT);                        // no LIM here
              
  for (int i = 0; i < 40; i++){                     // WAKE UP THE CHAIN!!!!
    chain1.communicate();
  }

  Serial.println("Booting Sketch...");
}



void loop(){
  for (byte i = 0xE1; i <0xE2; i++){                         // play here change the numbers between 0x00 and 0xFF   smaller on the left
  wheel_instruction_byte = i;
  for (byte j = 0x00; j < 0x04; j++){GO_North();delay(200);}   // this does it 4 times then takes a rest to let you see the differences
  GO_Stop();                                                     
  delay(100);
  }
  for (byte k = 0xE4; k <0xE5; k++){                         // play here change the numbers between 0x00 and 0xFF   smaller on the left
  wheel_instruction_byte = k;
  for (byte l = 0x00; l < 0x04; l++){GO_North();delay(200);}   // this does it 4 times then takes a rest to let you see the differences
  GO_Stop();                                                     
  delay(100);
  }
}
    

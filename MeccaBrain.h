
/*
       LEGAL NOTICE:
      Meccano™, MeccaBrain™, MeccanoTech™ and Meccanoid™ are trademarks of Meccano.  All rights reserved.     
      The information contained in this document is Proprietary to Spin Master Ltd.   
      This information should not be used in the creation and sale of any commercial product.”
*/
#ifndef MeccaBrain_h
#define MeccaBrain_h

#include "Arduino.h"

class MeccaBrain{
	public:
		MeccaBrain(int pin);
		
		byte outputByteInfo(int num);
		byte inputByteInfo();
		byte inputBytesInfo(int servoNum);
		byte checkSumByteInfo();
		byte servoPositionsInfo(int servoNum);
		char moduleTypeInfo(int num);
		byte moduleNumInfo();
		byte getLEDorder();
		byte getLEDbyte1();
		byte getLEDbyte2();	

		void setLEDColor(byte red, byte green, byte blue, byte fadetime);
		void setServoColor(int servoNum, byte color);
		void setServoPosition(int servoNum, byte pos);
		void setServotoLIM(int servoNum);
		byte getServoPosition(int servoNum);
    void wheel(int wheelNum, byte direction);            //Storming Moose 2024
		
		void communicate();		
		void sendByte(byte servoData);
		byte receiveByte();
		byte calculateCheckSum(byte Data1, byte Data2, byte Data3, byte Data4);
		
	private:
		int _pmwPin;
		int servoNumber;
		int inputCounter = 0;
		int moduleNum = 0;
		int printModNum = 0;
		int ledOrder = 0;
		int bitDelay = 417;
		int receiveArray[8];
		int servo1Positions[25];                // Storming moose 2024 added 25's to make it work
		int servo2Positions[25];
		int servo3Positions[25];
		int servo4Positions[25];
	
		
		byte inputByte;
		byte checkSum;
		byte servoPos;
		byte LEDoutputByte1 = 0x00;
		byte LEDoutputByte2 = 0x47;
		byte header = 0xFF;
		byte outputByte[4];
		byte printOutputByte[4];
		
		char moduleType[4];
		byte inputBytes[];                        // Storming Moose 2024 moved to bottom so it would compile
		
};

#endif
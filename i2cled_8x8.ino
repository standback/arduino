
#include "Wire.h"
uint16_t Num_0_9_Map[10][8]={
  {//0
    0b00011000,
    0b01100110,
    0b01100110,
    0b01100110,
    0b01100110,
    0b01100110,
    0b01100110,
    0b00011000
  },
  {//1
    0b00010000,
    0b00011000,
    0b00011100,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00111100
  },
  {//2
    0b00111000,
    0b01111100,
    0b01100100,
    0b01100000,
    0b00111000,
    0b00001100,
    0b01101100,
    0b01111100
  },
  {//3
    0b00111000,
    0b01111100,
    0b01100000,
    0b01111000,
    0b01111000,
    0b01100000,
    0b01111100,
    0b00111000
  },
  {//4
    0b00100000,
    0b00110000,
    0b00111000,
    0b00110100,
    0b01111110,
    0b00110000,
    0b00110000,
    0b01111000,
  },
  {//5
    0b00111100,
    0b00111100,
    0b00001100,
    0b00111100,
    0b01100000,
    0b01100000,
    0b01111100,
    0b00111100,
  },
  {//6
    0b00111000,
    0b01111100,
    0b00001100,
    0b00111100,
    0b01101100,
    0b01101100,
    0b01111100,
    0b00111000,
  },
  {//7
    0b01111100,
    0b01111100,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100000
  },
  {//8
    0b00111100,
    0b01100110,
    0b01100110,
    0b01111110,
    0b01111110,
    0b01100110,
    0b01100110,
    0b00111100,
  },
  {//9
    0b01111110,
    0b01111110,
    0b01100110,
    0b01111110,
    0b01111110,
    0b01100000,
    0b01111110,
    0b01111110,
  }
}; 
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  
  
  Wire.beginTransmission(0x70);
  Wire.write(0x21);
  Wire.endTransmission();
  
   Wire.beginTransmission(0x70);
  Wire.write(0x80 | 0x01 ); 
  Wire.endTransmission();
  //clear
  Wire.beginTransmission(0x70);
  Wire.write(0x0);
  for(int i=0; i< 8; i++)
  {
  
 Wire.write(0); 
 Wire.write(0); 
  }
  Wire.endTransmission();
  
}

void loop() {
  // put your main code here, to run repeatedly:

 
 
  for(int i=0;i<10;i++)
  {Wire.beginTransmission(0x70);
    Wire.write(0x0);
    for(int j=0;j<8;j++)
    {
      Wire.write(Num_0_9_Map[i][j] & 0xFF);
      Wire.write(0);
    }
    
  Wire.endTransmission();
    delay(1000);
  } 
}

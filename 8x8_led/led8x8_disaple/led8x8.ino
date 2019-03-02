#include "Wire.h"
void clear()
{
  
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
void display(int addr, int red, int green)
{
  
  Wire.beginTransmission(0x70);
      Wire.write(addr);
      Wire.write(red);
      Wire.write(green);
  Wire.endTransmission();
}
int row =0;
int intel=0;
void display(int round)
{
    if (round ==0){
      Wire.write(0xff);
      Wire.write(0x00);
    }
     if (round ==1){
      Wire.write(0x00);
      Wire.write(0xff);
    } 
     if (round ==2){
      Wire.write(0xff);
      Wire.write(0xff);
    } 
}
void blink_show(int second)
{
  
  Wire.beginTransmission(0x70);
     
  Wire.write(0x83);
  Wire.endTransmission();
  delay(second*1000);
  Wire.beginTransmission(0x70);
     
  Wire.write(0x81);
  Wire.endTransmission();
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(0x70);
  Wire.write(0x81);
  Wire.write(0x21);
  Wire.endTransmission();
  clear();
}
void loop() {
  // put your main code here, to run repeatedly:

  Serial.print(row);
  Serial.print("--");
  Serial.println(intel);
  Wire.beginTransmission(0x70);
  Wire.write(row);
  display(intel);
     
  Wire.endTransmission();
    delay(1000);
  row+=2;
  if (row>15){
     row=0;
         
    intel ++;
    if (intel>2)
        intel=0;
     blink_show(3);
    clear();
  }
}

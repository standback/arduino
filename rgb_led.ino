#define  rPin  9
#define  gPin  10
#define  bPin  11
void setup() {
  // put your setup code here, to run once:
  pinMode(rPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(bPin,OUTPUT);
  ser
}

void loop() {
  // put your main code here, to run repeatedly:
  int r,g,b;
  for(r=0; r<255; r+=5);
    {for(g=0; g<255; g+=5)
      {for(b=0; b<255; b+=5)
      {
        setColor(r,g,b);
        delay(100);
      }
      }
    }
}
void setColor(int r, int g, int b)
{
  analogWrite(rPin,255-r);
  analogWrite(gPin, 255-g);
  analogWrite(bPin, 255-b);
}

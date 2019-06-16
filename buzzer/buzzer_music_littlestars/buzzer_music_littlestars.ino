
unsigned int list[] = {261,293,329,349,392,440,494};
unsigned int stars[] = {1,1,5,5,6,6,5,5,4,4,3,3,
                        2,2,1,1,5,5,4,4,3,3,2,2,
                        5,5,4,4,3,3,2,2,1,1,5,5,
                        6,6,5,5,4,4,3,3,2,2,1,1};
int i = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(i);
 
  tone(8,list[stars[i]-1]);
  
  delay(450);
  if (i%8 != 6)
    noTone(8);
  delay(50);
  i++;
  if (i == 48) i =0;
}

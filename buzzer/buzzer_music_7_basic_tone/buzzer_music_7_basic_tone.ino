
unsigned int tone_high[] = {261,293,329,349,392,440,494};
unsigned int tone_std[] = {261,293,329,349,392,440,494};
unsigned int tone_low[] = {261,293,329,349,392,440,494};
int i = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(i);
 
  tone(8,tone_std[i]);
  i++;
  if (i ==7) i =0;
  delay(1000);
}

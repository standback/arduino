#include "someonelikeyou.h"
struct song *song =0;
void setup()
{
  Serial.begin(9600);
  song = init_song_someonelikeyou();
}

void loop()
{
 play(song);
  //dump_song(song);
}

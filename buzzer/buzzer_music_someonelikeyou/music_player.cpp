#include "Arduino.h"
#include "music_player.h"
void dump_song(struct song* song)
{
  struct tone *mtone = song->tones;
  Serial.println(song->length);
  while (mtone) {
    Serial.println(mtone->value);
    delay(500);
    mtone = mtone->next;
  }
}
void play(struct song *song)
{
  struct tone * mtone = song->tones;
  while (mtone) {
    if (mtone->value == 0)
      noTone(8);
    else
      tone(8, mtone->value);
      Serial.println(mtone->value);
    delay(mtone->during);
    if (mtone->mode == TONE_MODE_SIGNEL) {
      noTone(8);
      delay(TONE_OFF_LENGTH);
    }
    if (mtone->mode == TONE_MODE_SUB_SIGNEL) {
      noTone(8);
      delay(10);
    }
    mtone = mtone->next;
  }
}
void add_tone(struct song *song, unsigned int tone_value,
             unsigned int during, unsigned int tone_mode)
{
  struct tone * tone = (struct tone *)malloc(sizeof(struct tone));

  tone->value = tone_value;
  tone->during = during;
  tone->mode = tone_mode;
  tone->next = 0;

  if (song->tones == 0)
    song->tones = song->last = tone;
  song->last->next = tone;
  song->last = tone;

  song->length++;
  Serial.println(song->length);
}


struct song * init_song(unsigned int mode)
{
  struct song * song = (struct song*)malloc(sizeof(struct song));
  memset(song, 0, sizeof(struct song));
  song->mode = mode;
  return song;
}

#ifndef __MUSIC_PLAYER_H__
#define __MUSIC_PLAYER_H__

#include "Arduino.h"
#include "tone_define.h"
#define SONG_MODE_2_4 0

struct song {
  struct tone *tones;
  struct tone *last;
  unsigned int length;
  unsigned int mode;
};

struct song * init_song(unsigned int mode);
void add_tone(struct song *song, unsigned int tone_value,
                unsigned int during, unsigned int tone_mode);
void play(struct song *song);
void dump_song(struct song *song);
#endif

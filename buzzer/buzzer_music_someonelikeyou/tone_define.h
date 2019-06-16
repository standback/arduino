#ifndef __TONE_DEFINE_H__
#define _TONE__DEFINE_H__
#include "Arduino.h"
//
#define A2
#define G2
//
#define C1
#define D1
#define E1
#define F1
#define G1
#define A1
#define G1
//
#define C
#define D
#define E
#define F
#define G
#define A
#define G
//
#define c
#define d
#define e
#define f 
#define g 196
#define a 220
#define b 247
//
#define c1 261
#define d1 293
#define e1 329
#define f1 349
#define g1 392
#define a1 440
#define b1 494
//
#define c2
#define d2
#define e2
#define f2
#define g2
#define a2
#define b2
//
#define c3
#define d3
#define e3
#define f3
#define g3
#define a3
#define b3
//
#define c4
#define d4
#define e4
#define f4
#define g4
#define a4
#define b4
//
#define c5
//
#define tone_none  0
#define TONE_MODE_SIGNEL 0
#define TONE_MODE_CONTINUE 1
#define TONE_MODE_SUB_SIGNEL 2

#define TONE_LENGTH  1000 //ms
#define TONE_OFF_LENGTH 10

#define TONE_DURING_1   TONE_LENGTH
#define TONE_DURING_1_2 TONE_LENGTH/2
#define TONE_DURING_1_4 TONE_LENGTH/4

struct tone {
  unsigned int value;
  unsigned int during;
  unsigned int mode;

  struct tone * next;
};
#endif

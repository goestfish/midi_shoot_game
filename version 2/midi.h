/* Copyright 2023 Neil Kirby, all rights reserved. */
/* Do not publish this code without written permission */
#include <stdbool.h>
/* Neil Kirby */

int midi_X(int color, double X, double Y);
void midi_beep();
void midi_clear();
void midi_flash();
int midi_getch();
int midi_initialize(int debug);
int midi_projectile(int color, double X, double Y, double direction);
void midi_refresh();
void midi_score(int score, int color);
int midi_smile(int score, int color, double X, double Y, double direction);
void midi_status(const char *statstr);
void midi_teardown();
void midi_time(int milliseconds);
bool midi_touches_wall(double X, double Y);

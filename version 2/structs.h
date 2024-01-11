
/* Copyright 2023 Neil Kirby, not for disclosure */
/* structs.h */
#include <stdbool.h>

struct Sim
{
        double elapsed, delta_T;
        int score[8];      /* per team, 2 biliion ought to suffice */
	bool bonus;

        void *smile_list; /* sort by X */
        void *shot_list;  /* sort by color */
	void *hit_list;	/* sort by hit color */
};

struct Datum
{
    double X, Y, direction;
};

struct Object
{
        int color;
	int speed;
	double desired;	/* might not be needed */
        struct Datum current;
        struct Sim *game;
};



//Bowei Kou

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "midi.h"
#include "bits.h"
#include "pi.h"
#include "sim.h"
#include "output.h"

#define DELTA_T (1.0/32.0)

//transfer degree to radians
double degreesToRadians(double degree){
	return degree*(M_PI/180.0);
}

//determine wether this position is valid
bool isValidPosition(double ball[], short unsigned code, double time){	
	if (midi_touches_wall(ball[3], ball[4])==true){
		master_wall_output(time, code, ball);

	} else{
		ball[0] = ball[3];
		ball[1] = ball[4];
	}
	return !midi_touches_wall(ball[3],ball[4]);
}


//do the simulation
void runSimulation(unsigned short code, double x, double y, double dir){
	double time = 0.0;//start time
	int sp = getSpeed(code);//speed
	double dirr = degreesToRadians(dir);//direction in radians
	double ball[6] = {x, y, dir, x, y, DELTA_T};//last two elements are new x and y
	while (isValidPosition(ball, code, time)){ 
		ball[3] = ball[0]+sp * ball[5] * sin(dirr);//new x
		ball[4] = ball[1]+sp * ball[5] * cos(dirr);//new y
		master_output(time, code, ball);
		time+=ball[5];
	}
}

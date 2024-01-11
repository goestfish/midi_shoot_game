//Bowei Kou

#include <stdbool.h>
#include <math.h>
#include "midi.h"
#include "pi.h"
#include "p_bits.h"
#include "bits.h"

#define DELTA_T (1.0/32.0)//Time for each clock

//transfer degree to radians
double degreesToRadians(double degree){
	return degree*(M_PI/180.0);
}

//determine wether this position is valid
bool isValidPosition(double x, double y){
	return !midi_touches_wall(x,y);
}

//do the simulation
void runSimulation(unsigned short code, double x, double y, double dir){
	int sp = getSpeed(code);//speed
	double dirr = degreesToRadians(dir);//direction in radians

	while (isValidPosition(x,y)){
		printf("x is %f, y is %f, direction is %f\n", x, y, dir);
		double nx = x + sp * DELTA_T * sin(dirr);//new x
		double ny = y + sp * DELTA_T * cos(dirr);//new y

		if(isValidPosition(nx, ny)){
			x=nx;
			y=ny;
		} else{
			break;
		}
	}
}

int main(){
	double degree = 57.3;
	double r = degreesToRadians(degree);
	printf("degree is %f, radians is %f\n", degree, r);
	unsigned short code = 0x4107;
	double x = 2.0, y = 20.0, dir = 120.0;
	runSimulation(code, x, y, dir);
	return 0;
}

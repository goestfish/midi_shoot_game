//Bowei Kou

#include <stdio.h>
#include <math.h>
#include "pi.h"

double toRadians(double degree){
	return degree*(M_PI/180.0);
}

int main(){
	double degree = 57.3;
	double ra = toRadians(degree);
	printf("degree is %f, radian is %f\n", degree, ra);
	return 0;
}

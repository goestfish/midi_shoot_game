//Bowei Kou

#include <stdio.h>
#include <stdbool.h>
#include "midi.h"
#include "bits.h"
#include "input.h"
#include "sim.h"
#include "output.h"

//function which will input the data and call the sim.c file
bool master_input(){
	unsigned short code;
	double x, y, dir;
	//value of scanf()
	int words = scanf("%hx %lf %lf %lf", &code, &x, &y, &dir);
	//while scanf don't have 4 variables, break the loop
	while(words == 4){
		if(isValid(code)){ 
		runSimulation(code, x, y, dir);
		}
		else return false;
		words = scanf("%hx %lf %lf %lf", &code, &x, &y, &dir);
	}
		master_scanf(words);
		return true;
}

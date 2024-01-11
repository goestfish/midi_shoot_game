#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "structs.h"
#include "output.h"
#include "bits.h"
#include "sim.h"
#include "memory.h"
#include "debug.h"
#include "callbacks.h"

#include "p_data.h"


void data(struct Object* ob, double x, double y, double direction){
        ob->current.X=x;
        ob->current.Y=y;
        ob->current.direction=direction;
}

int main(){
	struct Object* ob = malloc(sizeof(struct Object));
	unsigned short code=0x2401;
	double x = 5.5;
	double y = 8.0;
	double direction = 270.0;
	data(ob, x, y, direction);
	printf("x is %f, y is %f, direction is %f\n", ob->current.X, ob->current.Y, ob->current.direction);
	free(ob);
}

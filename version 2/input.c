// Bowei Kou

// put system shared libraries first - they are unlikely to have bugs.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// put our own header files next.
// Start with one that are #define and structs

// includes for header files based on our own C code goes here.
// Always include the header for the file itself
// THis validates the header declarations against the defninitions.
// We are spoiled by our automatically generated headers, but we still
// validate them.  We put the include for this file dead last.
#include "structs.h"
#include "output.h"
#include "bits.h"
#include "sim.h"
#include "memory.h"
#include "debug.h"
#include "callbacks.h"

#include "input.h"

//initialize the linked lists.
struct Sim* init_list(){
	struct Sim *sim=calloc(1, sizeof(struct Sim));

	sim->smile_list=NULL;
	sim->shot_list=NULL;
	sim->hit_list=NULL;
	

	return sim;
}

//assign the data to the struct's members.
void get_data(struct Sim* sim, unsigned short code, double x, double y, double direction){
	struct Object* thing = allocateOb();
	thing->color=get_color(code);
	thing->speed=get_speed(code);
	thing->current.X=x;
	thing->current.Y=y;
	thing->current.direction=direction;
	thing->game = sim;
	if(is_smile(code)){
		insert(&sim->smile_list,thing , by_color, TEXT);
		fire(thing, sim);
	} else{
		insert(&sim->shot_list, thing, by_color, TEXT);
	}
}

//master input.
bool good_input_run()
{
	int tokens;
	unsigned short code;
	double X, Y, direction;
	struct Sim* sim = init_list();

	while( 4 ==(tokens = 
		scanf("%hx %lf %lf %lf", &code, &X, &Y, &direction))
	    )
	{
	    if(valid_code(code))
	    {	
	    	get_data(sim, code, X, Y, direction);
	    }
	    else
	    {
	    	output_bad_code(code);
		return(false);
	    }

	}
	output_scanf(tokens);
	run_sim(sim);
	free(sim);
	return (tokens==EOF);

}

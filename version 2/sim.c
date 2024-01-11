//Bowei Kou

// put system shared libraries first - they are unlikely to have bugs.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "structs.h"
#include "callbacks.h"
#include "pi.h"
#include "midi.h"
#include "debug.h"
// put our own header files next.
// Start with one that are #define and structs

// includes for header files based on our own C code goes here.
// Always include the header for the file itself 
// THis validates the header declarations against the defninitions.
// We are spoiled by our automatically generated headers, but we still
// validate them.  We put the include for this file dead last.
#include "output.h"
#include "bits.h"

#include "sim.h"

// sim owns this
#define DELTA_T (1.0 / 32.0)

//finally, clear three lists
void clear_lists(struct Sim *sim){
	struct Sim *li=sim;
		int smiles=deleteSome(&li->smile_list, always_T, NULL, delete_thing, TEXT);
		int shots=deleteSome(&li->shot_list, always_T, NULL, delete_thing, TEXT);
		int hits=deleteSome(&li->hit_list, always_T, NULL, delete_thing, TEXT);
		if(DEBUG)printf("DEBUG: sim.c: clear_list: %d smiles deleted\n", smiles);
		if(DEBUG)printf("DEBUG: sim.c: clear_list: %d shots deleted\n", shots);
		if(DEBUG)printf("DEBUG: sim.c: clear_list: %d hits deleted\n", hits);
}

//run the simulation
void run_sim(struct Sim *sim)
{
	sim->elapsed = 0.0;
	sim->delta_T = DELTA_T;
	sim->bonus = false;//set ai mode
	while (sim->elapsed<20.0&&count(sim->smile_list,always_T,NULL)>1){
		master_output(sim);
		sim->elapsed += DELTA_T;
		update_Projectile(sim);
		update_Smile(sim);	
}

	final_output(sim);
	clear_lists(sim);
}



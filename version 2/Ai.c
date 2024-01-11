//Bowei Kou

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "structs.h"
#include "debug.h"
#include "midi.h"
#include "callbacks.h"
#include "pi.h"
#include "linkedlist.h"
#include "output.h"

#include "Ai.h"

//make projectile
void fire(struct Object *ob, struct Sim *sim){

	fire_message(ob);
	struct Object *pro = allocateOb();
	pro->color = ob->color;
	pro->speed = ob->speed*2;
	pro->current = ob->current;
	pro->game = sim;
	insert(&sim->shot_list, pro, by_X, TEXT);
}

//delete projectile
void delete_Projectile(struct Sim *sim){
	deleteSome(&sim->shot_list, mustGo, NULL, delete_thing, TEXT);
}

//update the projectile
void update_Projectile(struct Sim *sim){
	if(sim->shot_list){
		iterate(sim->shot_list,new_XY);
		delete_Projectile(sim);
	}
}

//delete smile
void delete_Smile(struct Sim *sim){
	if(sim->shot_list){
		iterate(sim->shot_list,clear_smile);
	}
}

//update the smile
void update_Smile(struct Sim *sim){
	if(sim->smile_list){
		iterate(sim->smile_list, new_XY_S);
		delete_Smile(sim);
	}
}

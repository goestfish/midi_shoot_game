//Bowei Kou

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "structs.h"
#include "midi.h"
#include "memory.h"
#include "pi.h"
#include "Ai.h"
#include "debug.h"

#include "callbacks.h"


typedef bool (* ComparisonFunction) (void *data1, void *data2);

//compare by color
bool by_color(void *data1, void *data2){
	struct Object *ob1 = data1;
	struct Object *ob2 = data2;
	return ob1->color < ob2->color;
}

//compare by X
bool by_X(void *data1, void *data2){
	struct Object *ob1 = data1;
	struct Object *ob2 = data2;
	return ob1->current.X < ob2->current.X;
}

//compare by Y
bool by_Y(void *data1, void *data2){
	struct Object *ob1 = data1;
	struct Object *ob2 = data2;
	return ob1->current.Y < ob2->current.Y;
}

typedef bool (* CriteriaFunction)(void *data, void *helper);

//always return true
bool always_T(void *data, void*helper){
	return (true);
}

//check if the object hit the wall
bool good_position(void *data, void*helper){
	struct Object *ob = data;
	return (!midi_touches_wall(ob->current.X,ob->current.Y));
}

//check if the projectile should be clear
bool mustGo(void *data, void*helper){
	struct Object *ob = data;
	if(midi_touches_wall(ob->current.X,ob->current.Y)){
		wall_message(ob);
	}
	return (midi_touches_wall(ob->current.X,ob->current.Y));
}

//check if the smile is hitted
bool hit_smile(void *data, void*helper){
	struct Object *sm = data;
	struct Object *pro = helper;
	double distance = sqrt(pow(sm->current.X-pro->current.X,2)+ pow(sm->current.Y-pro->current.Y,2));
	if(distance<1.0&&(sm->color!=pro->color)){
		if(TEXT)hit_message(sm,pro);
		pro->game->score[pro->color]+=1;
		return true;
	}else{
		return false;
	}
}

typedef void (* ActionFunction) (void *data);

//delete the data
void delete_thing(void *data){
	struct Object *ob=data;
	freeOb(ob);
}

//move smile to hit_list
void transfer_thing(void *data){
	struct Object *ob=data;
	insert(&ob->game->hit_list, ob, by_color, TEXT);
}

//delete the smile
void clear_smile(void *data){
	struct Object *ob=data;
	deleteSome(&ob->game->smile_list, hit_smile, ob, transfer_thing, TEXT);
}

//get new x and y for projectile
void new_XY(void *thing){
        struct Object *ob = thing;
	ob->current.X=(ob->current.X + ob->speed*ob->game->delta_T*sin(ob->current.direction*M_PI / 180.0));
	ob->current.Y=(ob->current.Y + ob->speed*ob->game->delta_T*cos(ob->current.direction*M_PI / 180.0));
}

//smile do the rotation and fire
void rotation(void *thing){
        struct Object *ob=thing;
	int rotation;
	
        if(ob->color&1){
                rotation = -10;
        }else{
                rotation = 10;
        }

        if(ob->current.direction<-360){
                ob->current.direction += 360;
        }else if(ob->current.direction>360){
                ob->current.direction -= 360;
        }
	
        ob->current.direction += rotation;
	if(DEBUG) printf("DEBUG: default_ai: %d at %4.2f, %4.2f facing %.0f turn to by %d\n", ob->color, ob->current.X, ob->current.Y, ob->current.direction, rotation);
	if((int)ob->current.direction%90==0){
		fire(ob,ob->game);
	}
}

//function for bonus ai where smile will reflect
void reflect(void *thing){
	struct Object *ob=thing;
	
	double facing = ob->current.direction;
	double radian = ob->current.direction*M_PI/180.0;
	double first=atan2(-sin(radian),cos(radian))*180/M_PI;//first angle
	double second=atan2(sin(radian),-cos(radian))*180/M_PI;//second angle

	if(first<0) first+=360; else if (first>360) first -=360;
	if(second<0) second+=360; else if (second>360) second -= 360;
	//first new x
	double x1=ob->current.X+ob->speed*ob->game->delta_T*sin(first*M_PI/180);
	//first new y
	double y1=ob->current.Y+ob->speed*ob->game->delta_T*cos(first*M_PI/180);
	if(!midi_touches_wall(x1,y1)){
		ob->current.direction = first;
	}else {
		//second new y
		double x2 = ob->current.X+ob->speed*ob->game->delta_T*sin(second*M_PI/180);
		//second new x
		double y2 = ob->current.Y+ob->speed*ob->game->delta_T*cos(second*M_PI/180);
		if(!midi_touches_wall(x2,y2)){
			ob->current.direction=second;
		}else{
			//both are not ok, use 180 degree
			ob->current.direction+=180;
			if(ob->current.direction>=360) ob->current.direction-=360;
		}
	}
	if(DEBUG) printf("DEBUG: reflect_ai: %d at %4.2f, %4.2f facing %.0f turns to %.0f\n", ob->color, ob->current.X, ob->current.Y, facing, ob->current.direction);

	fire(ob, ob->game);
}

//get new x and y for smile
void new_XY_S(void *thing){
	struct Object *ob = thing;
	double x=(ob->current.X + ob->speed*ob->game->delta_T*sin(ob->current.direction*M_PI / 180.0));
	double y=(ob->current.Y + ob->speed*ob->game->delta_T*cos(ob->current.direction*M_PI / 180.0));
	if(!midi_touches_wall(x,y)){

		if(ob->game->bonus){
			if(DEBUG) printf("DEBUG: reflect_ai: %d at %4.2f, %4.2f facing %.0f steps\n", ob->color, ob->current.X, ob->current.Y, ob->current.direction);
		}else{
			if(DEBUG) printf("DEBUG: default_ai: %d at %4.2f, %4.2f facing %.0f steps\n", ob->color, ob->current.X, ob->current.Y, ob->current.direction);
		}
		ob->current.X=x;
		ob->current.Y=y;
	}else{
		if(ob->game->bonus) reflect(ob);
		else rotation(ob);
	}
}


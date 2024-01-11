//Bowei Kou

#include <stdio.h>
#include <stdbool.h>
#include "output.h"
#include "debug.h"
#include "bits.h"
#include "n2.h"

// print the color, speed, and data of the ball, also print the time
void master_text(double et, unsigned short code, double ball[]){
	double sp = getSpeed(code);
	int color = getColor(code);
	if(DEBUG)printf("\nC  S    __X______, __Y______    _D_    ET=%9f\n", et);
	if(DEBUG)printf("%d  %.0f    %9f, %9f    %3.0f\n", color,sp,ball[0],ball[1],ball[2]);
}

//output in graphics mode
void master_graphics(double et, unsigned short code, double ball[]){
	int co=getColor(code);
	midi_clear();
	if(isProjectile(code))midi_projectile(co, ball[0], ball[1], ball[2]);
	else if(isSmile(code)) midi_smile(0, co, ball[0], ball[1], ball[2]);
	midi_time(et*1000);
	midi_refresh();
	microsleep(ball[5]*1000000);
}

//output midi_x function
void master_X(double time, unsigned short code, double ball[]){
	int co=getColor(code);
	if(isSmile(code)){
		midi_X(co, ball[0], ball[1]);
	}

}

// print the scanf's returning value
void master_scanf(int words){
	if(DEBUG){
		printf("scanf returned %d\n", words);
	}
}


// print the message when ball touches the wall
void master_touch_wall(double time, unsigned short code, double ball[]){
	double sp = getSpeed(code);
	int color = getColor(code);
	bool sm = isSmile(code);
	bool pro = isProjectile(code);
	if(DEBUG) printf("\nAt elapsed time %f:\n", time);
	if(DEBUG){
		if(sm == true){
			printf("Smile %d at %.7f, %.7f speed %.0f direction %.0f will hit the wall.\n",color, ball[0], ball[1], sp, ball[2]);
		} else if(pro == true){
			printf("Projectile %d at %.7f, %.7f speed %.0f direction %.0f will hit the wall.\n",color, ball[0], ball[1], sp, ball[2]);
		}
	}
}

//output when ball touches the wall
void master_wall_output(double time, unsigned short code, double ball[]){
	if(TEXT){
	 	master_touch_wall(time, code, ball);
	}
	if(GRAPHICS) master_X(time, code, ball);
}

//output for text and graphic
void master_output(double et, unsigned short code, double ball[]){
	if(TEXT){
		master_text(et,code,ball);
	}
	if(GRAPHICS)master_graphics(et,code,ball);
}


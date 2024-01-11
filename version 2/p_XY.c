#include <stdio.h>
#include <stdlib.h>

#include "structs.h"

#include "p_XY.h"

typedef bool (* ComparisonFunction) (void *data1, void *data2);

bool by_X(void *data1, void *data2){
        struct Object *ob1 = data1;
        struct Object *ob2 = data2;
        return ob1->current.X < ob2->current.Y;
}

bool by_Y(void *data1, void *data2){
        struct Object *ob1 = data1;
        struct Object *ob2 = data2;
        return ob1->current.X < ob2->current.Y;
}

int main(){
        struct Object* ob1 = malloc(sizeof(struct Object));
        struct Object* ob2 = malloc(sizeof(struct Object));
        ob1->current.X = 1.0;
	ob1->current.Y = 1.0;
        ob2->current.X = 2.0;
	ob2->current.Y = 2.0;

        printf("For X, should be 1 and is %i\n", by_X(ob1, ob2));
	printf("For Y, should be 1 and is %i\n", by_Y(ob1, ob2));

        free(ob1);
	free(ob2);
	return 0;
}


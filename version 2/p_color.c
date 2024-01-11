#include <stdio.h>
#include <stdlib.h>

#include "structs.h"

#include "p_color.h"

typedef bool (* ComparisonFunction) (void *data1, void *data2);

bool by_color(void *data1, void *data2){
        struct Object *ob1 = data1;
        struct Object *ob2 = data2;
        return ob1->color < ob2->color;
}

int main(){
	struct Object* ob1 = malloc(sizeof(struct Object));
	struct Object* ob2 = malloc(sizeof(struct Object));
	ob1->color = 1;
	ob2->color = 2;

	printf("Should be 1 and is %i\n", by_color(ob1, ob2));

	free(ob1);
	free(ob2);
	return 0;
}

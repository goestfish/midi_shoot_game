#include <stdlib.h>
#include <stdio.h>

#include "p_memory.h"
#include "structs.h"
#include "debug.h"

struct Object* allocateOb(){
	static int ob_allocate = 0;
	struct Object* ob = malloc(sizeof(struct Object));
	if (ob == NULL){
		if(TEXT) printf("DIAGNOSTIC: Memory allocation failed.\n");
		return NULL;
	}
	ob_allocate++;
	if (TEXT) printf("DIAGNOSTIC: %d objects allocated.\n", ob_allocate);
	return ob;
}

void freeOb(struct Object *ob){
	static int ob_free = 0;
	if(ob !=NULL){
		free(ob);
		ob_free++;
		printf("DIAGNOSTIC: %d objects freed.\n", ob_free);
	}
	else printf("DIAGNOSTIC: Accepts a NULL pointer.\n");
}

int main(){
	struct Object* ob1 = allocateOb();
	struct Object* ob2 = allocateOb();
	freeOb(ob1);
	freeOb(ob2);
	return 0;
}

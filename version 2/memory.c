/* Bowei Kou */

#include <stdlib.h>
#include <stdio.h>

#include "altmem.h"
#include "structs.h"
#include "debug.h"

#include "memory.h"


struct Object *allocate_object()
{
        struct Object *bp;
        static int allocations = 0;

        if( bp = alternative_calloc(1, sizeof(struct Object)))
        {
            allocations++;
            if(TEXT)printf("DIAGNOSTIC: %d objects allocated.\n", allocations);
        }
        else
        {
            if(TEXT)printf("ERROR: failed to allocate object.\n");
        }

        return bp;

}


// I might get called as an action function, hence the signature
void free_object(void *data)
{
        static int freed = 0;

        if(data)
        {
            freed++;
            alternative_free(data);
            if(TEXT)printf("DIAGNOSTIC: %d objects freed.\n", freed);
        }
        else
        {
            if(TEXT)printf("ERROR: tried to free NULL pointer.\n");
        }

}


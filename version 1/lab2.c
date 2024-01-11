//Bowei Kou

#include <stdio.h>
#include <stdbool.h>
#include "lab2.h"
#include "midi.h"
#include "n2.h"
#include "input.h"
#include "debug.h"

int main()
{
	int rval = 0;//exit success
	double start, runtime;

	start = now();

	if(TEXT||(GRAPHICS&&midi_initialize(GRAPHICS)))
	{
		if( !master_input()) rval = 2;
		if(GRAPHICS)midi_teardown();
	}
	else
	{
	 rval = 1;//exit failure
	}
	printf("Returning %d\n", rval);
	runtime = now() - start;
	printf("Total runtime is %.9lf seconds\n", runtime);
	return rval;
}


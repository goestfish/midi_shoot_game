//Bowei Kou

// put system shared libraries first - they are unlikely to have bugs.
#include <stdio.h>
#include <stdlib.h>

#include "midi.h"
#include "debug.h"
#include "n2.h"
#include "input.h"

#include "lab3.h"

#define RVAL_BAD_INIT (1)
#define RVAL_BAD_INPUT (2)


/* I own all inits.  In future labs, I might morph to master init and call
 * my init minions to do the various subtasks.  For now, I'm simple enough
 * to do it all easily myself.  I shield main for all details about
 * initializations */
bool init()
{
	/* we might take manual control over what we feed midi_init
	 * SO that we turn it off but still debug our code. */
	return(TEXT || ( GRAPHICS && midi_initialize(false)));

}

/* Put all of the toys away.  In future labs I will own more stuff and
 * call my minions to do those things. */
void teardown()
{
	if(GRAPHICS)midi_teardown();
}


/* Avoid details and call upon my minions to make it everything happen.  I own
 * those highest level things that I must own: performance timing and the
 * value we return to linux */
int main()
{
	int rval = EXIT_SUCCESS;
	double start, runtime;

	start = now();	// this is the very first executable statement

	if( init())
	{
	    if( !good_input_run()) rval = RVAL_BAD_INPUT;
	    teardown();
	}
	else
	{
	    rval = RVAL_BAD_INIT;	// non zero, indicates an error
	}
	
	/* at this point we are done, graphics has been torn down*/
	printf("Returning %d\n", rval);
	runtime = now() - start;
	/* after graphics has been torn down, we can freely print */
	printf("Total runtime is %.9lf seconds\n", runtime);

	return rval;
}


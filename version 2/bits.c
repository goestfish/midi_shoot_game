
/* Copyright 2023, Neil Kirby.  Not for disclosure without permission */

// put system shared libraries first - they are unlikely to have bugs.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// put our own header files next.
// Start with one that are #define and structs

// includes for header files based on our own C code goes here.
// Always include the header for the file itself
// THis validates the header declarations against the defninitions.
// We are spoiled by our automatically generated headers, but we still
// validate them.  We put the include for this file dead last.
#include "bits.h"

bool is_smile(unsigned short code)
{
	return( ((code >> 4) & 0x03) == 0);
}

bool is_projectile(unsigned short code)
{
	return( ((code >> 4) & 0x03) == 1);
}

unsigned int get_color(unsigned short code)
{
	return ( code & 0x7);
}

unsigned int get_speed(unsigned short code)
{
	return ( (code >> 8) & 0xF);
}

bool valid_code(unsigned short code)
{
	unsigned int expect, actual = 0;
	unsigned int speed;

	speed = get_speed(code);
	expect = code >>12;
	code &= 0xFFF;
	while(code)
	{
	    actual += code & 0x01;
	    code = code >> 1;
	}
	// debug statement goes here
	return ( (speed >0) && (expect == actual));
}



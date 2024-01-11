//Author:Bowei Kou

#include <stdio.h>
#include <stdbool.h>
#include "bits.h"

#define color 0x0007
#define type 0x0030
#define speed 0x0F00
#define checksum 0xF000

//get color as an integer value
int getColor(unsigned short code){
	return code&color;
	}

//get Type as an interger value
int getType(unsigned short code){
	return (code&type)>>4;
	}

//check if the bits are for a smile
bool isSmile(unsigned short code){
	return getType(code)==0;
	}

//check if the bits are for a projectile
bool isProjectile(unsigned short code){
	return getType(code)==1;
	}
//get speed as an integer value
int getSpeed (unsigned short code){
	return (code&speed)>>8;
	}

//get checksum value as an integer value
int getChecksum(unsigned short code){
	return (code&checksum)>>12;
	}

//check if the bits are valid
bool isValid(unsigned short code){
	int cs=getChecksum(code);
	int s=getSpeed(code);

	//get number of 1 bits
	int num=0;
	for (int i=0;i<12;i++){
		num+=(code>>i)&1;
	}
	return cs==num && s!=0;
	}


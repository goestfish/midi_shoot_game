//Author:Bowei Kou

#include <stdio.h>
#include <stdbool.h>
#include "p_bits.h"

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

//if the bits are for a smile
bool isSmile(unsigned short code){
	return getType(code)==0;
}

//if the bits are for a projectile
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

//if the bits are valid
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

int main(){
	unsigned short code=0x4213;
	int c=getColor(code);
	int s=getSpeed(code);
	bool smile=isSmile(code);
	bool projectile=isProjectile(code);
	bool valid=isValid(code);
	printf("color is %d, speed is %d, smile is %d, projectile is %d, valid is %d\n",c,s,smile,projectile,valid);
	return 0;
}

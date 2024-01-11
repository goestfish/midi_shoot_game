//Bowei Kou

#include <stdio.h>
#include <stdbool.h>

#define type 0x0030

int getType(unsigned short code){
	return (code&type)>>4;
}

int isSmile(unsigned short code){
	return getType(code)==0;
}

int main(){
	unsigned short code = 0x4107;
	bool re = isSmile(code);
	if (re==true){
		printf("Is smile\n");
	} else{
		printf("Is not smile\n");
	}
	return 0;
}

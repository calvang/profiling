#include <stdio.h>
#include <stdlib.h> // added
#include <string.h>
//#include <unistd.h>

#define LONG_TIME (0xffffffff/8)

void child1(void) {
	printf("\n     Inside child1()\n");
	int i = 0;

	for( ; i < (LONG_TIME * 2); i++) {
		// Prevent the compiler from optimizing out empty loop
		asm("nop;");
	}

	return;
}

void child2(void) {
	int i = 0;

	for( ; i < 16; i++) {
		// Prevent the compiler from optimizing out empty loop
		asm("nop;");
	}

	return;
}

void parent(void) {
	printf("\n   Inside parent \n");
	int i = 0;

	for (i=0 ; i < (LONG_TIME); i++) {
		// Prevent the compiler from optimizing out empty loop
		asm("nop;");
	}
	child1();

	printf("\n     Starting child2() loop\n");
	for (i=0 ; i < (LONG_TIME/2); i++) {
		child2();
	}

	return;
}

static void no_children(void) {
	printf("\n   Inside no_children \n");
	int i = 0;

	for (i=0; i < (LONG_TIME * 5); i++) {
		// Prevent the compiler from optimizing out empty loop
		asm("nop;");
	}

	return;
}

void Branch1(int i, int prob){
	if (i < prob) {
		printf("\n Inside branch1()\n");
	}
	return;
}

void Branch2(int i, int prob){
	if (i < prob) {
		printf("\n Inside branch2()\n");
	}
	return;
}

void Branch3(int i, int prob){
	if (i < prob) {
		printf("\n Inside branch3()\n");
	}
	return;
}

void never(int i){
	if (i > 4) {
		printf("\n Inside never()\n");
	}
	return;
}
void always(int i){
	if (i < 4) {
		printf("\n Inside always()\n");
	}
	return;
}

int main(int argc, char **argv) {
	printf("\n Inside main()\n");
	int i = 0;
	// added 
	//parent();
	//no_children();
	int branch1 = atoi(argv[1]);
	int branch2 = atoi(argv[2]);
	int branch3 = atoi(argv[3]);
	for (int k = 0; k < 2000; ++k){
		i = rand() % 4; // generate random values from 0 to 3 
		Branch1(i,branch1);
		Branch2(i,branch2);
		Branch3(i,branch3);
		never(i);
		always(i);
	}
	printf("\n Exiting \n");
	return 0;
}

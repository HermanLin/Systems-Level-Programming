#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	//vars
	int z;
	
	//random number generator
	srand( time(NULL) );
	
	/*===NON POINTER===*/
	//populating non pointer array
	int non_pointer[10];
	
	for (z = 0; z < 10; z ++) {
		non_pointer[z] = rand();
	}
	non_pointer[9] = 0;
	
	//printing non pointer array
	printf("non_pointer\n");
	for (z = 0; z < 10; z ++) {
		printf("arr[%d]: %d\n", z, non_pointer[z]);
	}
	/*=================*/
	
	/*===POINTER===*/
	//populating pointer array
	int pointer[10];
	int *flip;
	for (z = 9; z >=0; z --) {
		flip = &non_pointer[z];
		pointer[9 - z] = *flip;
	}
	
	//printing pointer array
	printf("\npointer\n");
	for(z = 0; z < 10; z ++) {
		printf("arr2[%d]: %d\n", z, pointer[z]);
	}
	/*=============*/
	
	return 0;
}
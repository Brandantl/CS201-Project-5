// CS201 Assignment 5: Optimization of a loop.
//
// This is your starting code.  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Submitted code must have the correct values for these two constants:
//    N_TIMES:      200000
//    ARRAY_SIZE:     9973
// Feel free to play with these numbers below during test, 
// but ensure you submit with the correct numbers.
//
#define N_TIMES     200000
#define ARRAY_SIZE    9973

int main(void)
{
	int  *array = (int *)calloc(ARRAY_SIZE, sizeof(int));
	int  sum = 0;
	int  checksum = 0;
	int  i;
	int  j;
	int  x;

	// Make sure you change this so you get credit.
	//
	printf("CS201 - A05\n");

	// Initialize the array with random values 0 to 13. 
	//
	srand(time(NULL));
	for (j = 0; j < ARRAY_SIZE; j++) {

		x = rand() / (int)(((unsigned)RAND_MAX + 1) / 14);
		array[j] = x;
		checksum += x;
	}
	//printf("Checksum is %d.\n",checksum);
	clock_t startTime = clock();

	int sum_cache = -1;
	for (i = 0; i < N_TIMES; i++) {

		// ---------------------------------------------------------------
		// Do not alter anything above this line, except for the print 
		// statement with your name, and any variables that need to be declared
		// outside of the i loop.  Here is where you make your changes to 
		// optimize performance.  

		if (sum_cache < 0) {
			for (j = 0; j < ARRAY_SIZE; j++) {
				sum += array[j];
			}
			sum_cache = sum;
		}
		else {
			sum = sum_cache;
		}


		// Do not alter anything below this line.
		// ---------------------------------------------------------------

		// Check each iteration.  
		//
		if (sum != checksum) {
			printf("Checksum error!\n");
		}
		sum = 0;

	}

	clock_t endTime = clock();
	clock_t clockTicksTaken = endTime - startTime;
	double timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;
	printf("Time: %f\n", timeInSeconds);

	getchar();
	getchar();
	return 0;
}
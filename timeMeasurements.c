#include"binary_s.h"
#include <time.h>
#define MAXVAL 255
#define NUM_ELEM_UNSORT_ARR 100000
#define NUM_OF_REP 10000

#define VARIABLES_FOR_MACRO clock_t start; clock_t stop; double elapsed

#define TIME_MEASUREMENT_SEARCH(FUNCTION, INPUT_ARRAY, NUM_ARR_ELEM) start = clock();\
	for(i = 0; i < NUM_ARR_ELEM; i += NUM_ARR_ELEM/NUM_OF_REP)\
		FUNCTION(i, INPUT_ARRAY, NUM_ARR_ELEM);\
	stop = clock();\
	elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC\

static void fillRandom(int* tab, int numberOfElem)
{
	for (int i = 0; i < numberOfElem; i++)
		{
		tab[i] = randomNumbers(0,MAXVAL);
		}
}

int main()
{
	printf("Measurment for %d elements in unsorted array.\n", NUM_ELEM_UNSORT_ARR);
	srand(time(0));
	clock_t start, stop;
	double elapsed;
	int* arrayWithRandNum = malloc(NUM_ELEM_UNSORT_ARR * sizeof(*arrayWithRandNum));
	int scale = NUM_ELEM_UNSORT_ARR/NUM_OF_REP;
	int i;

	fillRandom(arrayWithRandNum, NUM_ELEM_UNSORT_ARR);

	start = clock();
	countSort(arrayWithRandNum, NUM_ELEM_UNSORT_ARR, MAXVAL);
	stop = clock();
	elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time to count sort a %d element array [ms]: %f\n", NUM_ELEM_UNSORT_ARR, elapsed);

	fillRandom(arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	TIME_MEASUREMENT_SEARCH(linearSearch, arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	printf("Time to %d linear search in a %d element array [ms]: %f\n", NUM_ELEM_UNSORT_ARR, NUM_ELEM_UNSORT_ARR, elapsed);

	fillRandom(arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	countSort(arrayWithRandNum, NUM_ELEM_UNSORT_ARR, MAXVAL);
	TIME_MEASUREMENT_SEARCH(binarySearch, arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	printf("Time to %d binary search (+ count sort) a %d element array [ms]: %f\n", NUM_ELEM_UNSORT_ARR, NUM_ELEM_UNSORT_ARR, elapsed);

	free(arrayWithRandNum);
	arrayWithRandNum = NULL;

}

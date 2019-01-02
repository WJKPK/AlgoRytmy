#include"binary_s.h"
#include <time.h>
#define SIZE 10
#define MAXVAL 100000000
#define NUM_ELEM_UNSORT_ARR 10000
#define NUM_OF_REP 10000

#define FREE(POINTER) do{free(POINTER);\
POINTER = NULL;} while(0)

#define TIME_MEASUREMENT_SEARCH(FUNCTION, INPUT_ARRAY, NUM_ARR_ELEM) do{start = clock();\
	for(i = 0; i < NUM_ARR_ELEM; i += NUM_ARR_ELEM/NUM_OF_REP)\
		FUNCTION(i, INPUT_ARRAY, NUM_ARR_ELEM);\
	stop = clock();\
	elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;} while(0)

static int Compare (const void* a, const void* b)
{
	  if(*(int*)a < *(int*)b) return -1;
	  else if(*(int*)a == *(int*)b) return 0;
	  else return 1;
}

static void fillRandom(int* tab, int numberOfElem)
{
	for (int i = 0; i < numberOfElem; i++)
		{
		tab[i] = randomNumbers(0,MAXVAL);
		}
}

int main()
{
	int arrayOfNumbers[SIZE] = {3, 3, 3, 7, 7, 13, 18, 21, 25, 27};
	printf("\nGiven is an array: 3, 3, 3, 7, 7, 13, 18, 21, 25, 27\n");
	printf("Search 3 using a lowerbound binary search: %d\n", binarySearchLowerBound(3, arrayOfNumbers, SIZE));
	printf("Search 3 using a upperbound binary search: %d\n", binarySearchUpperBound(3, arrayOfNumbers, SIZE));
	printf("\nMeasurment for %d elements in unsorted array.\n", NUM_ELEM_UNSORT_ARR);
	srand(time(0));
	clock_t start, stop;
	double elapsed;
	int* arrayWithRandNum = malloc(NUM_ELEM_UNSORT_ARR * sizeof(*arrayWithRandNum));
	int i;

	fillRandom(arrayWithRandNum, NUM_ELEM_UNSORT_ARR);

	start = clock();
	int* histogram = countSort(arrayWithRandNum, NUM_ELEM_UNSORT_ARR, MAXVAL);
	stop = clock();
	elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	FREE(histogram);
	printf("Time to count sort a %d element array [ms]: %f\n", NUM_ELEM_UNSORT_ARR, elapsed);

	fillRandom(arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	start = clock();
	qsort(arrayWithRandNum, NUM_ELEM_UNSORT_ARR, sizeof(*arrayWithRandNum), Compare);
	stop = clock();
	elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	FREE(histogram);
	printf("Time to qsort a %d element array [ms]: %f\n", NUM_ELEM_UNSORT_ARR, elapsed);


	start = clock();
	bubbleSort(arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	stop = clock();
	elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time to bubbleSort a %d element array [ms]: %f\n", NUM_ELEM_UNSORT_ARR, elapsed);

	fillRandom(arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	TIME_MEASUREMENT_SEARCH(linearSearch, arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	printf("Time to %d linear search in a %d element array [ms]: %f\n", NUM_ELEM_UNSORT_ARR, NUM_ELEM_UNSORT_ARR, elapsed);

	fillRandom(arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	histogram = countSort(arrayWithRandNum, NUM_ELEM_UNSORT_ARR, MAXVAL);
	TIME_MEASUREMENT_SEARCH(binarySearch, arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	printf("Time to %d binary search (+ count sort) a %d element array [ms]: %f\n", NUM_ELEM_UNSORT_ARR, NUM_ELEM_UNSORT_ARR, elapsed);

	FREE(arrayWithRandNum);
	FREE(histogram);
}

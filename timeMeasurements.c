#include"binary_s.h"
#include <time.h>
#define SIZE 10
#define MAXVAL 3000000
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
	int arrayOfNumbers[SIZE] = {2, 3, 3, 7, 7, 13, 18, 21, 25, 27};
	printf("\nGiven is an array: 3, 3, 3, 7, 7, 13, 18, 21, 25, 27\n");
	printf("Search element with value 3 using a lowerbound binary search: %d\n", binarySearchLowerBound(3, arrayOfNumbers, SIZE));
	printf("Search element with value 4 using a lowerbound binary search: %d\n", binarySearchLowerBound(4, arrayOfNumbers, SIZE));
	printf("Search element with value 3 using a upperbound binary search: %d\n", binarySearchUpperBound(3, arrayOfNumbers, SIZE));
	printf("Search element with value 4 using a upperbound binary search: %d\n", binarySearchUpperBound(4, arrayOfNumbers, SIZE));
	printf("Search element with value 4 using a binary search: %d\n", binarySearch(4, arrayOfNumbers, SIZE));
	printf("Search element with value 2 using a binary search: %d\n", binarySearch(2, arrayOfNumbers, SIZE));
	printf("Search element with value 3 using a binary search: %d\n", binarySearch(3, arrayOfNumbers, SIZE));
	printf("Search element with value 13 using a binary search: %d\n", binarySearch(13, arrayOfNumbers, SIZE));
	printf("\nMeasurement for %d elements in unsorted array.\n", NUM_ELEM_UNSORT_ARR);
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
	printf("Time to count sort an array containing %d elements [ms]: %f\n", NUM_ELEM_UNSORT_ARR, elapsed);

	fillRandom(arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	start = clock();
	qsort(arrayWithRandNum, NUM_ELEM_UNSORT_ARR, sizeof(*arrayWithRandNum), Compare);
	stop = clock();
	elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	FREE(histogram);
	printf("Time to qsort an array containing %d elements  [ms]: %f\n", NUM_ELEM_UNSORT_ARR, elapsed);


	start = clock();
	bubbleSort(arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	stop = clock();
	elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time to bubble sort an array containing %d elements [ms]: %f\n", NUM_ELEM_UNSORT_ARR, elapsed);

	fillRandom(arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	TIME_MEASUREMENT_SEARCH(linearSearch, arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	printf("\nTime to %d linear search in a %d element array [ms]: %f\n", NUM_ELEM_UNSORT_ARR, NUM_ELEM_UNSORT_ARR, elapsed);

	fillRandom(arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	histogram = countSort(arrayWithRandNum, NUM_ELEM_UNSORT_ARR, MAXVAL);
	TIME_MEASUREMENT_SEARCH(binarySearch, arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	printf("Time to %d binary search a %d element array [ms]: %f\n", NUM_ELEM_UNSORT_ARR, NUM_ELEM_UNSORT_ARR, elapsed);

	FREE(arrayWithRandNum);
	FREE(histogram);
}

#include"binary_s.h"
#include <time.h>
#define MAXVAL 255
#define NUM_ELEM_UNSORT_ARR 100000
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

	int* arrayWithRandNum = malloc(NUM_ELEM_UNSORT_ARR * sizeof(*arrayWithRandNum));
	int i;

	fillRandom(arrayWithRandNum, NUM_ELEM_UNSORT_ARR);

	clock_t start = clock();
	countSort(arrayWithRandNum, NUM_ELEM_UNSORT_ARR, MAXVAL);

	clock_t stop = clock();
	double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time to count sort a %d element array [ms]: %f\n", NUM_ELEM_UNSORT_ARR, elapsed);

	fillRandom(arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	start = clock();
	int divided;
	for(i = 0; i < NUM_ELEM_UNSORT_ARR; i+=MAXVAL)
	{
		divided = i/MAXVAL;
		linearSearch(divided, arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	}
	stop = clock();
	elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time to %d linear search in a %d element array [ms]: %f\n", NUM_ELEM_UNSORT_ARR, NUM_ELEM_UNSORT_ARR, elapsed);

	fillRandom(arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	start = clock();
	countSort(arrayWithRandNum, NUM_ELEM_UNSORT_ARR, MAXVAL);

	for(i = 0; i < NUM_ELEM_UNSORT_ARR; i+=MAXVAL)
	{
		divided = i/MAXVAL;
		binarySearch(divided, arrayWithRandNum, NUM_ELEM_UNSORT_ARR);
	}
	stop = clock();
	elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time to %d binary search (+ count sort) a %d element array [ms]: %f\n", NUM_ELEM_UNSORT_ARR, NUM_ELEM_UNSORT_ARR, elapsed);

	free(arrayWithRandNum);
	arrayWithRandNum = NULL;

}

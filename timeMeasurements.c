#include"binary_s.h"
#include <time.h>
#define MAXVAL 255
#define NUM_ELEM_UNSSORT_ARR 1000

int main()
{
	printf("Measurment for %d elements in unsorted array.\n", NUM_ELEM_UNSSORT_ARR);
	srand(time(0));
	int* arrayWithRandNum = malloc(NUM_ELEM_UNSSORT_ARR*sizeof(*arrayWithRandNum));
	int i;
	for (i = 0; i < NUM_ELEM_UNSSORT_ARR; i++)
	{
		arrayWithRandNum[i] = randomNumbers(0,255);
	}
	clock_t start = clock();
	countSort(arrayWithRandNum, NUM_ELEM_UNSSORT_ARR, MAXVAL);
	clock_t stop = clock();

	double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time elapsed in ms: %f\n", elapsed);

	for (i = 0; i < NUM_ELEM_UNSSORT_ARR; i++)
	{
		arrayWithRandNum[i] = randomNumbers(0,255);
	}
	start = clock();
	bubbleSort(arrayWithRandNum, NUM_ELEM_UNSSORT_ARR);
	stop = clock();
	elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time elapsed in ms: %f\n", elapsed);

	free(arrayWithRandNum);
}

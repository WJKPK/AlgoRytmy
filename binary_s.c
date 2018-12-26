#include<stdio.h>
#include<stdlib.h>

int binarySearch(int value, int tab[], int tabSize)
{
	int firstElemNum = 0;
	int lastElemNum = tabSize-1;

	int result = -1;
	int midSearchedElem;

	while (firstElemNum <= lastElemNum)
	{
		midSearchedElem = ((firstElemNum  + lastElemNum) / 2);
		if(tab[midSearchedElem] == value)
		{
			result = midSearchedElem;
			return result;
		}
		if(tab[midSearchedElem] < value)
		{
			firstElemNum = midSearchedElem + 1;
		}
		if(tab[midSearchedElem] > value)
		{
			lastElemNum = midSearchedElem -1;
		}
	}
	return result;
}

int binarySearchLowerBound(int value, int tab[], int tabSize)
{
	int firstElemNum = 0;
	int lastElemNum = tabSize-1;

	int midSearchedElem;
	while (firstElemNum < lastElemNum)
	{
		midSearchedElem = ((firstElemNum  + lastElemNum) / 2);

		if(tab[midSearchedElem] < value)
		{
			firstElemNum = midSearchedElem + 1;
		}
		if(tab[midSearchedElem] >= value)
		{
			lastElemNum = midSearchedElem;
		}
	}
	return firstElemNum;
}

int binarySearchUpperBound(int value, int tab[], int tabSize)
{
	int firstElemNum = 0;
	int lastElemNum = tabSize;

	int midSearchedElem;

	while (firstElemNum < lastElemNum)
	{
		midSearchedElem = ((firstElemNum  + lastElemNum) / 2);
		if(tab[midSearchedElem] <= value)
		{
			firstElemNum = midSearchedElem + 1;
		}
		if(tab[midSearchedElem] > value)
		{
			lastElemNum = midSearchedElem;
		}
	}
	return firstElemNum - 1;
}

int* countSort (int inputArray[], const int numberOfElements, const int maxVal, int* restrict histogram)
{
	int* sorrtedArray = (int*)malloc(numberOfElements * sizeof(*sorrtedArray));
	histogram = (int*)calloc(maxVal + 1, sizeof(*histogram));

	int i;
	for (i = 0; i < numberOfElements; i++)
	{
		++histogram[inputArray[i]];
	}
	// te dwie petle wykonają się w sumie numOfElements razy.
	for (i = 0; i < maxVal +1; i++)
	{
		static int jMemoryVal = 0;
		int j = 0;
		for (; j < histogram[i]; j++)
		{
			sorrtedArray[jMemoryVal + j] = i;
		}
		jMemoryVal += j;
	}
	return sorrtedArray;
}

#include<stdio.h>
#include<time.h>
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

int* countSort (int* inputArray, const int numberOfElements, const int maxVal)
{
	int* sorrtedArray = (int*)malloc(numberOfElements * sizeof(*sorrtedArray));
	int* histogram = (int*)calloc(maxVal + 1, sizeof(*histogram));

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
			inputArray[jMemoryVal + j] = i;
		}
		jMemoryVal += j;
	}
	return histogram;
}

int randomNumbers(int min, int max)
{
    int tmp;
    if (max>=min)
        max-= min;
    else
    {
        tmp= min - max;
        min= max;
        max= tmp;
    }
    return max ? (rand() % max + min) : min;
}

void bubbleSort(int* inputArray, int sizeOfArray)
{
	int i, j, temp;
	for (i = 0; i < sizeOfArray - 1; i++)
        {
		for (j = 0; j < sizeOfArray - 1 - i; j++)
		{
			if (inputArray[j] > inputArray[j+1])
			{
				temp = inputArray[j + 1];
				inputArray[j + 1] = inputArray[j];
				inputArray[j] = temp;
			}
		}
        }
}

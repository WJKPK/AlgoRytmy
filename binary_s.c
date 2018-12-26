#include<stdio.h>
l
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

int binarySearchLowerCase(int value, int tab[], int tabSize)
{
	int firstElemNum = 0;
	int lastElemNum = tabSize-1;

	int midSearchedElem;
	int result = -1;

	while (firstElemNum <= lastElemNum)
	{
		midSearchedElem = ((firstElemNum  + lastElemNum) / 2);
		if(tab[midSearchedElem] == value)
		{
			result = midSearchedElem;
			lastElemNum = midSearchedElem-1;
		}
		if(tab[midSearchedElem] < value)
		{
			firstElemNum = midSearchedElem + 1;
		}
		if(tab[midSearchedElem] > value)
		{
			lastElemNum = midSearchedElem -1 ;
		}
	}
	return result;
}

int binarySearchUpperCase(int value, int tab[], int tabSize)
{
	int firstElemNum = 0;
	int lastElemNum = tabSize-1;

	int midSearchedElem;
	int result = -1;

	while (firstElemNum <= lastElemNum)
	{
		midSearchedElem = ((firstElemNum  + lastElemNum) / 2);
		if(tab[midSearchedElem] == value)
		{
			result = midSearchedElem;
			firstElemNum = midSearchedElem + 1;
		}
		if(tab[midSearchedElem] < value)
		{
			firstElemNum = midSearchedElem + 1;
		}
		if(tab[midSearchedElem] > value)
		{
			lastElemNum = midSearchedElem -1 ;
		}
	}
	return result;
}

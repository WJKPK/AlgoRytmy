#ifndef BINARY_S_H_
#define BINARY_S_H_

#include <stdio.h>
#include <stdlib.h>

int randomNumbers(int min, int max);
int binarySearch(int value, int tab[], int tabSize);
int binarySearchLowerBound(int value, int tab[], int tabSize);
int binarySearchUpperBound(int value, int tab[], int tabSize);
int linearSearch (int searchedValue, int tab[], int tabSize);
int* countSort (int* inputArray, const int numberOfElements, const int maxVal);
void bubbleSort(int* inputArray, const int sizeOfArray);
#endif /* BINARY_S_H_ */

#include <criterion/criterion.h>
#include "binary_s.h"

Test(binarySearchTest,oddSearch)
{
	int tab[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	for(int i = 0; i < 9; i++)
	{
		cr_assert(binarySearch(i,tab,9)==i, "ERR  in: %d", i);
	}
}

Test(binarySearchTest,evenSearch)
{
	int tab[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	for(int i = 0; i < 16; i++)
	{
		cr_assert(binarySearch(i,tab,16)==i, "ERR  in: %d", i);
	}
}

Test(binarySearchTestLowerBound, oddSearch)
{
	int tab[17] = {0, 1, 2, 3, 3, 4, 4, 4, 4, 7, 8, 9, 10, 11, 12, 13, 14};
	cr_assert(binarySearchLowerBound(0,tab,17) == 0, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerBound(4,tab,17) == 5, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerBound(3,tab,17) == 3, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerBound(14,tab,17) == 16, "ERR  in: binarySearchLowerCas");
}

Test(binarySearchTestLowerBound,evenSearch)
{
	int tab[20] = {0, 1, 2, 3, 3, 4, 4, 4, 4, 7, 8, 9, 10, 11, 12, 13, 14, 14, 15, 16};
	cr_assert(binarySearchLowerBound(0,tab,20) == 0, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerBound(4,tab,20) == 5, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerBound(3,tab,20) == 3, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerBound(13,tab,20) == 15, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerBound(14,tab,20) == 16, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerBound(16,tab,20) == 19, "ERR  in: binarySearchLowerCas");
}

Test(binarySearchTestUpperBound, oddSearch)
{
	int tab[17] = {0, 1, 2, 3, 3, 4, 4, 4, 4, 7, 8, 9, 10, 11, 12, 13, 14};
	cr_assert(binarySearchUpperBound(0,tab,17) == 0, "ERR  in: binarySearchUpperCas: 1");
	cr_assert(binarySearchUpperBound(4,tab,17) == 8, "ERR  in: binarySearchUpperCas: 2");
	cr_assert(binarySearchUpperBound(3,tab,17) == 4, "ERR  in: binarySearchUpperCas: 3");
	cr_assert(binarySearchUpperBound(14,tab,17) == 16, "ERR  in: binarySearchUpperCas: 4");
}

Test(countSortTest,firstTestSearch)
{
#define ARRAYSIZE 6
	int testArray[ARRAYSIZE] = {3,3,1,5,0,8};
	int* histo = countSort(testArray, ARRAYSIZE, 8);

	cr_expect(testArray[0] == 0, "ERR  in: countSort: 0");
	cr_expect(testArray[1] == 1, "ERR  in: countSort: 1");
	cr_expect(testArray[2] == 3, "ERR  in: countSort: 2");
	cr_expect(testArray[3] == 3, "ERR  in: countSort: 3");
	cr_expect(testArray[4] == 5, "ERR  in: countSort: 4");
	cr_expect(testArray[5] == 8, "ERR  in: countSort: 5");

	free(histo);

#undef ARRAYSIZE
}

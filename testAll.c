#include <criterion/criterion.h>
#include "binary_s.h"
#include <stdio.h>

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

Test(binarySearchTestLowerCase, oddSearch)
{
	int tab[17] = {0, 1, 2, 3, 3, 4, 4, 4, 4, 7, 8, 9, 10, 11, 12, 13, 14};
	cr_assert(binarySearchLowerCase(0,tab,17) == 0, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerCase(4,tab,17) == 5, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerCase(3,tab,17) == 3, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerCase(14,tab,17) == 16, "ERR  in: binarySearchLowerCas");
}

Test(binarySearchTestLowerCase,evenSearch)
{
	int tab[20] = {0, 1, 2, 3, 3, 4, 4, 4, 4, 7, 8, 9, 10, 11, 12, 13, 14, 14, 15, 16};
	cr_assert(binarySearchLowerCase(0,tab,20) == 0, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerCase(4,tab,20) == 5, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerCase(3,tab,20) == 3, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerCase(13,tab,20) == 15, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerCase(14,tab,20) == 16, "ERR  in: binarySearchLowerCas");
	cr_assert(binarySearchLowerCase(16,tab,20) == 19, "ERR  in: binarySearchLowerCas");
}

Test(binarySearchTestUpperCase, oddSearch)
{
	int tab[17] = {0, 1, 2, 3, 3, 4, 4, 4, 4, 7, 8, 9, 10, 11, 12, 13, 14};
	cr_assert(binarySearchUpperCase(0,tab,17) == 0, "ERR  in: binarySearchUpperCas: 1");
	cr_assert(binarySearchUpperCase(4,tab,17) == 8, "ERR  in: binarySearchUpperCas: 2");
	cr_assert(binarySearchUpperCase(3,tab,17) == 4, "ERR  in: binarySearchUpperCas: 3");
	cr_assert(binarySearchUpperCase(14,tab,17) == 16, "ERR  in: binarySearchUpperCas: 4");
}

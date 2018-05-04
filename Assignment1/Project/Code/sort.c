/**
 ============================================================================
 Name        : sort.c
 Author      : @author Samuel
 Version     : 1
 Copyright   : public
 Description : Jnim C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "sort.h"

/**
 * The method use pointers because swap is a void method
 * @param number_1
 * @param number_2
 */
void swap(int *number_1, int *number_2) {
	int temp = *number_1;
	*number_1 = *number_2;
	*number_2 = temp;
}

/**
 * @param array
 */
void sort(int array[3]) {
	if(array[1] > array[2]) swap(&array[1], &array[2]);
	if(array[0] > array[2]) swap(&array[0], &array[2]);
	if(array[0] > array[1]) swap(&array[0], &array[1]);
}

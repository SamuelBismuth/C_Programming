/**
 ============================================================================
 Name        : initialisation.c
 Author      : @author Samuel
 Version     : 1
 Copyright   : public
 Description : Jnim C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdbool.h>
#include "initialisation.h"
#include "sort.h"
#include "wronginput.h"

/**
 * @param number_1
 * @param number_2
 * @param number_3
 * @return true if computer's turn
 * @return false if user'turn
 */
bool whoBegin(int number_1, int number_2, int number_3) {
	if (number_3 == 0) return false;
	if (number_2 == 0 && number_3 == 1) return false;
	else if (number_2 == 0 && number_3 != 1) return true;
	else if (number_1 == 0 && number_2 == 1 && number_3 != 0) return true;
	else if (number_1 == 0 && number_2 + number_1 == number_3) return false; //if number_2 == number_3
	else if (number_1 + number_2 == number_3) return false;
	else return true;
}

/**
 * @param array
 * @return true if computer's turn
 * @return false if user'turn
 */
bool beginingOfTheGame(int array[3]) {
	printf("Please enter 3 numbers \n");
	fflush(stdout);
	if (scanf("%d", &array[0]) != 1 || array[0] < 0) badInput();
	if (scanf("%d", &array[1]) != 1 || array[1] < 0) badInput();
	if (scanf("%d", &array[2]) != 1 || array[2] < 0) badInput();
	sort(array);
	printf("packets size are %d, %d, %d \n", array[0], array[1], array[2]);
	if(whoBegin(array[0], array[1], array[2]) == 1) {
		printf("The computer begin \n");
		return true;
	}
	else {
		printf("The user begin \n");
		return false;
	}
}

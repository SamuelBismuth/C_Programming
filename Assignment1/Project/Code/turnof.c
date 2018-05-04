/**
 ============================================================================
 Name        : turnof.c
 Author      : @author Samuel
 Version     : 1
 Copyright   : public
 Description : Jnim C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdbool.h>
#include "turnof.h"
#include "sort.h"
#include "wronginput.h"

/**
 * here we use the secret of the game

 If the user know the secret he could win :
 here is an exemple :
 the user choose the numbers : 11 7 4 so, by our secret, we're giving the turn to the user (4 + 7 = 11)
 the the user make the choice 11 to 3, packets size are 7 4 3
 computer's turn, by our secret : 7 to 1, packets size are 4 3 1
 user's turn : 4 to 2, packets size are 3 2 1
 computer's turn : 3 to 1 packets size are 2 1 1
 user's turn : 2 to 1, packets size are 1 1 1
 computer's turn : 1 to 0 (there is no another choice to make), packets size are 1 1 0
 user's turn : 1 to 0, packets size are 1 0 0
 the user win !!
 * @param array
 */
void computerPlay(int array[3]) {
	if (array[0] == 0 && array[1] == 0 && array[2] == 1) {
		printf("I turned 1 to 0 \n");
		array[2] = 0;
	}
	else if (array[0] == 0 && array[1] == 0 && array[2] != 1) {
		printf("I turned %d to 1 \n", array[2]);
		array[2] = 1;
	}
	else if (array[0] == 0 && array[1] == 1 && array[2] != 0) {
		printf("I turned %d to 0 \n", array[2]);
		array[2] = 0;
	}
	else if (array[0] == 1 && array[1] == 1 && array[2] != 1) {
		printf("I turned %d to 1 \n", array[2]);
		array[2] = 1;
	}
	else if (array[1] != array[2] || array[0] != 0){
		printf("I turned %d to %d \n", array[2], array[1] - array[0]);
		array[2] = array[1] - array[0];
	}
	else {
		printf("I turned %d to %d \n", array[2], array[2] - 1);
		array[2] = array[2] - 1;
	}
	sort(array);
	printf("packets size are %d, %d, %d \n", array[0], array[1], array[2]);
}

/**
 * The method ask the user to input the number
 * @param array
 * @return true if the input is good
 * @return false if the input is wrong
 */
bool userPlay(int array[3]) {
	printf("Your turn : \n");
	fflush(stdout);
	int numberToSwap, numberWanted;
	scanf("%d to %d", &numberToSwap, &numberWanted);
	if (input(numberToSwap, numberWanted, array) == 1) {
		if (numberToSwap == array[0]) array[0] = numberWanted;
		else if (numberToSwap == array[1]) array[1] = numberWanted;
		else array[2] = numberWanted;
		sort(array);
		printf("packets size are %d, %d, %d \n", array[0], array[1], array[2]);
		return true;
	}
	return false;
}

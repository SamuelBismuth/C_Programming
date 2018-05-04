/*
 * StepOfTheGame.c
 *
 *  Created on: Dec 17, 2017
 *      Author: samuel
 */

/**
 * Includes.
 */
#include <stdio.h>
#include <stdlib.h>

#include "StepOfTheGame.h"
#include "PLayingField.h"
#include "InputException.h"

/**
 * This method reprensents the turn of the playerX.
 * The method first prints the field.
 * Then, aks the user an input.
 * Checks this input, and if it's a wrong input, aks the user to input again.
 */
void playerX() {
	printField();
	puts("Player‬‬ ‫‪X,‬‬ ‫‪please‬‬ ‫‪enter‬‬ ‫‪a‬‬ ‫‪column‬‬ ‫‪number‬‬ ‫‪(or‬‬ ‫‪0‬‬ ‫‪to‬‬ ‫‪undo):");
	int place = inputPlayer();
	if (place == 0) {
		place = undo();
		if (place == 0) {
			puts("‫‪Board‬‬ ‫‪is‬‬ ‫‪empty‬‬ ‫‪-‬‬ ‫‪can't‬‬ ‫!‪undo‬‬");
			playerX();
		}
	}
	else
		if (addChip('X', place) == 0){
			puts("‫‪Invalid‬‬ ‫‪input,‬‬ ‫‪this‬‬ ‫‪column‬‬ ‫‪is‬‬ ‫‪full.‬‬ ‫‪Please‬‬ ‫‪choose‬‬ ‫‪another‬‬ ‫‪one:‬‬");
			playerX();
		}
}

/**
 * This method reprensents the turn of the playerO.
 * The method first prints the field.
 * Then, aks the user an input.
 * Checks this input, and if it's a wrong input, aks the user to input again.
 */
void playerO() {
	printField();
	puts("Player‬‬ ‫‪O,‬‬ ‫‪please‬‬ ‫‪enter‬‬ ‫‪a‬‬ ‫‪column‬‬ ‫‪number‬‬ ‫‪(or‬‬ ‫‪0‬‬ ‫‪to‬‬ ‫‪undo):");
	int place = inputPlayer();
	if (place == 0) {
		place = undo();
		if (place == 0) {
			puts("‫‪Board‬‬ ‫‪is‬‬ ‫‪empty‬‬ ‫‪-‬‬ ‫‪can't‬‬ ‫!‪undo‬‬");
			playerO();
		}
	}
	else
		if (addChip('O', place) == 0) {
			puts("‫‪Invalid‬‬ ‫‪input,‬‬ ‫‪this‬‬ ‫‪column‬‬ ‫‪is‬‬ ‫‪full.‬‬ ‫‪Please‬‬ ‫‪choose‬‬ ‫‪another‬‬ ‫‪one:‬‬");
			playerO();
		}
}

/**
 * This method ask the user to input with the help of scanf.
 * @return the input of the user.
 */
int inputPlayer() {
	char input;
	scanf(" %c", &input);
	int place = isGoodInput(input);
	emptyBuffer();
	while (place == 8) place = inputPlayer();
	return place;
}

/**
 * This method empty the buffer.
 */
void emptyBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF)
        c = getchar();
}

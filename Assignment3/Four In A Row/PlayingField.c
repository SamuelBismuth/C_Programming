/*
 * PlayingField.c
 *
 *  Created on: Dec 17, 2017
 *      Author: samuel
 */

/**
 * Includes.
 */
#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"
#include "StackUndo.h"
#include "PLayingField.h"
#include "EndOfTheGame.h"

/**
 * Defines.
 */
#define ROW 6
#define COLUMN 7
#define PLACES 42

/**
 * Structure stack.
 */
struct Stack {
	char array[ROW];
	int top;
};

/**
 * Structure stack undo.
 */
struct StackUndo {
	int array[PLACES];
	int top;
};

/**
 * Global field and stack undo.
 */
struct Stack field[COLUMN];
struct StackUndo stackUndo;

/**
 * This method initialize the field.
 */
void initialisation() {
	stackUndo.top = -1;
	for (int column = 0; column < COLUMN; ++column)
		for (int row = 0; row < ROW; ++row)
			field[column].top = -1;
}

/**
 * This method print the field.
 */
void printField() {
	for (int row = 0; row < ROW; ++row) {
		for (int column = 0; column < COLUMN; ++column) {
			printf("|");
			if (size(&field[column]) >= (ROW - row  - 1)) printf("%c", field[column].array[ROW - row  - 1 ]);
			else printf(" ");
			if (column == COLUMN - 1) printf("|");
		}
		printf("\n");
	}
	for (int count = 1; count < COLUMN + 1; ++count) {
		printf(" %d", count);
	}
	printf("\n");
}

/**
 * This method add a chip in the filed.
 * @param chip.
 * @param place.
 * @return true is the chip is added.
 * return false if not.
 */
bool addChip(char chip, int place) {
	place--;
	if(push(&field[place], chip) == 0) return false;
	pushUndo(&stackUndo, place);
	isEndOfTheGame(&stack, place, size(&field[place]));
	return true;
}

/**
 * This method come back to the last position.
 * return the place of the chip poped.
 */
int undo() {
	return pop(&field[popUndo(&stackUndo)]);
}


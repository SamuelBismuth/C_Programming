/*
 * StackUndo.c
 *
 *  Created on: Dec 17, 2017
 *      Author: samuel
 */

/**
 * Includes.
 */
#include <stdio.h>
#include <stdlib.h>

#include "StackUndo.h"
#include "PLayingField.h"

/**
 * Define.
 */
#define PLACE 42

/**
 * Structure stack.
 */
struct StackUndo {
	int array[PLACE];
	int top;
};

/**
 * Stack is full when top is equal to the last index.
 * @param stack.
 * @return true if the stack is full.
 * @return false if not.
 */
int isFullUndo(struct StackUndo* stackUndo) {
	return stackUndo->top == PLACE - 1;
}

/**
 * Stack is empty when top is equal to the last index.
 * @param stack.
 * @return true if the stack is empty.
 * @return false if not.
 */
int isEmptyUndo(struct StackUndo* stackUndo) {
	return stackUndo->top == -1;
}

/**
 * This method add an item to the stack, and increases top by 1.
 * @param stack.
 * @param item.
 */
void pushUndo(struct StackUndo* stackUndo, int item) {
	if (isFullUndo(stackUndo)) {
		printField();
		puts("‫‪It's‬‬ ‫‪a‬‬ ‫!‪tie‬‬");
		exit(0);
	}
	stackUndo->array[++stackUndo->top] = item;
}

/**
 * This method remove an item to the stack, and decreases top by 1.
 * @param stack.
 * @return the number of the top.
 */
int popUndo(struct StackUndo* stackUndo) {
	if (isEmptyUndo(stackUndo))
		return 0;
	return stackUndo->array[stackUndo->top--];
}

/**
 * This method return the size of the stack.
 * @return top.
 */
int sizeUndo(struct StackUndo* stackUndo) {
	return stackUndo->top;
}

/*
 * Stack.c
 *
 *  Created on: Dec 17, 2017
 *      Author: samuel
 */

/**
 * Includes.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Stack.h"

/**
 * Define.
 */
#define ROW 6

/**
 * Structure stack.
 */
struct Stack {
	char array[ROW];
	int top;
};

/**
 * Stack is full when top is equal to the last index.
 * @param stack.
 * @return true if the stack is full.
 * @return false if not.
 */
int isFull(struct Stack* stack) {
	return stack->top == ROW - 1;
}

/**
 * Stack is empty when top is equal to the last index.
 * @param stack.
 * @return true if the stack is empty.
 * @return false if not.
 */
int isEmpty(struct Stack* stack) {
	return stack->top == -1;
}

/**
 * This method add an item to the stack, and increases top by 1.
 * @param stack.
 * @param item.
 */
bool push(struct Stack* stack, char item) {
	if (isFull(stack))
		return false;
	stack->array[++stack->top] = item;
	return true;
}

/**
 * This method remove an item to the stack, and decreases top by 1.
 * @param stack.
 * @return the number of the top.
 */
int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return 0;
    return stack->array[stack->top--];
}

/**
 * This method return the size of the stack.
 * @return top.
 */
int size(struct Stack* stack) {
	return stack->top;
}

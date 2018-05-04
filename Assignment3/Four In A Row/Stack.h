/*
 * Stack.h
 *
 *  Created on: Dec 17, 2017
 *      Author: samuel
 */

/**
 * Includes.
 */
#include <stdbool.h>

/**
 * Global stack.
 */
struct Stack stack;

int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
bool push(struct Stack* stack, char item);
int pop(struct Stack* stack);
int size(struct Stack* stack);



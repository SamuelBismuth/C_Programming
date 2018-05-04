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

#include "Stack.h"

/**
 * Define the head (top) and the size of the stack.
 */
Node* head;
int size = 0;

/**
 * This function define a new Node.
 */
Node* newNode(int data) {
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

/**
 * This function push push a new elenment in the stack.
 */
void push(int data) {
	if (size == 0)
		head = newNode(data);
	else {
		Node* new = newNode(data);
		new->prev = head;
		head->next = new;
		head = new;
	}
	size++;
}

/**
 * This function delete the head of the stack and return his data.
 */
int pop() {
	if (size == 0)
		return 0;
	int data = head->data;
	head = head->prev;
	free(head);
	size--;
	return data;
}

/**
 * This method return the size of the current stack.
 */
int sizeStack() {
	return size;
}

/*
 ============================================================================
 Name        : Question1a.c
 Author      : Samuel
 Version     :
 Copyright   : public
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/**
 * Includes.
 */
#include <stdio.h>
#include <stdlib.h>

#include "Question1a.h"

/**
 * Define the tail, the middle and the size of the Linked List.
 */
Node* tail;
Node* middle;
int size = 0;

/**
 * This function define a new Node.
 */
Node* newNode(Node* node, int data) {
	Node* nodeTemp = (Node*) malloc(sizeof(Node));
	nodeTemp->data = data;
	nodeTemp->next = node;
	return nodeTemp;
}

/**
 * This function add a Node to our Linked List.
 */
void add(int data) {
	if (size == 0) {
		tail = newNode(NULL, data);
		middle = tail;
	}
	else {
		Node* nodeTemp = newNode(NULL, data);
		tail->next = nodeTemp;
		tail = nodeTemp;
	}
	size++;
}

/**
 * The function take add a new Node to our Linked List and return the element in the middle of the Linked List.
 */
int take(int newData) {
	add(newData);
	if (size % 2 == 0)
		middle = middle->next;
	return middle->data;
}

/**
 * The main class for the test.
 */
int main() {
	puts("Welcome !");
	printf("%d\n", take(20));
	printf("%d\n", take(10));
	printf("%d\n", take(30));
	printf("%d\n", take(5));
	printf("%d\n", take(40));
	return 0;
}

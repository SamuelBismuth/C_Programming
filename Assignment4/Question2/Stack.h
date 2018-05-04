/*
 * Stack.h
 *
 *  Created on: Dec 17, 2017
 *      Author: samuel
 */

typedef struct Node {
	struct Node* next;
	struct Node* prev;
	int data;
} Node;

Node* newNode(int data);
void push(int data);
int pop();
int sizeStack();


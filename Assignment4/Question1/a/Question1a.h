/*
 * Question1a.h
 *
 *  Created on: Jan 7, 2018
 *      Author: samuel
 */

/**
 * The structure Node.
 */
typedef struct Node {
	struct Node* next;
	int data;
} Node;

Node* newNode(Node* node, int data);
void add(int data);
int take(int newData);

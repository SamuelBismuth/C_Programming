/*
 * Question1b.h
 *
 *  Created on: Jan 7, 2018
 *      Author: samuel
 */

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
	int place;
} Node;

Node* newNode(int data);
void add(Node* node);
void updatePlaces(Node* tmp);
void updateMedian();
int take(int num);

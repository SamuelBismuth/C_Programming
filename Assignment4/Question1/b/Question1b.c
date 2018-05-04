/*
 ============================================================================
 Name        : Question1b.c
 Author      : Samuel
 Version     :
 Copyright   : public
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/**
 * Includes.
 */
#include <stdlib.h>
#include <stdio.h>

#include "Question1b.h"

/**
 * Define the head, the median and the size of the Linked List.
 */
Node* head;
Node* median;
int size = 0;

/**
 * This function define a new Node.
 */
Node* newNode(int data) {
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->place = 0;
	return node;
}

/**
 * This function add a Node to our Linked List.
 */
void add(Node* node) {
	if (size == 0) {
		head=node;
		median = node;
		median->place = 1;
		size=1;
		return;
	}
	Node* temp = head;
	if (temp->data > node->data) {
		node->next = head;
		head->prev = node;
		head = node;
		size++;
		updatePlaces(head);
		updateMedian();
	}
	else {
		while(temp->next != NULL) {
			if(node->data > temp->next->data)
				temp = temp->next;
			else {
				node->next = temp->next;
				node->prev = temp;
				temp->next->prev = node;
				temp->next = node;
				break;
			}
		}
		if (temp->next == NULL) {
			temp->next = node;
			node->prev = temp;
		}
		size++;
		node->place = temp->place++;
		updatePlaces(temp);
		updateMedian();
	}
}

/**
 * This function updtae the place of all the elements of the Linked List.
 */
void updatePlaces(Node* temp) {
	if (temp != head)
		temp = temp->next->next;
	while (temp != NULL) {
		temp->place++;
		temp = temp->next;
	}
}

/**
 * This method update the place of the median.
 */
void updateMedian() {
	if(size % 2 == 0 && median->place > size / 2)
		median = median->prev;
	if(size % 2 == 1 && median->place < size / 2 + 1)
		median = median->next;
}

/**
 * The function take add a new Node to our Linked List and return the element in the median of the Linked List.
 */
int take(int num) {
	Node* node = newNode(num);
	add(node);
	return median->data;
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

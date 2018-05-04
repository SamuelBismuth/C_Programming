/*
 * StackUndo.h
 *
 *  Created on: Dec 17, 2017
 *      Author: samuel
 */

/**
 * Global stack undo.
 */
struct StackUndo stackUndo;

int isFullUndo(struct StackUndo* stackUndo);
int isEmptyUndo(struct StackUndo* stackUndo);
void pushUndo(struct StackUndo* stackUndo, int item);
int popUndo(struct StackUndo* stackUndo);
int sizeUndo(struct StackUndo* stackUndo);

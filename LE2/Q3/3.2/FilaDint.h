#ifndef FILADINT_H_INCLUDED
#define FILADINT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int* dataPtr;
	struct node* next;
}QUEUE_NODE;

typedef struct queue{
	QUEUE_NODE* front;
	QUEUE_NODE* rear;
	int count;
}QUEUE_H;

QUEUE_H* createQueue();
QUEUE_H* destroyQueue(QUEUE_H* queue);

bool enqueue (QUEUE_H* queue, int** itemPtr);
bool dequeue (QUEUE_H* queue, int** itemPtr);
bool queueFront (QUEUE_H* queue, int** itemPtr);
bool queueRear (QUEUE_H* queue, int** itemPtr);
int queueCount (QUEUE_H* queue);

bool emptyQueue (QUEUE_H* queue);
bool fullQueue (QUEUE_H* queue);

#endif


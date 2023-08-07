#ifndef FILAESINT_H_INCLUDED
#define FIlAESINT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 30

typedef struct queue_header{
	int rear,front;
	int dados[MAX];
}queue;

queue* createQueue();
bool enqueue(queue* fila, int dado);
int dequeue(queue* fila);
int queueFront (queue* fila);
int queueRear (queue* fila);
int queueCount (queue* fila);

bool queueEmpty (queue* fila);
bool queueFull(queue* fila);

void destroyQueue (queue* fila);

#endif

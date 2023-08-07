#include "FilaDint.h"

QUEUE_H* createQueue(){
	QUEUE_H* queue;
	
	queue = (QUEUE_H*)malloc(sizeof(QUEUE_H));
	if(queue){
		queue->front = NULL;
		queue->rear = NULL;
		queue->count = 0;
	}
	return queue;
}

bool enqueue (QUEUE_H* queue, int** itemPtr){
	QUEUE_NODE* newNode;
	
	if(!(newNode = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE)))){
		return false;
	}
	newNode->dataPtr = *itemPtr;
	newNode->next = NULL;
	
	if(queue->count == 0){
		queue->front = newNode;
	}else{
		queue->rear->next = newNode;
	}
	(queue->count)++;
	queue->rear = newNode;
	return true;
}

bool dequeue (QUEUE_H* queue, int** itemPtr){
	QUEUE_NODE* deleteNode;
	
	if(!queue->count){
		return false;
	}else{
		*itemPtr = queue->front->dataPtr;
		deleteNode = queue->front;
	}
	if(queue->count == 1){
		queue->front = queue->rear = NULL;
	}else{
		queue->front = queue->front->next;
	}
	(queue->count)--;
	free(deleteNode);
	
	return true;
}

bool queueFront (QUEUE_H* queue, int** itemPtr){
	
	if(!queue->count){
		return false;
	}else{
		*itemPtr = queue->front->dataPtr;
	}
	return true;
}

bool queueRear (QUEUE_H* queue, int** itemPtr){
	
	if(!queue->count){
		return false;
	}else{
		*itemPtr = queue->rear->dataPtr;
	}
	return true;
}

int queueCount(QUEUE_H* queue){
	return queue->count;
}

bool emptyQueue(QUEUE_H* queue){
	return(queue->count == 0);
}

bool fullQueue (QUEUE_H* queue){
	QUEUE_NODE* temp;
	
	if(!(temp = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE)))){
		return true;
	}
	free (temp);
	return false;
}

QUEUE_H* destroyQueue (QUEUE_H* queue){
	QUEUE_NODE* deleteQueue;
	
	if(queue){
		while (queue->front != NULL){
			free(queue->front->dataPtr);
			deleteQueue = queue->front;
			queue->front = queue->front->next;
			free(deleteQueue);
		}
		free(queue);
	}
	return NULL;
}

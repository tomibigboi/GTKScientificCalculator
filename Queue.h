
#include "stdbool.h"
// C Program to demonstrate how to Implement a queue
#define MAX_SIZE 100

#ifndef QUEUE_H

#define QUEUE_H
// Defining the Queue structure
typedef struct Queue{
    char items[MAX_SIZE][255];
    int front;
    int rear;
} Queue;


void initializeQueue(Queue* q);
bool isQueueEmpty(Queue* q);
bool isQueueFull(Queue* q);
void enqueue(Queue* q, char *value);
void dequeue(Queue* q);
char *QueuePeek(Queue* q);
void printQueue(Queue* q);
char *StringQueue(Queue* q);

#endif // QUEUE_H

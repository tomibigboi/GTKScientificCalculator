#include <stdbool.h>
#include "stdio.h"
#include "string.h"
#include "Queue.h"


// Function to initialize the queue
void initializeQueue(Queue* q)
{
    q->front = -1;
    q->rear = 0;
}

// Function to check if the queue is empty
bool isQueueEmpty(Queue* q) 
{ return (q->front == q->rear - 1); }

// Function to check if the queue is full
bool isQueueFull(Queue* q) 
{ return (q->rear == MAX_SIZE); }

// Function to add an element to the queue (Enqueue operation)
void enqueue(Queue* q, char *value)
{
    if (isQueueFull(q)) {
        printf("Queue is full\n");
        return;
    }
    strcpy(q->items[q->rear],value);
    q->rear++;
}

// Function to remove an element from the queue (Dequeue
// operation)
void dequeue(Queue* q)
{
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    q->front++;
}

// Function to get the element at the front of the queue
// (QueuePeek operation)
char *QueuePeek(Queue* q)
{
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return "\0"; // return some default value or handle
                   // error differently
    }
    return q->items[q->front + 1];
}

// Function to print the current queue
void printQueue(Queue* q)
{
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Current Queue: ");
    for (int i = q->front + 1; i < q->rear; i++) {
        printf("%s ", q->items[i]);
    }
    printf("\n");
}

char *StringQueue(Queue* q)
{
    static char temp[255];
    if (isQueueEmpty(q)) {
        return "";
    }
    int SpaceChech = 0;
    int j = 0;
    for (int i = q->front + 1; i < q->rear; i++) {
        //temp[j] = q->items[i];
        strcat(temp,q->items[i]);
        strcat(temp," ");
        j++;
    }
    return temp;
}
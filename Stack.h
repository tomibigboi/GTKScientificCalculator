// Define the maximim capacity of the stack
#define MAX_SIZE 100


#ifndef Stack_H

#define Stack_H


// Define a structure for the stack
typedef struct {
    // Array to store stack elements
    char arr[MAX_SIZE];  
    // Index of the top element in the stack
    char top;        
} Stack;


void initializeStack(Stack *stack); 
bool isStackEmpty(Stack *stack); 
bool isStackFull(Stack *stack);
void push(Stack *stack, char value); 
char pop(Stack *stack);
char StackPeek(Stack *stack);


#endif
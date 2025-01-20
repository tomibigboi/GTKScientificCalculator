#include <stdbool.h>
#include "stdio.h"
#include "Stack.h"



// Function to initializeStack the stack
void initializeStack(Stack *stack) 
{
    // Set top index to -1 to indicate an empty stack
    stack->top = -1;  
}

// Function to check if the stack is empty
bool isStackEmpty(Stack *stack) 
{
    // If top is -1, the stack is empty
    return stack->top == -1;  
}

// Function to check if the stack is full
bool isStackFull(Stack *stack) 
{
    // If top is MAX_SIZE - 1, the stack is full
    return stack->top == MAX_SIZE - 1;  
}

// Function to push an element onto the stack
void push(Stack *stack, char value) 
{
    // Check for stack overflow
    if (isStackFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    // Increment top and add the value to the top of the stack
    stack->arr[++stack->top] = value;
    printf("Pushed %c onto the stack\n", value);
}

// Function to pop an element from the stack
char pop(Stack *stack) 
{
    // Check for stack underflow
    if (isStackEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    // Return the top element 
    char popped = stack->arr[stack->top];
    // decrement top pointer
    stack->top--;
    printf("Popped %c from the stack\n", popped);
    // return the popped element
    return popped;
}

// Function to StackPeek the top element of the stack
char StackPeek(Stack *stack) 
{
    // Check if the stack is empty
    if (isStackEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    // Return the top element without removing it
    return stack->arr[stack->top];
}

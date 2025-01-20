
#include <stdbool.h>
#include "ctype.h"
#include "string.h"
#include "Stack.h"
#include "Queue.h"
#include "ShuntingYard.h"
#include "Checks.h"

int getPrecedence(char x)
{
  if (x == '+' || x == '-')
    return 1;
  else if (x == '*' || x == '/')
    return 2;
  else if (x == '^' || IsFloatOperator(x))
    return 3;
  else
    return -1;
}

bool hasLeftAssociativity(char x) 
{
  if (x == '+' || x == '-' || x == '/' || x == '*') {
    return true;
  } else {
    return false;
  }
}


Queue ShuntingYard(char tokens[255][255], int tokensize)
{
  //int tokensize = strlen(tokens);
  int i = 0;
  Queue q;
  initializeQueue(&q);
  Stack s;
  initializeStack(&s);
  char c[255];
  strcpy(c,tokens[i]);
  char tempstring[10];
  while (i < tokensize)
  {
    //c = tokens[i];
    strcpy(c,tokens[i]);
    if (IsNumber(c))
    {
      enqueue(&q,c);
    }
    else if (isOperator(c))
    {
      while ((!isStackEmpty(&s))&&(getPrecedence(c[0])<=getPrecedence(StackPeek(&s)))&&(hasLeftAssociativity(c[0])))
      {
        tempstring[0] = pop(&s);
        tempstring[1] = '\0'; 
        enqueue(&q,tempstring);
      }
      push(&s,c[0]);
    }
    else if (c[0] == '(')
    {
      push(&s,c[0]);
    }
    else if (c[0] == ')')
    {
      while (!isStackEmpty(&s)&& StackPeek(&s) != '(')
      {
        tempstring[0] = pop(&s);
        tempstring[1] = '\0'; 
        enqueue(&q,tempstring);
        //enqueue(&q,pop(&s));
      }
      pop(&s);
    }
    i++;
  }

  while (!isStackEmpty(&s)) 
  {
    if (StackPeek(&s) == '(')
    {
      return q;
    }
    tempstring[0] = pop(&s);
    tempstring[1] = '\0'; 
    enqueue(&q,tempstring);
    //enqueue(&q,pop(&s));
  }
  //printQueue(&q);
  return q;
}

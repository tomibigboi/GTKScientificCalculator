//CalculationCall.c
#include "CalculationCall.h"
#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "ctype.h"
#include "Checks.h"
#include "ShuntingYard.h"
#include "Queue.h"
#include "ExpressionTree.h"
#include "EvaluationOfTree.h"



char* CalculationCall(char tokens[255][255])
{
  //char tokens[255][255] = {"1","l","5","+","5"};

  // Initialize a counter
  int numElements = 0;

  // Loop through the array to count initialized elements
  for (int i = 0; i < 255; i++) {
    if (strlen(tokens[i]) == 0) {
      
      break; // Stop counting when an empty string is found
    }
    numElements++;
  }

  Queue q = ShuntingYard(tokens,numElements);
  ANode *x = makeExpressionTree(&q);
  //printf("\n////%s\\\\",eval(x));
  return eval(x);
}
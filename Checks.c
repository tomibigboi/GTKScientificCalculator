#include <stdbool.h>
#include "string.h"
#include "ctype.h"
#include "Checks.h"
#include "math.h"


//exp : x
//sin : i
//modulo : m

#define MaxOperators 16
#define MaxOperatorLength 8
#define MaxFloatOperator 8

char OperatorsList[MaxOperators][MaxOperatorLength] = {"*","+","-","/","%","^","s","l","e","x","c","i","t","m","!"};
char FloatOperators[MaxFloatOperator] = {'s','l','e','x','c','i','t','m'};

bool isOperator(char *s)
{
    char x = s[0];
    for (int i = 0; i < MaxOperators ; i++)
    {
        if (x == OperatorsList[i][0])
        {
            return true;
        }
    }
    return false;
}


bool IsNumber(char *x)
{
    for (int i = 0; i < strlen(x); i++)
    {
        if (!(isdigit(x[i]))&&x[i] != '.')
        {
            return false;
        }
    }
    return true;
}


bool IsDecimal(char *x)
{
    for (int i = 0; i < strlen(x); i++)
    {
        if (x[i] == '.')
        {
            return false;
        }
    }
    return true;
}


bool IsFloatOperator(char x)
{
    for (int i = 0 ; i < MaxFloatOperator ; i++)
    {
        if (x == FloatOperators[i])
        {
            return true;
        }
    }
    return false;
}





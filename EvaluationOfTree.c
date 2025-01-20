#include "EvaluationOfTree.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "math.h"
#include "Checks.h"
#include "stdio.h"

// Utility function to return the integer value 
// of a given string 
int toInt(char* s) 
{ 
	int num = 0; 
	
	// Check if the integral value is 
	// negative or not 
	// If it is not negative, generate the number 
	// normally 
	if(s[0]!='-') 
	{
		for (int i=0; i<strlen(s); i++) 
			num = num*10 + ((int)(s[i])-48); 

	}
	// If it is negative, calculate the +ve number 
	// first ignoring the sign and invert the 
	// sign at the end 
	else
	{ 
	for (int i=1; i<strlen(s); i++) 
		num = num*10 + ((int)(s[i])-48); 
	num = num*-1; 
	} 
	
	return num; 
}

float toFloat(char *s)
{
    char *endptr; // Pointer to track the end of the conversion
    float number;

    // Convert string to float
    number = strtof(s, &endptr);

    // Check for conversion errors
    if (endptr == s) {
        //printf("Conversion error: No digits were found.\n");
		return -1;
    } 
	else {
        //printf("The float representation of the string \"%s\" is: %f\n", s, number);
		return number;
    }
}


int power(int l_val,int r_val)
{
	if (r_val == 0)
		return 1;
	else if (r_val == 1)
		return l_val;
	return l_val * power(l_val,r_val-1);
}

float Floatpower(int l_val,int r_val)
{
	if (r_val == 0)
		return 1;
	else if (r_val == 1)
		return l_val;
	return l_val * power(l_val,r_val-1);
}


int fact(int x)
{
	if ((x == 1)||(x == 0))
	{
		return fact(x-1)*x;
	}
}




int DecimalCalculations(char *l_val,char *r_val,char *operator)
{
	int Dl_val = toInt(l_val);
	int Dr_val = toInt(r_val);
	// Check which operator to apply 
	if (operator[0]=='+') 
		return Dl_val+Dr_val; 
	if (operator[0]=='-') 
		return Dl_val-Dr_val;
	if (operator[0]=='*') 
		return Dl_val*Dr_val;
	if (operator[0]=='^')
		return power(Dl_val,Dr_val);
	if (operator[0] == '/')
	{
		if (l_val[0] == '0')
		{
			return -1;
		}
		return Dl_val/Dr_val; 
	}
	if (operator[0]=='!')
	{
		return fact(Dr_val);
	}
	
}

float EXP10(float x)
{
	if (x == 1)
	{
		return 10;
	}
	else
	{
		return EXP10(x-1)*10;
	}
}

float FloatCalculations(char *l_val,char *r_val,char *operator)
{
	float Dl_val = toFloat(l_val);
	float Dr_val = toFloat(r_val);
	// Check which operator to apply 
	if (operator[0]=='+') 
		return Dl_val+Dr_val; 
	if (operator[0]=='-') 
		return Dl_val-Dr_val;
	if (operator[0]=='*') 
		return Dl_val*Dr_val;
	if (operator[0]=='^')
		return Floatpower(Dl_val,Dr_val);
	if (operator[0] == '/')
	{
		if (l_val[0] == '0')
		{
			return -1;
		}
		return Dl_val/Dr_val; 
	}
	if (operator[0]=='s')
	{
		return sqrt(Dr_val);
	}
	if (operator[0]=='l')
	{
		return  log(Dr_val);
	}
	if (operator[0]=='e')
	{
		return exp(Dr_val);
	}
	if (operator[0]=='x')
	{
		return EXP10(Dr_val);
	}
	if (operator[0]=='c')
	{
		return cos(Dr_val);
	}
	if (operator[0]=='i')
	{
		return sin(Dr_val);
	}
	if (operator[0]=='t')
	{
		return tan(Dr_val);
	}
	if (operator[0]=='!')
	{
		return fact(Dr_val);
	}
}

// This function receives a node of the syntax tree 
// and recursively evaluates it 
char *eval(ANode* root) 
{
	// empty tree 
	if (!root) 
		return "\0"; 


	// leaf node i.e, an integer 
	if (!root->left && !root->right) 
	{
		return root->data; 
	}

	// Evaluate left subtree 
	char *l_val = eval(root->left); 

	//
	// Evaluate right subtree 
	char *r_val = eval(root->right);
	
	if (!IsDecimal(r_val) || !IsDecimal(l_val) || IsFloatOperator(root->data[0]))
	{
		float Result = FloatCalculations(l_val,r_val,root->data);
		static char str[20]; // Buffer to hold the resulting string
		sprintf(str, "%.2f", Result); // Convert float to string
		printf("\n**%.2f**",Result);
		return str;
	}
	else
	{
		int Result = DecimalCalculations(l_val,r_val,root->data);
		static char str[20]; // Buffer to hold the resulting string
		sprintf(str, "%d", Result); // Convert int to string
		printf("\n %s",str);
		return str;
	}

	
} 



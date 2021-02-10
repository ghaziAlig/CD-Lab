/*
Q3: Write a C program to display the operator name of a given input.
*/

#include <stdio.h>
#include <string.h>

void main() {
	char operator;
	printf("\nEnter the operator=>  ");
	scanf("%c",&operator);

	if (operator == '+')
	{
		printf("\nThe input operator is=> 'Addition Operator'\n");
	}

	else if (operator == '-')
	{
		printf("\nThe input operator is=> 'Subtraction Operator'\n");
	}

	else if (operator == '*')
	{
		printf("\nThe input operator is=> 'Multipication Operator'\n");
	}

	else if (operator == '/')
	{
		printf("\nThe input operator is=> 'Division Operator'\n");
	}

	else if (operator == '%')
	{
		printf("\nThe input operator is=> 'Modulus Operator'\n");
	}

	else if (operator == '=')
	{
		printf("\nThe input operator is=> 'Simple Assignment Operator\n");
	}

	else
		printf("\nUnidentified Operator\n");
}
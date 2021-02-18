/*
Write a C programme to identify whether a given constant is 
integer constant or real constant.
*/


#include <stdio.h>
#include <string.h>

int main()
{
	char constant[10];
	int flag = 0, length;

	printf("\nEnter a number=>   ");
	scanf("%s", constant);
	length = strlen(constant);

	while(length--)
	{
		if (constant[length] == '.')
		{
			flag = 1;
			break;
		}
	}

	if (flag)
		printf("\nThe given number is a 'Real Constant'\n\n");

	else
		printf("\nThe given number is an 'Integer'\n\n");

	return 0;
}
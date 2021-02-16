/*
Q2: Write a C program to display whether the givern input is keyword or not.
*/

#include <stdio.h>
#include <string.h>

void main()
{
	int i, flag=0;
	char string[10];

//Array declaration for keywords	
	char keywords[32][10]={	"auto","double","int","struct","break","else","long",
							"switch","case","enum","register","typedef","char",
      						"extern","return","union","const","float","short",
      						"unsigned","continue","for","signed","void","default",
     	 					"goto","sizeof","volatile","do","if","static","while"} ;
                            

//Taking input
    printf("\nEnter the string that you want to check=>  ");
    // gets(string, 10, stdin);
    scanf("%s", string);
    printf("\nEntered string is=>  %s\n", string);


//Check whether the input is keyword or not



    for (int i = 0; i <32; ++i)
    {
    	if (strcmp(string,keywords[i])==0)
    		flag = 1;
    }

    if (flag == 1)
    	printf("\nThe given string '%s' is a keyword.\n", string);
		
    else
    	printf("\nThe given string '%s' is not a keyword.\n", string);
}
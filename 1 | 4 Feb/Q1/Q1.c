/*
Q1: Write a program to derive the predictive parse table.
*/


#include <stdio.h>
#include <ctype.h>
void main()    
{
	int no_of_characters = 0, no_of_digits = 0, no_of_whitespaces = 0, no_of_lines = 0, no_of_specialcharacters = 0, no_of_alphabets = 0;

	printf("\n########## The contents of the file are ##########\n\n");

	FILE *fp ;  
	char ch ;  
	fp = fopen("file.txt","r") ;  
	while ( 1 )  
	{  
		ch = fgetc (fp) ;
		
		if (isdigit(ch)!=0) {
		 	no_of_digits++;
		}
		
		if (ch==' ') {
		 	no_of_whitespaces++;
		}

		if (ch=='\n') {
			no_of_lines++;
		}
		
		if (isdigit(ch)==0 && isalpha(ch)==0 && ch!=' ' && ch!='\n') {
			no_of_specialcharacters++;
		}
		
		if (isalpha(ch)!=0) {
			no_of_alphabets++;
		}
		
		if ( ch == EOF )  
			break ;  
		
		printf("%c",ch) ;
		
		no_of_characters++; 
	}  
	fclose (fp ) ;

	printf("\n\n##################################################\n\n");
	

	printf("\n\na) Number of characters=          %d\n",no_of_characters);
	
	printf("b) Number of digits=              %d\n",no_of_digits);
	
	printf("c) Number of spaces=              %d\n",no_of_whitespaces);
	
	printf("d) Number of lines=               %d\n",no_of_lines);
	
	printf("e) Number of special characters=  %d\n",no_of_specialcharacters);
	
	printf("f) Number of alphabets=           %d\n",no_of_alphabets);
}
/*
Write a C program to implement Lexical Analyzer.
*/


#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void openingMessage()
{
    printf("\n#$#$#$#$#$#$#$#$#$#$#$#$#$#$  LEXICAL  ANALYSER  $#$#$#$#$#$#$#$#$#$#$#$#$#$#\n\n");
}

void closingMessage()
{
    printf("\n\n#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$  THANK YOU  $#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#\n\n");
}

// Check if the character is a delimiter
bool delimiter(char ch)
{
    if (ch == '+' || ch == '-' ||
        ch == '*' || ch == '/' ||
        ch == ' ' || ch == '>' ||
        ch == '<' || ch == '=' ||
        ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' ||
        ch == '{' || ch == '}' ||
        ch == ',' || ch == ';')
        return (true);
    return (false);
}

// Check if the character is an operator
bool operator(char ch)
{
    if (ch == '+' || ch == '-' 
    	|| ch == '*' || ch == '/' 
    	|| ch == '>' || ch == '<' 
    	|| ch == '=')
        return (true);
    return (false);
}

// Check if the string is a keyword
bool keyword(char* str)
{
    if (!strcmp(str, "auto") || !strcmp(str, "break")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "const") || !strcmp(str, "continue")
        || !strcmp(str, "default") || !strcmp(str, "do")
        || !strcmp(str, "double") || !strcmp(str, "else")
        || !strcmp(str, "enum") || !strcmp(str, "extern")
        || !strcmp(str, "float") || !strcmp(str, "for")
        || !strcmp(str, "goto") || !strcmp(str, "if")
        || !strcmp(str, "int") || !strcmp(str, "long")
        || !strcmp(str, "register") || !strcmp(str, "return")
        || !strcmp(str, "short") || !strcmp(str, "signed")
        || !strcmp(str, "sizeof") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "switch")
        || !strcmp(str, "typedef") || !strcmp(str, "union")
        || !strcmp(str, "unsigned") || !strcmp(str, "void")
        || !strcmp(str, "volatile") || !strcmp(str, "while") )
        return (true);
    return (false);
}

// Check if the string is an intrger
bool isInteger(char* str)
{
    int i, len = strlen(str);

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1'
            && str[i] != '2' && str[i] != '3'
            && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7'
            && str[i] != '8' && str[i] != '9'
            || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

// Check if the string is a real constant
bool isRealNumber(char* str)
{
    int i, len = strlen(str);
    bool hasDecimal = false;

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' 
        	&& str[i] != '2' && str[i] != '3' 
        	&& str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' 
            && str[i] != '8' && str[i] != '9' 
            && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}

// Check if the string is identifier
bool identifier(char* str)
{
    if (str[0] == '0' || str[0] == '1' 
    	|| str[0] == '2' || str[0] == '3' 
    	|| str[0] == '4' || str[0] == '5' 
    	|| str[0] == '6' || str[0] == '7' 
    	|| str[0] == '8' || str[0] == '9' 
    	|| delimiter(str[0]) == true)
        return (false);
    return (true);
}

// Break the string into substring
char* subString(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(
            sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

// Analyse the input strings
void analyse(char* str)
{
    int left = 0, right = 0;
    int len = strlen(str);

    printf("\n\n");

    while (right <= len && left <= right) {
        if (delimiter(str[right]) == false)
            right++;

        if (delimiter(str[right]) == true && left == right) {
            if (operator(str[right]) == true)
                printf("'%c' is an 'OPERATOR'\n", str[right]);

            right++;
            left = right;
        } 
        else if (delimiter(str[right]) == true && left != right
                   || (right == len && left != right)) {
            char* subStr = subString(str, left, right - 1);

            if (keyword(subStr) == true)
                printf("'%s' is a 'KEYWORD'\n", subStr);

            else if (isInteger(subStr) == true)
                printf("'%s' is an 'INTEGER CONSTANT'\n", subStr);

            else if (isRealNumber(subStr) == true)
                printf("'%s' is a 'REAL CONSTANT'\n", subStr);

            else if (identifier(subStr) == true
                     && delimiter(str[right - 1]) == false)
                printf("'%s' is an 'IDENTIFIER'\n", subStr);

            else if (identifier(subStr) == false
                     && delimiter(str[right - 1]) == false)
                printf("'%s' is not a 'VALID IDENTIFIER'\n", subStr);
            left = right;
        }
    }
    return;
}

// Main Function
void main()
{
    openingMessage();

    char str[500];

    FILE *fptr;

    char filename[100], c;

    printf("Enter the name of the file for lexical analysis==>>   ");
    scanf("%s", filename);

    // Open file
    fptr = fopen(filename, "r");

/*    printf("Enter a string to perform lexical analysis==>>   ");
    scanf("%[^\n]%*c", str);*/

    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }


    // Read contents from file
/*    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }*/

    c = fgetc(fptr);
    while (c != EOF)
    {
        fscanf(fptr, "%s", str);

        analyse(str);

        c = fgetc(fptr);
    }    


//    analyse(str); // calling the analyse function

/*    printf("\n\nDo you want to run the program again???\nPress '1' for yes, any other key to exit.");
    int ch;
    scanf("%d", &ch);

    switch (ch) {
        case 1: main();
            break;
        default: closingMessage();
            break;
    }*/

    fclose(fptr);

    closingMessage();

}
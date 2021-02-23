/*
Write a C program to identify whether the
given string is identifier or not.
*/


#include <stdio.h>
#include <ctype.h>

int main()
{
    int count=0, k;
    char str[20], ch;

    printf("\nEnter a string=>   ");
    scanf("%s", str);
    ch = str[0];

    k = isalpha(ch) || ch == 95;
    if (k)
    {
        count++;

        for (int i=1; str[i] != '\0'; ++i)
        {
            if (isalnum(str[i]) || ch==95)
            {
                count++;
            }
        }

    }

    if (count > 0)
        printf("\nThe entered string is an 'identifier'\n\n");
    else
        printf("\nThe entered string is not an 'identifier'\n\n");

    return 0;
}
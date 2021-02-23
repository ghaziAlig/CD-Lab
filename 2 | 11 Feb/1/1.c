/*
Write a C program to check whether the given
string is accepted by given DFA or not.
*/


#include <stdio.h>

int main()
{
    int state=0;
    char str[20], ch;

    printf("\nEnter a string beginning with 10 =>   ");
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; ++i)
    {
        ch = str[i];
        switch(state)
        {
            case 0:
            {
                if (ch == '1')
                    state = 1;
                else
                    state = 3;
                break;
            }
            case 1:
            {
                if (ch == '0')
                    state = 2;
                else
                    state = 3;
                break;
            }
            case 2:
            {
                state = 2;
                break;
            }
            case 3:
            {
                printf("\n\nThe DFA has gone into dead state.\n");
                break;
            }
        }
    }

    if (state == 2)
        printf("\nThe given string is accepted by the DFA and state = %d\n\n", state);
    else
        printf("\nThe given string is not accepted by the DFA and it ended with state = %d\n\n", state);

    return 0;
}
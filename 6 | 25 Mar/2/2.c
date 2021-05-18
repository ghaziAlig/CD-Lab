/*
Q2	Write a program to check whether a given string belongs to operator grammar or not.
*/


#include<stdio.h>

void f()
{
    printf("\nGiven grammar is not Operator grammar .");
}
void main()
{
    char grm[20][20], c;
    int i, n, j = 2, flag = 0;
    printf("Enter the number of production :");
    scanf("%d", &n);
    printf("The grammer is :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", grm[i]);
    }
    for (i = 0; i < n; i++)
    {
        c = grm[i][2];
        while (c != '\0'){
            if (grm[i][3] == '+' || grm[i][3] == '-'
                || grm[i][3] == '*' || grm[i][3] == '/')
                flag = 1;
            else
            {
                flag = 0;
                f();
            }
            if (c == '$')
            {
                flag = 0;
                f();
            }
            c = grm[i][++j];
        }
    }
    if (flag == 1)
        printf("\nGiven grammar is an Operator grammar .");
}

#include <stdio.h>
#include <stdlib.h>

//global variables 
char game[3][3];
int l, c;

void initializeMatrix();
void print();

int main(void)
{
    initializeMatrix();
    print();
    return (0);
}

 void initializeMatrix()
{
    l = 0;
    while (l < 3)
    {
        c = 0;
        while(c < 3)
        {
            game[l][c] = ' ';
            c++;
        }
        l++;
    }
}

void print()
{
    printf("\n\n\t\t 0   1   2\n\n");
    l = 0;
    while(l < 3)
    {
        c = 0;
        while(c < 3)
        {
            if (c == 0)
                printf("\t\t");
            printf(" %c ", game[l][c]);
            if (c < 2)
                printf("|");
            if (c == 2)
                printf("   %d", l);
            c++;
        }
        printf("\n");
        if(l < 2)
            printf("\t\t-----------\n");
        l++;
    }
}

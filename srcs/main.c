#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//global variables 
char game[3][3];
int l, c;

void ft_initializeMatrix();
void ft_print();

//Win lines
int ft_winLine(int l, char ch);
int ft_winLines(char ch);

int ft_winColumn(int c, char j);
int ft_winColumns(char j);

int ft_winDiagonalF(char c);
int ft_winDiagonalS(char c);

//check
int ft_validate(int l, int c);
void ft_readPositions(char j);
void ft_playing();
int ft_freeElements();

int main(void)
{
    int opcao;

    //open the title
    FILE *ptr;
    char ch;
    ptr = fopen("nameTitle.txt", "r");
    if (NULL == ptr) {
        printf("File can't be opened \n");
    }
    do {
        ch = fgetc(ptr);
        printf("%c", ch);
    } while (ch != EOF);
    fclose(ptr);

    // initialize game
    do {
        ft_initializeMatrix();
        ft_playing();

        printf("\nPress/Enter 1 to play again! \n");
        scanf("%d", &opcao);
    }while(opcao == 1);

    return (0);
}

 void ft_initializeMatrix()
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

void ft_print()
{
    printf("\n");
    printf("\n\n\t 0   1   2\n\n");
    l = 0;
    while(l < 3)
    {
        c = 0;
        while(c < 3)
        {
            if (c == 0)
                printf("\t");
            printf(" %c ", game[l][c]);
            if (c < 2)
                printf("|");
            if (c == 2)
                printf("   %d", l);
            c++;
        }
        printf("\n");
        if(l < 2)
            printf("\t-----------\n");
        l++;
    }
    printf("\n\n");
}

int ft_winLine(int l, char ch)
{
    if (game[l][0] == ch && game[l][1] == ch && game[l][2] == ch)
        return (1);
    else
        return (0);
}

int ft_winLines(char ch)
{
    int win = 0;

    l = 0;
    while (l < 3) //check three lines of the matrix
    {
        win += ft_winLine(l, ch);    
        l++;
    }
    return (win);
}

int ft_winColumn(int c, char j)
{
    if (game[0][c] == j  && game[1][c] == j && game[2][c] == j)
        return (1);
    else
        return (0);
}

int ft_winColumns(char j)
{
    int win = 0;

    c = 0;
    while(c < 3)
    {
        win += ft_winColumn(c, j);
        c++;
    }
    return (win);
}

int ft_winDiagonalF(char c)
{
    if (game[0][0] == c && game[1][1] == c && game[2][2] == c)
        return (1);
    else
        return (0);
}

int ft_winDiagonalS(char c)
{
if (game[0][2] == c && game[1][1] == c && game[2][0] == c)
        return (1);
    else
        return (0);
}

int ft_validate(int l, int c)
{
    if (l >= 0 && l < 3 && c >= 0 && c < 3 && game[l][c] == ' ')
        return(1);
    else
        return(0);
}

void ft_readPositions(char j)
{
    int line, column;

    printf("Press/Enter the position of a row and a column: ");
    scanf(" %d%d", &line, &column);

    while(ft_validate(line, column) == 0)
    {
        printf("Invalid coordinates! Press/Enter another: ");
        scanf(" %d%d", &line, &column);
    }
    game[line][column] = j;
}

void ft_playing()
{
    int player = 1;
    int winX = 0, winO = 0;
    char play1 = 'X', play2 = 'O';

    do {
        ft_print();
        if (player == 1)
        {
            ft_readPositions(play1);
            player++;
            winX += ft_winLines(play1);
            winX += ft_winColumns(play1);
            winX += ft_winDiagonalF(play1);
            winX += ft_winDiagonalS(play1);   
        }
        else
        {
            ft_readPositions(play2);
            player = 1;
            winO += ft_winLines(play2);
            winO += ft_winColumns(play2);
            winO += ft_winDiagonalF(play2);
            winO += ft_winDiagonalS(play2);  
        }
    } while(winX == 0 && winO == 0 && ft_freeElements() > 0); //enquanto nao ganhar ira se repetir
    if (winO == 1)
        printf("\nCongratulations Player 2. You won! \n");
    else if (winX == 1)
        printf("\nCongratulations Player 1. You won! \n");
    else
        printf("\nNobody won!\n");
}

int ft_freeElements()
{
    int count = 0;

    l = 0;
    while(l < 3)
    {
        c = 0;
        while(c < 3)
        {
            if(game[l][c] == ' ')
                count++;
            c++;
        }
        l++;
    }
    return (count);
}

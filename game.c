#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void printboard();
void resetboard();
bool clear();
bool winner();
char play();
char computer_play();

const char PLAYER = 'X';
const char COMPUTER = 'Y';
char board [3][3];

int main (void)
{
    srand(time(0));
    resetboard();
    printboard();
    do
    {
        
            play();
            computer_play();
            printboard();
    
    } 
    while (clear() == true && winner() == false);

    winner();
}

void printboard()
{
     printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
     printf("_____|_____|______\n");
     printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
     printf("_____|_____|______\n");
     printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
     printf("     |     |    \n");
     printf("\n");

}

void resetboard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

bool clear()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return true;
            }
          
        }
    }
    return false;
}

char play()
{
    int x;
    int y;
    
       do
       {
       printf("Type Row Number [1-3]:  ");
       scanf("%i", &x);
       }while(x != 1 && x != 2 && x != 3);

       do
       {
       printf("Type Column Number [1-3]:  ");
       scanf("%i", &y);
       }while(y != 1 && y != 2 && y != 3);
       

      if (board[x - 1][y - 1] == ' ') 
        board[x - 1][y - 1] = PLAYER;  
    
    else
    {
        printf("Space is already occupied! Choose an open space.\n");
        return play();  
    }

    return PLAYER; 
}

char computer_play()
{
    int x;
    int y;

    if (clear() == false)
    {    
        return 1;
    }
    
    do
    {
        x = (rand() % 3) + 1;
        y = (rand() % 3) + 1;

    } while (board[x - 1][y - 1] != ' ');

    board[x - 1][y - 1] = COMPUTER;
    return COMPUTER;

}

bool winner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&  board[i][1] == board[i][2] && board [i][0] != ' ')
            {
                printf("%c IS THE WINNER!\n", board[i][0]);
                return 0;
            }
    }

    for (int i = 0; i < 1; i++)
    {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            {
                printf("%c IS THE WINNER!\n", board[0][i]);
                return 0;
            }
    }


    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '))
    {
        printf("%c IS THE WINNER!\n", board[0][0]);
        return 0;
    }

    if((board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
    {
        printf("%c IS THE WINNER!\n", board[1][3]);
        return 0;    
    }
    
    return false;
}


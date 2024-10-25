#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    srand(time(0));
    int value = (rand() % 100) + 1;
    int guess;

    do
    {
        printf("Guess the number: ");
        scanf("%i", &guess);
    
        if(guess > value)
            printf("The number is lower than your guess!\n");
        else if(guess < value)
            printf("The number is higher than your guess!\n");
        else if(guess == value)
            printf("Nice guess!\n");

    }
    while(guess != value);
}
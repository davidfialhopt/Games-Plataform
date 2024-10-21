#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

int main (void)
{
    resetboard();
    printboard();
    do
    {
        play();
        computer_play();
        printboard();
       
    } 
    while (clear() && winner() == false);

    winner();
}
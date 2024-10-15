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
        printboard();
       
    } 
    while (clear() && winner() == false);

    winner();
}
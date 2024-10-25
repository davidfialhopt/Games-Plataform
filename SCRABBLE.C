#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    const int x = 27;
    const int y = 20;

    char alphabet[x] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int score[x] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                    1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    char w1[y];
    char w2[y];

    printf("Word 1: ");
    scanf("%s", w1);

    printf("Word 2: ");
    scanf("%s", w2);

    int w1_length = strlen(w1);
    int w2_length = strlen(w2);

    int score1 = 0;
    int score2 = 0;

    for (int i = 0; i < w1_length; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (toupper(w1[i]) == alphabet[j])
            {
                score1 = score1 + score[j];
            }
        }
    }
    for (int i = 0; i < w2_length; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (toupper(w2[i]) == alphabet[j])
            {
                score2 = score2 + score[j];
            }
        }
    }

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

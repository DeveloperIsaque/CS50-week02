#include <cs50.h>
#include <stdio.h>
#include <string.h>


string judgment (string word[]);

int main (void)
{
    string player[2];
    player[0] = get_string("Player 1: ");
    player[1] = get_string("Player 2: ");

    string win = judgment(player);

    printf("%s\n", win);
}
//THE END----------------------------------------------------------------------------------------------------------------

string judgment (string word[]) {
    int number;
    int numbers[2];
    string result = 0;
    string score[7];
    score[0] = "aeilnorstuAEILNORSTU";
    score[1] = "dgDG";
    score[2] = "bcmpBCMP";
    score[3] = "fhvwyFHVWY";
    score[4] = "kK";
    score[5] = "jxJX";
    score[6] = "qzQZ";

    for(int i = 0; i < 2; i++)
    {
        for(int j =0, jj = strlen(word[i]); j < jj; j++ )
        {
            for(int k =0; k < 7; k++)
            {
                for(int l = 0, ll = strlen(score[k]); l < ll; l++ )
                {
                    if(word[i][j] == score[k][l])
                    {
                        if(k < 5)
                        {
                            number = number + k + 1;
                        }
                        if (k == 5)
                        {
                            number = number + 8;
                        }
                        if (k == 6)
                        {
                            number = number + 10;
                        }
                    }
                }
            }
        }
        numbers[i] = number;
        number = 0;
    }
    if(numbers[0] < numbers[1])
    {
        result = "Player 2 win!";
    }
    else
    {
        if(numbers[0] > numbers[1])
        {
            result = "Player 1 win!";
        }
        else
        {
            if(numbers[0] == numbers[1])
            {
                result = "Tie!";
            }
        }
    }

    return result;
}

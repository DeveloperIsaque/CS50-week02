#include <cs50.h>
#include <stdio.h>
#include <string.h>


int judgment (string word[]);

int main (void)
{
    string player[2];
    player[0] = get_string("Player01: ");
    player[1] = get_string("Player02: ");

    string win;
    win = judgment(player);

    printf("%s\n", win);
}
//THE END----------------------------------------------------------------------------------------------------------------

string judgment (string word[]) {
    int number;
    int numbers[2];
    string result = 0;
    string score[7];
    score[0] = "aeilnorstu";
    score[1] = "dg";
    score[2] = "bcmp";
    score[3] = "fhvwy";
    score[4] = "k";
    score[5] = "jx";
    score[6] = "qz";

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
    }
    if(numbers[0] < numbers[1])
    {
        result = "Player 2 win";
    }
    else
    {
        if(numbers[0] > numbers[1])
        {
            result = "Player 1 win";
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

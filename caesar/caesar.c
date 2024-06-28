#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int transforming (int length, string argv[1]);

int main(int argc, string argv[])
{
    int start = 1;
    int length = strlen(argv[1]);

    for(int i = 0; i < length; i++)
    {
        if(!isdigit(argv[1][i]) || argv[2] != NULL)
        {
            printf("Usage: ./caesar key\n");
            start = 0;
            return 1;
        }
    }

    if(start == 1)
    {
        int number = transforming (length, argv);
    }
    return 0;
}

int transforming (int length, string array[1])
{
    int number = 0;
    int base = 10;
    for(int i = 0; i < length; i++)
    {
        int exponent = length - i;
        number = number + (argv[1][i] * (pow(base, exponent)));
    }

    return number;
}

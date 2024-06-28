#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int transforming (int length, string argv[1]);
string encrypting (int number, string text);

int main(int argc, string argv[])
{
    int start = 1;
    int number = 0;
    int length = strlen(argv[1]);

    for(int i = 0; i < length; i++)
    {
        if(!isdigit(argv[1][i]) || argv[2] != NULL) // Preciso fazer funcionar se a pessoa só mandar ("./caesar")
        {
            printf("Usage: ./caesar key\n");
            start = 0;
            return 1;
        }
    }

    if(start == 1)
    {
        // Transforming into number
        number = transforming (length, argv);

        // getting the text
        string text = get_string("Your text: ");

        // encrypting
        text = encrypting (number, text);

        printf("ciphertext: %s\n", text);
    }
    return 0;
}

int transforming (int length, string array[1])
{
    int number = 0;
    for(int i = 0; i < length; i++)
    {
        number = number * 10 + (array[1][i] - '0');
    }

    while(number > 26)
    {
        number = number - 26;
    }
    return number;
}


string encrypting (int number, string text)
{
    int localization = 0;
    int transformation = 0;

    for(int i = 0, length = strlen(text); i < length; i++)
    {
        if(text[i] >= 'a' && text[i] <= 'z')
        {
            localization = text[i] - 'a';
            transformation = localization + number;
            while(transformation > 25)
            {
                transformation = transformation - 26;
            }
            text[i] = text[i] - localization + transformation;
        }
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            localization = text[i] - 'A';
            transformation = localization + number;
            while(transformation > 25)
            {
                transformation = transformation - 26;
            }
            text[i] = text[i] - localization + transformation;
        }
    }
    return text;
}

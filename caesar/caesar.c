#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    int start = 1;
    int length = strlen(argv[1]);
    int key[1][length];

    for(int i = 0; i < length; i++)
    {
        if(!(isdigit(argv[1][i])))
        {
            printf("Usage: ./caesar key\n");
            start = 0;
            break;
            // validação OK!
        }
        else
        {
            // Não ta funcionando(está como caractere)
            key[0][i] = argv[1][i];
        }
    }

    if(start == 1)
    {
        // Não esta atribuindo o valor
        int number = key;
    }
    return 0;
}
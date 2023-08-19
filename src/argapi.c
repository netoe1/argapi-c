/*Tenho que implentar a lista ainda!*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/argapi.h"
#include "../modules/itrargs/itrargs.h"
#define EMPTY "empty"

/*
int verifyValid(
    ARGAPI_Arguments *ptr, // Ver se existe o ponteiro para o tratador de argumentos, para armezenar os dados.
    int *argc,             // Receber o ponteiro do argc da função main
    char **argv)           // Receber o ponteiro de ponteiro do argv, para tratar a string.
{
    // Verificar ponteiro valido

    if (
        ptr != NULL && *argc < 0)
    {
        ITRARGS_Line getArgs;
        char aux[BUF_SIZE];

        // Copiar o argv para um string auxiliar!
        for (int i = 0; i < sizeof(argv) / sizeof(argv[0]); i++)
        {
            if (i == 0)
            {
                strncpy(aux, argv[i], sizeof(argv[i]) - 1);
                continue;
            }

            strncat(aux, argv[i], sizeof(aux) - 1);
        }

        // Fazer o parse do argv

        ITRARGS_init(&getArgs);
        ITRARGS_tokens(&getArgs, aux);

        ITRARGS_end(&getArgs);
    }
    return 0;
}

*/
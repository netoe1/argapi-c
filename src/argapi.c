/*Tenho que implentar a lista ainda!*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/argapi.h"
#include "../externalLibs/itrargs/itrargs.h"

#define EMPTY "empty"
static bool inited = false;

void init(ARGAPI_Arguments *ptr)
{
    if (ptr == NULL)
    {
        ptr = (ARGAPI_Arguments *)malloc(sizeof(ARGAPI_Arguments) * 1);
        inited = true;
        return;
    }

    printf("ARGAPI.H ERR:You almost init the ptr!\n");
}
void end(ARGAPI_Arguments *ptr)
{
    if (ptr != NULL)
    {
        free(ptr);
    }

    printf("ARGAPI.H ERR:You cannot free a invalid pointer!\n");
}
void addArgument(ARGAPI_Arguments *ptr, char *strArg)
{
    if (ptr != NULL)
    {
        if ((sizeof(ptr) / sizeof(ARGAPI_Arguments)) >= 1)
        {
            ptr = (ARGAPI_Arguments *)realloc(ptr, sizeof(ptr) + sizeof(ARGAPI_Arguments) + 1);

            strncpy(ptr[sizeof(ptr) + sizeof(ARGAPI_Arguments) - 1].longArgument, strArg, sizeof(ptr) + sizeof(ARGAPI_Arguments) - 1);
            ptr[sizeof(ptr) + sizeof(ARGAPI_Arguments) - 1].longArgument = '\0';
        }
    }
}

void removeArgument(ARGAPI_Arguments *ptr, char *argument)
{
    for (int i = 0; i < sizeof(ptr) / sizeof(ARGAPI_Arguments); i++)
    {
        if (strncmp(ptr[i].longArgument, argument, sizeof(argument) - 1) == 0)
        {
            strncpy(ptr[i].longArgument, EMPTY, sizeof(ptr[i].longArgument) - 1);
            ptr[i].longArgument[sizeof(ptr[i].longArgument)] = '\0';
        }
    }
}

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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include "../include/argapi.h"
#include "../modules/double-list/include/argapi_dlist.h"
#include "../modules/itargs/itrargs.h"
#include "../include/argapi.h"

void ARGAPI_AddValidArgNotRequired(ARGAPI_CLI_Struct *ptr, int count, ...)
{
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
    {
        const char *str = va_arg(args, const char *);
        ARGAPI_DLIST_addArguments(&ptr->arguments, str, ARG_NOT_REQUIRED);
    }

    va_end(args);
}

void ARGAPI_AddValidArgIsRequired(ARGAPI_CLI_Struct *ptr, int count, ...)
{
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
    {
        const char *str = va_arg(args, const char *);
        ARGAPI_DLIST_addArguments(&ptr->arguments, str, ARG_REQUIRED);
    }
    va_end(args);
}

void ARGAPI_AddCommands(ARGAPI_CLI_Struct *ptr, const char *strCommand, REQUIRE_TYPE required_or_not) // Stable!
{
    // I've to parse the command
    char aux[strlen(strCommand)];
    ITRARGS_Line strCommand_toParse;
    strncpy(aux, strCommand, strlen(strCommand) - 1);
    aux[strlen(aux)] = '\0';
    ITRARGS_init(&strCommand_toParse);
    ITRARGS_tokens(&strCommand_toParse, aux);

    for (unsigned int i = 0; i < strCommand_toParse.height; i++)
    {
        ARGAPI_DLIST_addArguments(&ptr->arguments, strCommand_toParse.string[i], required_or_not);
    }

    ITRARGS_end(&strCommand_toParse);
}

void ARGAPI_removeCommand(ARGAPI_CLI_Struct *ptr, const char *strCommand)
{
    char aux[strlen(strCommand)];
    ITRARGS_Line strCommand_toParse;

    strncpy(aux, strCommand, strlen(strCommand) - 1);
    aux[strlen(aux)] = '\0';
    ITRARGS_init(&strCommand_toParse);
    ITRARGS_tokens(&strCommand_toParse, aux);

    if (strCommand != NULL)
    {
        if (strCommand_toParse.height == 1)
        {
            ARGAPI_DLIST_ARG *node = ARGAPI_DLIST_search(ptr->arguments, aux);
            if (node != NULL)
            {
                ARGAPI_DLIST_deleteNode(&ptr->arguments, node);
            }
            return;
        }
    }

    ITRARGS_end(&strCommand_toParse);
}

void ARGAPI_freeMem(ARGAPI_CLI_Struct *ptr)
{
    if (ptr != NULL)
    {
        if (ptr->arguments != NULL)
        {
            // Libere os argumentos dentro da lista duplamente encadeada
            ARGAPI_DLIST_freeArguments(&ptr->arguments);
        }
        // Libere a estrutura ARGAPI_CLI_Struct
        free(ptr);
    }
}
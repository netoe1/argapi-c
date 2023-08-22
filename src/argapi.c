#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include "../include/argapi.h"
#include "../modules/double-list/include/argapi_dlist.h"
#include "../modules/itargs/itrargs.h"
#include "../include/argapi.h"



/*
void ARGAPI_addValidArgNotRequired(ARGAPI_CLI_Struct *ptr, int count, ...)
{
    if (ptr != NULL)
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
}

void ARGAPI_addValidArgIsRequired(ARGAPI_CLI_Struct *ptr, int count, ...)
{
    if (ptr != NULL)
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
}
*/
void ARGAPI_addCommands(ARGAPI_CLI_Struct *ptr, const char *strCommand, REQUIRE_TYPE required_or_not, void(*fn_to_exec)) // Stable!
{

    if (ptr != NULL)
    {
        if (fn_to_exec != NULL)
        {
            ptr->arguments->exec_void_fn = fn_to_exec;
        }
        else
        {
            ptr->arguments->exec_void_fn = NULL;
        }

        char aux[strlen(strCommand)];
        ITRARGS_Line strCommand_toParse;
        strcpy(aux, strCommand);
        ITRARGS_init(&strCommand_toParse);
        ITRARGS_tokens(&strCommand_toParse, aux);

        for (unsigned int i = 0; i < strCommand_toParse.height; i++)
        {
            ARGAPI_DLIST_addArguments(&ptr->arguments, strCommand_toParse.string[i], required_or_not, fn_to_exec);
        }

        ITRARGS_end(&strCommand_toParse);
    }
    // I've to parse the command
}

void ARGAPI_removeCommand(ARGAPI_CLI_Struct *ptr, const char *strCommand)
{
    if (ptr != NULL)
    {
        char aux[strlen(strCommand)];
        ITRARGS_Line strCommand_toParse;
        strcpy(aux, strCommand);
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
}

void ARGAPI_freeArgsMem(ARGAPI_CLI_Struct *ptr)
{
    if (ptr != NULL)
    {
        if (ptr->arguments != NULL)
        {
            // Libere os argumentos dentro da lista duplamente encadeada
            ARGAPI_DLIST_cleanup(ptr->arguments);
        }
        // Libere a estrutura ARGAPI_CLI_Struct
    }
}
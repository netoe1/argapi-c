/*Tenho que implentar a lista ainda!*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include "../include/argapi.h"
#include "../modules/double-list/include/argapi_dlist.h"
#include "../modules/itargs/itrargs.h"

static bool inited = false;

typedef struct commandLine
{
    ARGAPI_DLIST_ARG *arguments;
    int *argc;
    char **argv;
} ARGAPI_CLI_Struct;

void ARGAPI_AddValidArgNotRequired(ARGAPI_CLI_Struct *ptr, ...)
{
    va_list args;
    va_start(args, sizeof(args) / sizeof(va_list));
    for (int i = 0; i < sizeof(args) / sizeof(va_list); i++)
    {
        const char *str = va_arg(args, const char *);
        ARGAPI_DLIST_addArguments(ptr->arguments, str, ARG_NOT_REQUIRED);
    }

    va_end(args);
}

void ARGAPI_AddValidArgIsRequired(ARGAPI_CLI_Struct *ptr, ...)
{
    va_list args;
    va_start(args, sizeof(args) / sizeof(va_list));
    for (int i = 0; i < sizeof(args) / sizeof(va_list); i++)
    {
        const char *str = va_arg(args, const char *);
        ARGAPI_DLIST_addArguments(ptr->arguments, str, ARG_REQUIRED);
    }
    va_end(args);
}

void ARGAPI_AddCommands(ARGAPI_CLI_Struct *ptr, void (*pointerToFunction)(), const char *strCommand, REQUIRE_TYPE required_or_not)
{
    // I've to parse the command
    ITRARGS_Line strCommand_toParse;
    ITRARGS_init(&strCommand_toParse);
    ITRARGS_tokens(&strCommand_toParse, strCommand);

    for (unsigned int i = 0; i < sizeof(strCommand_toParse.string) / sizeof(strCommand_toParse.string[0]); i++)
    {
        ARGAPI_DLIST_addArguments(ptr->arguments, strCommand_toParse.string[i], required_or_not);
    }

    ITRARGS_end(&strCommand_toParse);
}
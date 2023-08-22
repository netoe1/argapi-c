#ifndef ARGAPI_H
#define ARGAPI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include "../include/argapi.h"
#include "../modules/double-list/include/argapi_dlist.h"
#include "../modules/itargs/itrargs.h"

typedef struct commandLine
{
    ARGAPI_DLIST_ARG *arguments;
    int *argc;
    char **argv;
} ARGAPI_CLI_Struct;
/*
void ARGAPI_addValidArgNotRequired(ARGAPI_CLI_Struct *ptr, int count, ...);
void ARGAPI_addValidArgIsRequired(ARGAPI_CLI_Struct *ptr, int count, ...);
*/
void ARGAPI_addCommand(ARGAPI_CLI_Struct *ptr, const char *strCommand, REQUIRE_TYPE required_or_not, void(*fn_to_exec));
void ARGAPI_removeCommand(ARGAPI_CLI_Struct *ptr, const char *strCommand);
void ARGAPI_freeArgsMem(ARGAPI_CLI_Struct *ptr);
#endif
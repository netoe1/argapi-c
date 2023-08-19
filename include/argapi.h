#ifndef ARGAPI_H
#define ARGAPI_H
#define BUF_SIZE 256
#define ARGAPI_REQUIRED 1
#define ARGAPI_NOT_REQUIRED 1

#include <stdbool.h>
#include "../modules/argapi_doubly-list/include/argapi_dlist.h"

typedef struct ARGAPI_line
{
    ARGAPI_DLIST_ARG *arg_head_list;
    char **argv;
    int argc;

} ARGAPI_line;

void ARGAPI_LINE_GetArguments(ARGAPI_DLIST_ARG *arg_head_list, const char **argv, const int argc);
void ARGAPI_LINE_VerifyDictionary(ARGAPI_DLIST_ARG *arg_head_list);
void ARGAPI_LINE_AddArgument(ARGAPI_DLIST_ARG *arg_head_list, const char *str_argument);
void ARGAPI_LINE_RemoveArgument(ARGAPI_DLIST_ARG *arg_head_list, const char *str_argument);

#endif
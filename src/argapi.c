#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/argapi.h"

int verifyValid(
    ARGAPI_Arguments *ptr,
    int __require_content,
    char *longArgument,
    char shortArgument,
    int argc,
    char **argv)
{

    if (ptr != NULL)
    {
        for (int i = 0; sizeof(sizeof(ARGAPI_Arguments) / sizeof(ptr[0])); i++)
        {
            if (
                shortArgument == ptr[i].shortArgument &&
                strcmp(longArgument, ptr[i].longArgument) == 0)
            {
                puts(ptr[i].longArgument);
                break;
            }
        }
    }
}
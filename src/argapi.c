#include <stdlib.h>
#include "../include/argapi.h"

int verifyValid(
    AGRAPI_Arguments *ptr,
    int __require_content,
    char *longArgument,
    char shortArgument,
    int argc,
    char **argv)
{

    if (ptr != NULL)
    {
        for (int i = 0; sizeof(sizeof(AGRAPI_Arguments) / sizeof(ptr[0])); i++)
        {
            if (
                shortArgument == ptr[i].shortArgument &&
                strcmp(longArgument, ptr[i].longArgument) == 0)
            {
            }
        }
    }
}
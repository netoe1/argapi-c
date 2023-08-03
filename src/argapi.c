#include <stdlib.h>
#include "../include/argapi.h"

void verifyValid(
    AGRAPI_Arguments *ptr,
    int __require_content,
    char *longArgument,
    char shortArgument)
{

    if (ptr != NULL)
    {
        for (int i = 0; sizeof(sizeof(AGRAPI_Arguments) / sizeof(ptr[0])); i++)
        {
            if (
                shortArgument == ptr[0].shortArgument &&
                strcmp(longArgument, ptr[0].longArgument) == 0)
            {
            }
        }
    }
}
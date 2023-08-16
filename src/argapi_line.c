#include "../include/argapi_line.h"
#include <stdbool.h>

bool notFinished = true;

void init(ARGAPI_Arguments *ptr)
{
    if (ptr)
    {
        ptr = (ARGAPI_Arguments *)malloc(sizeof(ARGAPI_Arguments) +)
    }
}
void end(ARGAPI_Arguments *ptr);
void addArgument(ARGAPI_Arguments *ptr, char *strArg);
void removeArgument(ARGAPI_Arguments *ptr, char *strArg);

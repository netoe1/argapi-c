#include "../include/argapi.h"

int main(void)
{
    ARGAPI_CLI_Struct line;
    ARGAPI_AddValidArgNotRequired(&line,5,"hello","hello","hello","Hello!");
    ARGAPI_freeMem(&line);

    return 0;
}
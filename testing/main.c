#include "../include/argapi.h"

int main(int argc, char **argv)
{
    ARGAPI_CLI_Struct line;
    ARGAPI_addCommand(&line, "--help", ARG_NOT_REQUIRED, NULL);

    ARGAPI_DLIST_display(line.arguments);
    ARGAPI_freeArgsMem(&line);

    return 0;
}
#include "../include/argapi.h"

void mensagemHelp()
{
    printf("Hello!");
    return;
}
int main(int argc, char **argv)
{
    ARGAPI_CLI_Struct line;
    ARGAPI_addCommand(&line, "--help", ARG_NOT_REQUIRED,NULL);
    ARGAPI_freeArgsMem(&line);

    return 0;
}

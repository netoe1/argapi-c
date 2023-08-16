#ifndef ARGAPI_H
#define ARGAPI_H
#define BUF_SIZE 256
#define ARGAPI_REQUIRED 1
#define ARGAPI_NOT_REQUIRED 1

typedef struct argapi_ARG
{
    char longArgument[BUF_SIZE];
    char shortArgument;
    int required_or_not;
} ARGAPI_Arguments;

/*
int verifyValid(
    ARGAPI_Arguments *ptr,
    int *argc,
    char **argv);


*/
#endif
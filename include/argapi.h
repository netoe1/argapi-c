#ifndef ARGAPI_H
#define ARGAPI_H

#define BUF_SIZE 256
#define ARGAPI_REQUIRED 1
#define ARGAPI_NOT_REQUIRED 1
typedef struct argapi_ARG
{
    char longArgument[BUF_SIZE];
    char shortArgument;
    int require_arg;
} AGRAPI_Arguments;

#endif
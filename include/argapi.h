#ifndef ARGAPI_H
#define ARGAPI_H

#define BUF_MAX 256
#define NOT_REQUIRED 0
#define REQUIRED 1

typedef struct options
{
    char return_arg;
    char long_arg[BUF_MAX];
    char short_arg;
    int required_or_not;
    int position_argc;
} ARGAPI_Options;

#endif
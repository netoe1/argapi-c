#ifndef ARGAPI_H
#define ARGAPI_H
#define BUF_SIZE 256
#define ARGAPI_REQUIRED 1
#define ARGAPI_NOT_REQUIRED 1

typedef struct argapi_ARG
{
    char longArgument[BUF_SIZE];
    int required_or_not;
} ARGAPI_Arguments;

typedef struct ARGAPI_line
{
    ARGAPI_Arguments *args;
    void (*init)(ARGAPI_line *ptr);
    void (*end)(ARGAPI_line *ptr);
    void (*addArgument)(ARGAPI_line *ptr, char *strArg);
    void (*removeArgument)(ARGAPI_line *ptr, char *strArg);

} ARGAPI_line;

void init(ARGAPI_Arguments *ptr);
void end(ARGAPI_Arguments *ptr);
void addArgument(ARGAPI_Arguments *ptr, char *strArg);
void removeArgument(ARGAPI_Arguments *ptr, char *strArg);

/*
int verifyValid(
    ARGAPI_Arguments *ptr,
    int *argc,
    char **argv);
*/
#endif
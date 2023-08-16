#ifndef ARGAPI_LINE_H_
#define ARGAPI_LINE_H_
#include "./argapi.h"
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

#endif
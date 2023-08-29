#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argapi.h"

struct Node
{
    ARGAPI_Options *option;
    struct Node *next;
};

typedef struct Node Node;

struct LinkedList
{
    Node *head;
};

typedef struct LinkedList LinkedList;

void LIST_append(LinkedList *list, ARGAPI_Options *option)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    memcpy((ARGAPI_Options*)new_node->option,(ARGAPI_Options*)option,sizeof(ARGAPI_Options));
    new_node->next = NULL;

    if (list->head == NULL)
    {
        list->head = new_node;
        return;
    }

    Node *current = list->head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
}

void LIST_display(const LinkedList *list)
{
    Node *current = list->head;
    int cont = 1;
    while (current != NULL)
    {
        printf("ARG %d:\nLong Arg:%s,Short Arg:%c,Required:%d,Position on Argv:%d", cont, current->options->long_arg, current->options->short_arg, current->options->required_or_not, current->options->position_argc);
        current = current->next;
        cont++;
    }
    printf("\n");
}

int LIST_count(const LinkedList *list)
{
    int count = 0;
    Node *current = list->head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int LIST_index_ofLongArg(const LinkedList *list, const char *long_arg)
{
    int index = 0;
    Node *current = list->head;
    while (current != NULL)
    {
        if (strcmp(current->options->long_arg, long_arg) == 0)
        {
            return index;
        }
        index++;
        current = current->next;
    }
    return -1; // Element not found
}

int LIST_index_ofShortArg(const LinkedList *list, const char short_arg)
{
    int index = 0;
    Node *current = list->head;
    while (current != NULL)
    {
        if (current->options->short_arg == short_arg)
        {
            return index;
        }
        index++;
        current = current->next;
    }
    return -1; // Element not found
}

void LIST_delete_by_index(LinkedList *list, int index)
{
    if (index < 0 || index >= LIST_count(list))
    {
        printf("Invalid index.\n");
        return;
    }

    Node *current = list->head;
    Node *prev = NULL;
    for (int i = 0; i < index; i++)
    {
        prev = current;
        current = current->next;
    }

    if (prev == NULL)
    {
        list->head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    free(current);
}

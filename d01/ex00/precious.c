#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct s_node *new_node(char c)
{
    struct s_node *node = NULL;

    node = (struct s_node *)malloc(sizeof(struct s_node));
    node->c = c;
    node->prev = NULL;
    node->next = NULL;
    return (node);
}

void  append_node(struct s_node **list, struct s_node *new_node)
{
    struct s_node *start_node;
    struct s_node *last_node;

    start_node = *list;
    if (!start_node)
    {
        start_node = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    else
    {
        last_node = start_node->prev;
        last_node->next = new_node;
        new_node->prev = last_node;
        new_node->next = start_node;
        start_node->prev = new_node;
    }
    *list = start_node;
}

char        get_letter(struct s_node **list, int index)
{
    struct s_node *start_node = NULL;

    start_node = *list;
    if (!start_node)
        return (0);
    if (index == 0)
        return (start_node->c);
    if (index < 0)
    {
        index *= -1;
        for (int i = 0; i<index; i++)
        {
            start_node = start_node->prev;
        }
    }
    else{
        for (int i = 0; i<index; i++)
        {
            start_node = start_node->next;
        }
    }
    *list = start_node;
    return (start_node->c);    
}

char        *display(struct s_node **list, int *text, int size)
{
    char    *res;

    res = (char *)malloc(sizeof(char) * size + 1);
    res[size] = '\0';
    for (int i = 0; i < size; i++)
    {
        res[i] = get_letter(list, text[i]);
    }
    return (res);
}

char        *precious(int *text, int size)
{
    struct s_node *list = NULL;
    int     len = strlen(CS);

    if (size == 0)
        return (0);
    for (int i = 0; i < len; i++)
    {
        append_node(&list, new_node(CS[i]));
    }
    return (display(&list, text, size));
}
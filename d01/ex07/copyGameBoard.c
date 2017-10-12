#include "header.h"
#include <stdlib.h>
#include <string.h>

struct s_node *create_node(int value) {
	struct s_node *node = malloc(sizeof(struct s_node));
    node->value = value;
	node->random = NULL;
	node->next = NULL;
	return (node);
}

struct s_node *cloneGameBoard(struct s_node *node)
{
    struct s_node *cloned;
    struct s_node *begin;
    struct s_node *orig;
    if (!node)
        return (0);
    /* data transfer */
    orig = node;
    cloned = create_node(node->value);
    begin = cloned;
    while (orig)
    {
        node = orig;
        orig = orig->next;
        node->next = cloned->next;
        cloned->random = node;
        cloned = cloned->next;
        cloned = create_node(node->value);
    }
    /*random pointers*/
    cloned = begin;
    while(cloned)
    {
        cloned->random = cloned->random->random->next;
        cloned = cloned->next;
    }
    return(begin);
}
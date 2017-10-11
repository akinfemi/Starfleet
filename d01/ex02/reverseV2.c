#include "header.h"
#include <stdio.h>
#include <stdlib.h>
struct s_item *create_item (char *word) {
	struct s_item *item = malloc(sizeof(*item));
	item->word = word;
	item->next = NULL;
	return (item);
}

struct	s_stack *stackInit(void)
{
		struct s_stack *new_stack = malloc(sizeof(*new_stack));
		if (!new_stack)
			return (NULL);
		new_stack->item = NULL;
		return (new_stack);
}

void	push(struct s_stack *stack, char *word)
{
		struct s_item *new_item = NULL;

		if (!stack || !word)
			return ;
		new_item = create_item(word);
		if (!stack->item)
			stack->item = new_item;
		else
		{
			new_item->next = stack->item;
            stack->item = new_item;
		}
}

void	*pop(struct s_stack *stack)
{
		struct s_item	*top = NULL;
        
		if (!stack || !stack->item)
			return (0);
		top = stack->item;
        stack->item = stack->item->next; 
        return (top);
}

void    printReverseV2(struct s_node *lst)
{
    struct s_stack  *stack = stackInit();
    struct s_item   *res;
    if (!lst || !stack)
        return ;
    while (lst)
    {
        push(stack, lst->word);
        lst = lst->next;
    }
    while (stack->item)
    {
        res = pop(stack);
        printf("%s", res->word);
        printf("%c", (res->next) ? ' ' : '\n');
    }
}
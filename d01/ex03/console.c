#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
struct s_item *create_item (int index) {
	struct s_item *item = malloc(sizeof(*item));
	item->idx = index;
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

void	push(struct s_stack *stack, int index)
{
		struct s_item *new_item = NULL;

		if (!stack)
			return ;
		new_item = create_item(index);
		if (!stack->item)
			stack->item = new_item;
		else
		{
			new_item->next = stack->item;
            stack->item = new_item;
		}
}

int     pop(struct s_stack *stack)
{
		struct s_item	*top = NULL;
        
		if (!stack || !stack->item)
			return (0);
		top = stack->item;
        stack->item = stack->item->next; 
        return (top->idx);
}

char    *console(void)
{
    struct s_stack  *stack = stackInit();
    char   buffer[256];
    char    *input;
    int     idx = 0;

    input = (char *)calloc(257,sizeof(char));
    printf("?: ");
    while (1)
    {
        bzero(buffer, 255);
        fgets(buffer, 255, stdin);
        idx = strlen(buffer) - 1;
        buffer[idx] = '\0';
        if (strcmp(buffer, "UNDO") == 0)
        {
            idx = strlen(input) - pop(stack);
            input[idx] = '\0';
            printf("%s\n", input);
        }
        else if (strcmp(buffer, "SEND") == 0)
            return (input);
        else
        {
            if (*input)
            {
                strcat(input," ");
                push (stack, idx + 1);
            }
            else
                push (stack, idx + 1);
            strcat(input,buffer);
            printf("%s\n", input);
        }
        printf("?: ");
    }
    return (input);
}
#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct s_item *create_item (int energy) {
	struct s_item *item = malloc(sizeof(*item));
	item->energy = energy;
	item->next = NULL;
	return (item);
}

struct	s_stack *stackInit(void)
{
		struct s_stack *new_stack = malloc(sizeof(*new_stack));
		if (!new_stack)
			return (NULL);
		new_stack->item = NULL;
        new_stack->total = 0;
		return (new_stack);
}

struct s_tank *initTank(void)
{
    struct s_tank *tank = (struct s_tank *)malloc(sizeof(struct s_tank));
    tank->stacks = (struct s_stack **)malloc(sizeof(struct s_stack *) * 100);
    for (int i = 0; i < 100; i++)
    {
        tank->stacks[i] = stackInit();
    }
    tank->n = 100;
    return (tank);
}

int     pop(struct s_stack *stack)
{
		struct s_item	*top = NULL;
        
		if (!stack || !stack->item)
			return (0);
		top = stack->item;
        stack->item = stack->item->next;
        stack->total -= top->energy;
        return (top->energy);
}

int     tankPop(struct s_tank *tank)
{
    if (!tank)
        return (0);
    for(int i = 0; i < tank->n; i++)
    {
        if (tank->stacks[i]->total == 0)
        {
            return (pop(tank->stacks[i - 1]));
        }
    }
    return (0);
}

void	push(struct s_stack *stack, int energy)
{
		struct s_item *new_item = NULL;

		if (!stack)
			return ;
		new_item = create_item(energy);
		if (!stack->item)
			stack->item = new_item;
		else
		{
			new_item->next = stack->item;
            stack->item = new_item;
		}
        stack->total += energy;
}

void    tankPush(struct s_tank *tank, int energy)
{
    if (!tank || energy > 100 || energy < 0)
        return ;
    for (int i = 0; i < tank->n; i++)
    {
        if (tank->stacks[i]->total + energy < 1000)
        {
            push(tank->stacks[i], energy);
            return ;
        }
    }
}

void    print_tanks(struct s_tank *tank)
{
    if (!tank)
        return ;
    for (int i = 0; i < tank->n; i++)
    {
        if (tank->stacks[i]->total == 0)
            break ;
        printf("Stack: %d, Energy total: %d\n", i, tank->stacks[i]->total);
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:41:32 by aakin-al          #+#    #+#             */
/*   Updated: 2017/10/20 14:40:17 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include "header.h"
#include <stdlib.h>
#include <stdio.h>
struct s_deque	*dequeInit(void)
{
	struct s_deque	*deque = (struct s_deque *)malloc(sizeof(struct s_deque));
	deque->first = NULL;
	deque->last = NULL;
	return (deque);
}

struct s_dequeNode *create_node(int value)
{
	struct s_dequeNode *node = (struct s_dequeNode *)malloc(sizeof(struct s_dequeNode));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	pushFront(struct s_deque *deque, int value)
{
	if(!deque)
		return ;
	struct s_dequeNode *node = create_node(value);
	node->next = deque->first;
	if (deque->first)
		deque->first->prev = node;
	deque->first = node;
	if (deque->last == NULL)
		deque->last = node;
}

void	pushBack(struct s_deque *deque, int value)
{
	if (!deque)
		return ;
	struct s_dequeNode *node = create_node(value);
	node->prev = deque->last;
	if (deque->last)
		deque->last->next = node;
	deque->last = node;
	if (deque->first == NULL)
		deque->first = node;
}

int		popFront(struct s_deque *deque)
{
	int val;
	if (!deque || !deque->first)
		return (INT_MIN);
	struct s_dequeNode *node = deque->first;
	deque->first = node->next;
	val = node->value;
	free(node);
	return(val);
}

int		popBack(struct s_deque *deque)
{
	int	val;
	if (!deque || !deque->last)
		return (INT_MIN);
	struct s_dequeNode *node = deque->last;
	deque->last = node->prev;
	val = node->value;
	free(node);
	return (val);
}

int		peek(struct s_deque *deque)
{
	if (!deque || !deque->first)
		return (-1);
	return (deque->first->value);
}

struct s_max	*maxSlidingWindow(int *arr, int n, int k)
{
	int		i = 0;
	struct s_deque *deque = dequeInit();
	struct s_max *max = (struct s_max *)malloc(sizeof(struct s_max));
	max->max = (int *)malloc(sizeof(int) * n - k + 1);
	max->length = 0;

	if (!arr || n <= 0 || k <= 0)
		return (0);
	while (i < k)
	{
		while (deque->last && arr[deque->last->value] <= arr[i])
			popBack(deque);
		pushBack(deque, i++);
	}
	max->max[i-k] = arr[peek(deque)];
	max->length++;
	while (i < n)
	{
		while (deque->last && arr[deque->last->value] <= arr[i]){
			popBack(deque);
		}
		pushBack(deque, i);
		if (deque->first && i - k >= peek(deque))
		   popFront(deque);	
		i++;
		max->max[i - k] = arr[peek(deque)];
		max->length++;
	}
	return (max);
}

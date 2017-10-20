/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:41:34 by aakin-al          #+#    #+#             */
/*   Updated: 2017/10/20 15:22:37 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "header.h"

struct s_node *create_node(int value)
{
	struct s_node *node = (struct s_node *)malloc(sizeof(struct s_node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

struct s_node *to_bst(int *arr, int start, int end)
{
	struct s_node *node;
	int mid = (start + end) / 2;

	if (start > end)
		return (NULL);
	node = create_node(arr[mid]);
	node->left = to_bst(arr, start, mid - 1);
	node->right = to_bst(arr, mid + 1, end);
	return (node);
}

struct s_node *createBST(int *arr, int n)
{
	struct s_node	*bst = NULL;

	bst = to_bst(arr, 0, n - 1);
	return (bst);
}

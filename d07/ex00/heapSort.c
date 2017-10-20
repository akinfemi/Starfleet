/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 13:46:55 by aakin-al          #+#    #+#             */
/*   Updated: 2017/10/20 11:12:01 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "header.h"

void		ft_swap(struct s_art *piece, struct s_art *other_piece)
{
	char	*name;
	int		price;

	name = other_piece->name;
	price = other_piece->price;
	other_piece->name = piece->name;
	other_piece->price = piece->price;
	piece->name = name;
	piece->price = price;
}

void		heapify(struct s_art **masterpiece, int size, int max_index)
{
	int		max = max_index;
	int		left = 2 * max_index + 1;
	int		right = 2 * max_index + 2;

	if (left < size && strcmp(masterpiece[left]->name, masterpiece[max]->name) > 0)
		max = left;
	if (right < size && strcmp(masterpiece[right]->name, masterpiece[max]->name) > 0)
		max = right;
	if (max != max_index)
	{
		ft_swap(masterpiece[max_index], masterpiece[max]);
		heapify(masterpiece, size, max);
	}
}

void		heapSort(struct s_art **masterpiece, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(masterpiece, size, i);
	for (int i = size - 1; i >= 0; i--)
	{
		ft_swap(masterpiece[0], masterpiece[i]);
		heapify(masterpiece, i, 0);
	}
}

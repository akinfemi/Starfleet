/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 20:41:30 by aakin-al          #+#    #+#             */
/*   Updated: 2017/10/19 13:42:25 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include "header.h"
#include <stdlib.h>

int		comp_func(const void *a, const void *b)
{
	struct s_hotspot **h_a = (struct s_hotspot **) a;
	struct s_hotspot **h_b = (struct s_hotspot **) b;
	return (((*h_a)->pos + (*h_a)->radius) > ((*h_b)->pos + (*h_b)->radius));
}

int		selectHotspots(struct s_hotspot **hotspots)
{
	struct s_hotspot *hspot;
	int		count = 0;
	int		curr_time = INT_MIN;
	int		size = 0;

	for (; hotspots[size]; size++)
		;
	mergesort(hotspots, size, sizeof(struct s_hotspot *), comp_func);
	for (int i = 0; hotspots[i]; i++)
	{
		hspot = hotspots[i];
		if (hspot->pos - hspot->radius >= curr_time)
		{
			count++;
			curr_time = hspot->pos + hspot->radius;
		}
	}
	return (count);
}

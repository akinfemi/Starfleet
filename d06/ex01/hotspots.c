/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 20:41:30 by aakin-al          #+#    #+#             */
/*   Updated: 2017/10/18 21:41:10 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include "header.h"

int		selectHotspots(struct s_hotspot **hotspots)
{
	struct s_hotspot *hspot;
	int		count = 0;
	int		curr_time = INT_MIN;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPersons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:01:05 by aakin-al          #+#    #+#             */
/*   Updated: 2017/10/19 16:06:35 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <math.h>

double factor_top(int k, int n)
{
    double res = 1;

    for (int i = k; i > k - n; i--)
        res *= i;
    return (res);
}

int minPersons(int elements, int minPercentage)
{
	int n = 2;

	while (1)
	{
		double k = factorial(elements, n);
        for (int i = 0; i < n; i++)
            k /= elements;
        if ((1 - k) * 100 > minPercentage)
            return (n);
        n++;
	}
}

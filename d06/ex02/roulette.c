/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 23:26:42 by aakin-al          #+#    #+#             */
/*   Updated: 2017/10/19 10:57:09 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		probabilityWin(double fDBet, double dWd, int nbGame)
{
	if (fDBet >= dWd)
		return (1);
	if (fDBet == 0 || nbGame == 0)
		return (0);
	return ( 18.0 / 37.0 * probabilityWin(fDBet*2, dWd, nbGame-1) +
			1.0 / 37.0 * probabilityWin(fDBet/2.0, dWd, nbGame-1) +
			18.0 / 37.0 * probabilityWin(0, dWd, nbGame-1));
}

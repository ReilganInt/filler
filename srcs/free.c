/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:34:59 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:35:00 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		free_bit(t_fill *filler)
{
	int a;

	a = 0;
	while (a < filler->bit_size[0])
	{
		ft_strdel(&filler->bit[a]);
		a++;
	}
	free(filler->bit);
}

void		free_map(t_fill *filler)
{
	int a;

	a = 0;
	while (a < filler->map_size[0])
	{
		ft_strdel(&filler->map[a]);
		a++;
	}
	free(filler->map);
}

void		free_sptlist(t_spt *lstsp)
{
	t_spt	*temp;

	while (lstsp)
	{
		if (lstsp->next)
		{
			temp = lstsp->next;
			free(lstsp);
			lstsp = temp;
		}
		else
			break ;
	}
	free(lstsp);
}

void		free_bitlist(t_bit *lstsp)
{
	t_bit	*temp;

	while (lstsp)
	{
		if (lstsp->next)
		{
			temp = lstsp->next;
			free(lstsp);
			lstsp = temp;
		}
		else
			break ;
	}
	free(lstsp);
}

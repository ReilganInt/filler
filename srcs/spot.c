/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:35:04 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:35:08 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#define GM g->map_size

void		find_lst(t_fill *g)
{
	t_spt	*lstsp;
	int		temp;

	lstsp = g->spot;
	temp = lstsp->summ;
	while (lstsp)
	{
		if (lstsp->summ <= temp)
		{
			if (g->xo == 'X')
				temp = lstsp->summ;
			g->a_loc = lstsp->locx;
			g->b_loc = lstsp->locy;
		}
		if (lstsp->next)
			lstsp = lstsp->next;
		else
			break ;
	}
}

void		find_loc(t_fill *g)
{
	t_bit	*p;
	t_spt	*lstsp;

	p = g->next;
	g->spot = (t_spt*)malloc(sizeof(t_spt));
	ft_bzero(g->spot, sizeof(t_spt));
	lstsp = g->spot;
	while (p->next)
	{
		if (p->bit_error == 0 && p->my_point == 1)
		{
			if (lstsp->summ != 0)
			{
				lstsp->next = (t_spt*)malloc(sizeof(t_spt));
				lstsp = lstsp->next;
				ft_bzero(lstsp, sizeof(t_spt));
				lstsp->next = NULL;
			}
			lstsp->summ = p->count;
			lstsp->locx = p->ap;
			lstsp->locy = p->bp;
		}
		p = p->next;
	}
}

t_bit		*check_bit_struct(t_bit *tbit, int a, int b)
{
	while (tbit->next)
		tbit = tbit->next;
	if (tbit->ap != a || tbit->bp != b)
	{
		tbit->next = (t_bit*)malloc(sizeof(t_bit));
		tbit->next->ap = a;
		tbit->next->bp = b;
		tbit = tbit->next;
		tbit->next = NULL;
	}
	return (tbit);
}

void		check_bit(t_fill *g, t_bit *tbit, int a, int b)
{
	int		i;
	int		j;
	t_bit	*p;

	p = check_bit_struct(tbit, a, b);
	if (a + g->bit_size[0] <= GM[0] && b + g->bit_size[1] <= GM[1])
	{
		i = 0;
		while (i < g->bit_size[0])
		{
			j = 0;
			while (j < g->bit_size[1])
			{
				if ((g->bit[i][j] != '.' && g->map[a + i][b + j] == g->enemy) ||
				(g->bit[i][j] != '.' && g->map[a + i][b + j] == g->enemy + 32))
					p->bit_error++;
				if (g->bit[i][j] != '.' && g->map[a + i][b + j] == g->xo)
					p->my_point++;
				if (g->bit[i][j] != '.')
					p->count += g->matrix[a + i][b + j];
				j++;
			}
			i++;
		}
	}
}

void		find_spot(t_fill *g)
{
	int		a;
	int		b;
	size_t	temp;
	t_bit	*tbit;

	a = 0;
	tbit = (t_bit*)malloc(sizeof(t_bit));
	ft_bzero(tbit, sizeof(t_bit));
	g->next = tbit;
	tbit->next = NULL;
	temp = g->xo * g->map_size[1] * g->map_size[0];
	while (a < g->map_size[0])
	{
		b = 0;
		while (b < g->map_size[1])
		{
			check_bit(g, tbit, a, b);
			b++;
		}
		a++;
	}
	find_loc(g);
	find_lst(g);
}

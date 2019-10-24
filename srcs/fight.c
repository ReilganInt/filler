/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:34:53 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:34:54 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		matrix_map(t_fill *g)
{
	int a;
	int b;

	a = 0;
	g->matrix = (size_t**)malloc(sizeof(size_t*) * g->map_size[0]);
	ft_bzero(g->matrix, sizeof(size_t*) * g->map_size[0]);
	while (a < g->map_size[0])
	{
		g->matrix[a] = (size_t*)malloc(sizeof(size_t) * g->map_size[1]);
		ft_bzero(g->matrix[a], sizeof(size_t) * g->map_size[1]);
		b = 0;
		while (b < g->map_size[1])
		{
			if (g->map[a][b] == '.')
				g->matrix[a][b] = 0;
			else if (g->map[a][b] == g->xo)
				g->matrix[a][b] = g->xo * g->map_size[1] * g->map_size[0];
			else if (g->map[a][b] == g->enemy)
				g->matrix[a][b] = g->enemy * g->map_size[1] * g->map_size[0];
			b++;
		}
		a++;
	}
}

int			fill_point(t_fill *g, size_t *i, int a, int b)
{
	g->ret = 0;
	if (a - 1 >= 0 && a - g->map_size[0])
	{
		if (g->matrix[a - 1][b] == 0 && ++g->ret)
			g->matrix[a - 1][b] = (*i) + 1;
		if (b + 1 < g->map_size[1] && g->matrix[a - 1][b + 1] == 0 && ++g->ret)
			g->matrix[a - 1][b + 1] = (*i) + 1;
		if (b - 1 >= 0 && g->matrix[a - 1][b - 1] == 0 && ++g->ret)
			g->matrix[a - 1][b - 1] = (*i) + 1;
	}
	if (a + 1 < g->map_size[0])
	{
		if (g->matrix[a + 1][b] == 0 && ++g->ret)
			g->matrix[a + 1][b] = (*i) + 1;
		if (b + 1 < g->map_size[1] && g->matrix[a + 1][b + 1] == 0 && ++g->ret)
			g->matrix[a + 1][b + 1] = (*i) + 1;
		if (b - 1 >= 0 && g->matrix[a + 1][b - 1] == 0 && ++g->ret)
			g->matrix[a + 1][b - 1] = (*i) + 1;
	}
	if (b - 1 >= 0 && g->matrix[a][b - 1] == 0 && ++g->ret)
		g->matrix[a][b - 1] = (*i) + 1;
	if (b + 1 < g->map_size[1] && g->matrix[a][b + 1] == 0 && ++g->ret)
		g->matrix[a][b + 1] = (*i) + 1;
	return (g->ret);
}

void		matrix_fill_two(t_fill *g, size_t *i, char *flag)
{
	int a;
	int b;

	a = 0;
	*flag = 0;
	while (a < g->map_size[0])
	{
		b = 0;
		while (b < g->map_size[1])
		{
			if (g->matrix[a][b] == *i)
				if (fill_point(g, i, a, b))
					*flag = 1;
			b++;
		}
		a++;
	}
}

void		matrix_fill_one(t_fill *g, size_t *i)
{
	int a;
	int b;

	a = 0;
	while (a < g->map_size[0])
	{
		b = 0;
		while (b < g->map_size[1])
		{
			if (g->map[a][b] == g->enemy)
				fill_point(g, i, a, b);
			b++;
		}
		a++;
	}
}

void		spot_loc(t_fill *g)
{
	char	flag;
	size_t	i;

	flag = 1;
	i = 1;
	matrix_map(g);
	matrix_fill_one(g, &i);
	i++;
	while (flag)
	{
		matrix_fill_two(g, &i, &flag);
		i++;
	}
	find_spot(g);
	if (g->spot)
		free_sptlist(g->spot);
	ft_printf("%i %i\n", g->a_loc, g->b_loc);
}

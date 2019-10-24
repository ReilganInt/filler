/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:35:16 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:35:17 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_map(t_fill *filler)
{
	char	*line;
	char	*temp;

	if (!(get_next_line(STDIN_FILENO, &line)))
	{
		if (filler->map)
			free_map(filler);
		if (filler->bit)
			free_bit(filler);
		exit(0);
	}
	temp = line;
	line = line + 8;
	filler->map_size[0] = ft_atoi(line);
	while (*line != 32)
		line++;
	filler->map_size[1] = ft_atoi(line);
	ft_strdel(&temp);
	get_next_line(STDIN_FILENO, &line);
	ft_strdel(&line);
}

void	read_bit(t_fill *filler)
{
	int		a;
	char	*line;
	char	*temp;

	if (filler->bit)
		free_bit(filler);
	get_next_line(STDIN_FILENO, &line);
	temp = line;
	line += 6;
	filler->bit_size[0] = ft_atoi(line);
	while (*line != 32)
		line++;
	filler->bit_size[1] = ft_atoi(line);
	filler->bit = (char**)malloc((sizeof(char*) * filler->bit_size[0]) + 1);
	filler->bit[filler->bit_size[0]] = NULL;
	a = 0;
	ft_strdel(&temp);
	while (a < filler->bit_size[0])
	{
		get_next_line(STDIN_FILENO, &line);
		filler->bit[a] = ft_strdup(line);
		ft_strdel(&line);
		a++;
	}
}

void	read_map(t_fill *filler)
{
	int		a;
	char	*line;

	check_map(filler);
	if (filler->map == NULL)
	{
		filler->map = (char**)malloc((sizeof(char*) * filler->map_size[0]) + 1);
		a = 0;
		while (a < filler->map_size[0])
		{
			filler->map[a] = NULL;
			a++;
		}
	}
	a = 0;
	while (a < filler->map_size[0])
	{
		if (filler->map[a])
			ft_strdel(&filler->map[a]);
		get_next_line(STDIN_FILENO, &line);
		filler->map[a] = ft_strdup(line + 4);
		ft_strdel(&line);
		a++;
	}
}

void	start_play(t_fill *filler)
{
	if (filler->xo == 'O')
	{
		read_map(filler);
		read_bit(filler);
		spot_loc(filler);
	}
	while (1)
	{
		read_map(filler);
		read_bit(filler);
		spot_loc(filler);
	}
}

int		main(void)
{
	char	*line;
	t_fill	*filler;

	filler = (t_fill*)malloc(sizeof(t_fill));
	ft_bzero(filler, sizeof(t_fill));
	filler->map = NULL;
	filler->bit = NULL;
	filler->spot = NULL;
	filler->a_loc = 0;
	get_next_line(STDIN_FILENO, &line);
	filler->xo = 'X';
	filler->enemy = 'O';
	if (ft_strstr(line, "p1") != NULL)
	{
		filler->xo = 'O';
		filler->enemy = 'X';
	}
	ft_strdel(&line);
	start_play(filler);
	return (0);
}

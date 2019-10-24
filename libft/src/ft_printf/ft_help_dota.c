/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_dota.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:14:33 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:14:35 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*un(char *main, char *s)
{
	char	*tmp_c;

	tmp_c = main;
	if (*s == '-')
		main = ft_strjoin(s, main);
	else
		main = ft_strjoin(main, s);
	free(tmp_c);
	return (main);
}

int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

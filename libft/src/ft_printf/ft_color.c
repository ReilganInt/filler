/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:13:37 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:13:38 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_detect_col(char *str, t_buf *buf)
{
	char	*tmp;
	char	*color;

	tmp = str;
	while (tmp && *tmp != '}')
	{
		if (*tmp < '0' || *tmp > '9')
			return (str - 1);
		tmp++;
	}
	if (*tmp != '}')
		return (str - 1);
	color = ft_strndup(str, tmp - str);
	ft_buf_add_s(buf, "\033[38;5;", 1);
	ft_buf_add_s(buf, color, 0);
	ft_buf_add_c(buf, 'm');
	return (tmp);
}

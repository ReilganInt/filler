/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:13:21 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:13:22 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_c(t_param list, char c, t_buf *buf)
{
	if (list.length == 'l')
		ft_c_up(list, c, buf);
	else
	{
		if (list.minus == 0 && list.zero == 1 && list.width > 1)
			ft_buf_add_s(buf,
				ft_memset(ft_strnew(list.width - 1), '0', list.width - 1), 0);
		else if (list.minus == 0 && list.zero == 0 && list.width > 1)
			ft_buf_add_s(buf,
				ft_memset(ft_strnew(list.width - 1), ' ', list.width - 1), 0);
		ft_buf_add_c(buf, c);
		if (list.minus == 1 && list.width > 1)
			ft_buf_add_s(buf,
				ft_memset(ft_strnew(list.width - 1), ' ', list.width - 1), 0);
	}
}

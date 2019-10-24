/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:13:30 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:13:31 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_len(wchar_t c)
{
	unsigned long long	cc;
	int					len;

	cc = (unsigned long long)c;
	len = 1 + (cc >= 127) + (cc >= 2047) + (cc >= 65535);
	return (len);
}

void				ft_c_up(t_param list, wchar_t c, t_buf *buf)
{
	int	len;

	if (c < 0)
		buf->err = 1;
	else
	{
		len = ft_len(c);
		if (list.minus == 0 && list.zero == 1 &&
		list.width > len && list.width - len >= 0)
			ft_buf_add_s(buf,
			ft_memset(ft_strnew(list.width - len), '0', list.width - len), 0);
		else if (list.minus == 0 && list.zero == 0 &&
		list.width > 1 && list.width - len >= 0)
			ft_buf_add_s(buf,
			ft_memset(ft_strnew(list.width - len), ' ', list.width - len), 0);
		if ((MB_CUR_MAX == 4 && c < 114112) || (MB_CUR_MAX == 3 && c < 65536) ||
			(MB_CUR_MAX == 2 && c < 2048) || (MB_CUR_MAX == 1 && c < 127))
			ft_buf_add_nc(buf, c);
		else
			ft_buf_add_c(buf, c);
		if (list.minus == 1 && list.width > len)
			ft_buf_add_s(buf,
			ft_memset(ft_strnew(list.width - len), ' ', list.width - len), 0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:23:55 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:23:57 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		prcnt(va_list ap, char **str, t_param list, t_buf *buf)
{
	*str = *str + 1;
	ft_percent(ap, str, list, buf);
}

static void		col(char **str, t_buf *buf)
{
	*str = ft_detect_col(*str + 1, buf);
	**str != '}' ? ft_buf_add_c(buf, **str) : NULL;
}

int				ft_printf(char *str, ...)
{
	va_list		ap;
	t_buf		buf;
	t_param		list;
	int			res;

	va_start(ap, str);
	ft_buf_new(&buf);
	ft_param_nul(&list);
	while (*str)
	{
		if (*str == '%')
			prcnt(ap, &str, list, &buf);
		else if (*str == '{')
			col(&str, &buf);
		else
			ft_buf_add_c(&buf, *str);
		*str ? str++ : NULL;
		buf.err == 1 ? free(buf.buf) : 0;
		if (buf.err == 1)
			return (-1);
	}
	res = ft_do_buf_empty(&buf);
	va_end(ap);
	return (res);
}

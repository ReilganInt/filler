/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:12:31 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:12:45 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_print_and_free(int top, char *str)
{
	write(1, str, top + 1);
	while (*str)
	{
		*str = 0;
		str++;
	}
}

void				ft_buf_add_s(t_buf *new, char *str, int flag)
{
	int		putch;
	size_t	len;
	char	*beg;

	len = ft_strlen(str);
	flag == 0 ? beg = str : 0;
	*str == '-' ? str++ : 0;
	new->top + 1 + len >= BUF_SIZE ? ft_print_and_free(new->top, new->buf) : 0;
	new->top + 1 + len >= BUF_SIZE ? new->top = -1 : 0;
	if (len >= BUF_SIZE)
	{
		new->size += len;
		write(1, str, len);
	}
	else
		while (*str)
		{
			putch = ft_putchar(*str, new->buf + 1 + new->top);
			new->size += putch;
			new->top += putch;
			str++;
		}
	flag == 0 ? free(beg) : 0;
}

void				ft_buf_add_ns(t_buf *new, char *str, size_t n, int flag)
{
	int		putch;
	char	*beg;

	if (new->top + 1 + n >= BUF_SIZE)
	{
		new->size += new->top + 1;
		ft_print_and_free(new->top, new->buf);
		new->top = -1;
	}
	flag == 0 ? beg = str : 0;
	if (n >= BUF_SIZE)
	{
		new->size += n;
		write(1, str, n);
	}
	else
		while (*str && n--)
		{
			putch = ft_putchar(*str, new->buf + 1 + new->top);
			new->size += putch;
			new->top += putch;
			str++;
		}
	flag == 0 ? free(beg) : 0;
}

void				ft_buf_add_c(t_buf *new, char c)
{
	if (new->top + 1 >= BUF_SIZE)
	{
		ft_print_and_free(new->top, new->buf);
		new->top = -1;
	}
	new->buf[++new->top] = c;
	new->size++;
}

void				ft_buf_add_nc(t_buf *new, wchar_t c)
{
	int putch;

	if (new->top + 1 + 1 + (c >= 127) + (c >= 2047) + (c >= 65535)
			>= BUF_SIZE)
	{
		ft_print_and_free(new->top, new->buf);
		new->top = -1;
	}
	putch = ft_putchar(c, new->buf + 1 + new->top);
	new->top += putch;
	new->size += putch;
}

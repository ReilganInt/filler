/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_buf_empty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:14:02 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:14:03 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_do_buf_empty(t_buf *buf)
{
	int size;

	size = buf->size;
	write(1, buf->buf, buf->top + 1);
	free(buf->buf);
	buf = NULL;
	return (size);
}

void	free_buf(t_buf *buf)
{
	free(buf->buf);
	buf = NULL;
}

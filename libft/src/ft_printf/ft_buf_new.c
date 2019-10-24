/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:12:50 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:13:06 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_buf				*ft_buf_new(t_buf *new)
{
	new->size = 0;
	new->top = -1;
	new->err = 0;
	if (!(new->buf = ft_strnew(BUF_SIZE)))
		return (NULL);
	return (new);
}

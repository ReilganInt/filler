/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:16:18 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:16:19 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (dst == src)
		return (dst);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		d = d + (len - 1);
		s = s + (len - 1);
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}

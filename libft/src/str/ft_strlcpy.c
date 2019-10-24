/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:19:49 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:19:50 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		n;
	const char	*s;

	if (!dst || !src)
		return (0);
	s = src;
	n = size;
	if (n != 0)
	{
		while (--n != 0)
		{
			if ((*dst++ = *src++) == '\0')
				break ;
		}
	}
	if (n == 0)
	{
		if (size != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return (src - s - 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:15:29 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:15:30 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *p;

	p = (unsigned char *)s;
	while (n--)
		if (*p != (unsigned char)c)
			p++;
		else
			return ((unsigned char *)p);
	return (NULL);
}

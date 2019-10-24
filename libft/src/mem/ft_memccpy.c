/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:15:22 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:15:23 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
					int c, size_t n)
{
	void	*p;

	p = ft_memchr(src, c, n);
	if (p != NULL)
		return (ft_mempcpy(dst, src, (p - src + 1)));
	else
	{
		ft_memcpy(dst, src, n);
		return (NULL);
	}
}

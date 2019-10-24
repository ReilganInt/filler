/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:48:05 by vmormont          #+#    #+#             */
/*   Updated: 2019/04/07 02:04:33 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stpncpy(char *dst, const char *src, size_t len)
{
	size_t	size;

	size = ft_strnlen(src, len);
	ft_memcpy(dst, src, size);
	dst += size;
	if (size == len)
		return (dst);
	return ((char *)ft_memset(dst, '\0', len - size));
}

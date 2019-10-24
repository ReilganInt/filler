/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:20:20 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:20:21 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	size;

	size = ft_strnlen(src, len);
	if (size != len)
		ft_memset(dst + size, '\0', len - size);
	return ((char *)ft_memcpy(dst, src, size));
}

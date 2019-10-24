/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:43:22 by vmormont          #+#    #+#             */
/*   Updated: 2019/04/06 20:46:40 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stpcpy(char *dst, const char *src)
{
	size_t	len;

	len = ft_strlen(src);
	return ((char *)ft_memcpy(dst, src, len + 1) + len);
}

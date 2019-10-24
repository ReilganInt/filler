/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:58:13 by vmormont          #+#    #+#             */
/*   Updated: 2019/04/10 06:49:54 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*p;

	p = ft_strstr(haystack, needle);
	if ((len == 0) && (ft_strlen(haystack) == ft_strlen(p)))
		return ((char *)haystack);
	if ((unsigned long)(p - haystack + ft_strlen(needle)) <= len)
		return ((char *)p);
	return (NULL);
}

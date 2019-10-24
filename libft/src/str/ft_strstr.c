/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:23:31 by vmormont          #+#    #+#             */
/*   Updated: 2019/04/21 18:10:14 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char		*p;
	size_t			len;

	p = haystack;
	len = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)p);
	while ((p = ft_strchr(p, *needle)) != 0)
	{
		if (ft_strncmp(p, needle, len) == 0)
			return ((char *)p);
		p++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:20:58 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:20:59 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*f;
	const char	*p;

	c = (unsigned char)c;
	if (c == '\0')
		return (ft_strchr(s, '\0'));
	f = NULL;
	while ((p = ft_strchr(s, c)) != NULL)
	{
		f = p;
		s = p + 1;
	}
	return ((char *)f);
}

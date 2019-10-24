/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:47:51 by vmormont          #+#    #+#             */
/*   Updated: 2019/04/08 01:36:44 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*s;

	s = s1;
	while (*s1++)
		;
	s1--;
	while (n--)
		if (!(*s1++ = *s2++))
			return (s);
	*s1 = '\0';
	return (s);
}

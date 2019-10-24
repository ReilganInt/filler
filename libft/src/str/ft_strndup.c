/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:20:26 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:20:27 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*new_s1;
	char	*tmp;

	if (!(new_s1 = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	tmp = new_s1;
	while ((int)n--)
	{
		*new_s1 = *s1;
		new_s1++;
		s1++;
	}
	*new_s1 = '\0';
	return (tmp);
}

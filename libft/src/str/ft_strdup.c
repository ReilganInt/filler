/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:19:20 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:19:21 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s1) + 1;
	new = (char *)malloc(sizeof(char) * len);
	if (new == NULL)
		return (NULL);
	return ((char *)ft_memcpy(new, s1, len));
}

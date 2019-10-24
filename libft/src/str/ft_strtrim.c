/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 01:31:46 by vmormont          #+#    #+#             */
/*   Updated: 2019/04/11 04:32:55 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_whitespace(s[i]))
		i++;
	l = ft_strlen(s) - 1;
	while (l > i && ft_whitespace(s[l]))
		l--;
	if (l < i)
		return (ft_strdup(""));
	return (ft_strsub(s, i, l - i + 1));
}

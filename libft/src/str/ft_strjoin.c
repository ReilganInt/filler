/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:19:27 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:19:34 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		iter;
	char	*res;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	iter = 0;
	while (iter < len1)
	{
		res[iter] = s1[iter];
		iter++;
	}
	while (iter - len1 < len2)
	{
		res[iter] = s2[iter - len1];
		iter++;
	}
	res[iter] = '\0';
	return (res);
}

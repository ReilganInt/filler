/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 02:35:20 by vmormont          #+#    #+#             */
/*   Updated: 2019/04/11 14:36:23 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_countwords(char const *str, char c)
{
	size_t		count;
	size_t		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static size_t		get_word_len(char const *str, char c)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i])
	{
		i++;
		len++;
	}
	return (len);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**new;

	if (!s || !(new = (char **)malloc(sizeof(char *) *
					(ft_countwords(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_countwords(s, c))
	{
		k = 0;
		if (!(new[i] = ft_strnew(get_word_len(&s[j], c) + 1)))
			new[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			new[i][k++] = s[j++];
		new[i][k] = '\0';
	}
	new[i] = 0;
	return (new);
}

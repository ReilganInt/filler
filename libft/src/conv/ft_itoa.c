/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:14:44 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:14:45 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_of_digits(long long nb)
{
	int res;

	res = 0;
	while (nb)
	{
		nb /= 10;
		res++;
	}
	return (res);
}

static void	fill_arr(char *str, long long n, int num_dig, int is_neg)
{
	int sign;

	if (is_neg)
		str[0] = '-';
	str[num_dig--] = '\0';
	sign = 1;
	if (n < 0)
		sign = -1;
	while (n)
	{
		str[num_dig--] = (char)((n % 10) * sign + (int)'0');
		n /= 10;
	}
}

char		*ft_itoa(long long n)
{
	char	*res;
	int		num_dig;

	num_dig = num_of_digits(n);
	if (n == 0)
	{
		if (!(res = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
	}
	else if (n < 0)
	{
		if (!(res = (char *)malloc(sizeof(char) * (num_dig + 2))))
			return (NULL);
		n *= -1;
		fill_arr(res, n, num_dig + 1, 1);
	}
	else
	{
		if (!(res = (char *)malloc(sizeof(char) * (num_dig + 1))))
			return (NULL);
		fill_arr(res, n, num_dig, 0);
	}
	return (res);
}

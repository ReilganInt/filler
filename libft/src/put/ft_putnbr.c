/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:18:38 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:18:40 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(long int n, int base, int fd)
{
	long int	div;
	char		temp;

	if (base != 10)
		n = (unsigned long int)n;
	div = 1;
	if (n < 0)
		write(fd, "-", 1);
	if (n < 0)
		n = -n;
	while (n / div >= base)
		div *= base;
	while (div > 0)
	{
		temp = '0' + n / div;
		if (temp > '9')
		{
			temp += 39;
			write(fd, &temp, 1);
		}
		else
			write(fd, &temp, 1);
		n %= div;
		div /= base;
	}
}

void	ft_putnbr_base(long int n, int base)
{
	ft_putnbr_base_fd(n, base, 1);
}

void	ft_putnbr_fd(long int n, int fd)
{
	ft_putnbr_base_fd(n, 10, fd);
}

void	ft_putnbr(long int n)
{
	ft_putnbr_base_fd(n, 10, 1);
}

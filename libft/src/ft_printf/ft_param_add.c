/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:17:18 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:24:07 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_get_length(char **str, t_param *new)
{
	if (**str == 'L' || **str == 'l' || **str == 'h' ||
											**str == 'j' || **str == 'z')
	{
		new->length += **str;
		*str += 1;
	}
	if ((new->length == 'l' && **str == 'l') ||
		(new->length == 'h' && **str == 'h'))
	{
		new->length += **str;
		*str += 1;
	}
}

static void		ft_flags(t_param *new, char **str)
{
	while (**str && (**str == '0' || **str == '+' || **str == '-' ||
			**str == ' ' || **str == '#'))
	{
		(**str == '#') ? new->hasht = 1 : 0;
		(**str == '0') ? new->zero = 1 : 0;
		(**str == '-') ? new->minus = 1 : 0;
		(**str == '+') ? new->plus = 1 : 0;
		(**str == ' ') ? new->space = 1 : 0;
		*str += 1;
	}
	(new->space == 1 && new->plus == 1) ? new->space = 0 : 1;
	(new->zero == 1 && new->minus == 1) ? new->zero = 0 : 1;
}

static void		ft_get_width(t_param *new, char **str, va_list ap)
{
	if (**str == '*')
	{
		new->width = (long long)va_arg(ap, long long);
		if (new->width < 0)
		{
			new->width *= -1;
			new->minus = 1;
		}
		*str = *str + 1;
	}
	else
	{
		new->width = ft_atoi(*str);
		while (**str && **str >= '0' && **str <= '9')
			*str += 1;
	}
}

static int		ft_prec(t_param *new, char **str, va_list ap)
{
	if (*(*str + 1) >= '0' && *(*str + 1) <= '9')
		new->precision = ft_atoi(*str + 1);
	else if (*(*str + 1) == '-')
		new->precision = -2;
	else if (*(*str + 1) == '*')
	{
		new->precision = (unsigned long long)va_arg(ap, unsigned long long);
		*str = *str + 1;
	}
	else if (*(*str + 1) == '\0')
		return (-1);
	else
		new->precision = 0;
	*str += 1;
	while (**str && **str >= '0' && **str <= '9')
		*str += 1;
	return (1);
}

int				ft_param_add(t_param *new, char **str, va_list ap)
{
	ft_flags(new, str);
	ft_get_width(new, str, ap);
	if (**str == '*' || (**str >= '0' && **str <= '9'))
		ft_get_width(new, str, ap);
	if (**str == '.')
	{
		if ((ft_prec(new, str, ap)) == -1)
			return (-1);
	}
	ft_get_length(str, new);
	if (**str && (**str == '0' || **str == '+' || **str == '-' ||
			**str == ' ' || **str == '#'))
		ft_flags(new, str);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:14:23 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:14:25 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		just_print(t_param list, char *i, t_buf *buf)
{
	list.plus == 1 && *i != '-' ? ft_buf_add_c(buf, '+') : 0;
	*i == '-' ? ft_buf_add_c(buf, '-') : 0;
	ft_buf_add_s(buf, i, 0);
	list.hasht == 1 && list.precision == 0 ? ft_buf_add_c(buf, '.') : 0;
}

static void		minus_pos(t_param list, char *i, int tmp, t_buf *buf)
{
	if (list.space == 1 && list.plus == 0 && *i != '-')
		ft_buf_add_c(buf, ' ');
	list.plus == 1 && *i != '-' ? ft_buf_add_c(buf, '+') : 0;
	ft_buf_add_s(buf, i, 0);
	list.hasht == 1 && list.precision == 0 ? ft_buf_add_c(buf, '.') : 0;
	if (list.width > tmp + (*i != '-' && (list.plus == 1 || list.space == 1)))
		ft_buf_add_s(buf, ft_memnew(list.width - tmp - (*i != '-' &&
					(list.plus == 1 || list.space == 1)), ' '), 0);
}

static void		minus_neg(t_param list, char *i, int tmp, t_buf *buf)
{
	if (list.width > tmp + (*i != '-' && (list.plus == 1 || list.space == 1)))
	{
		if (list.zero == 0)
		{
			ft_buf_add_s(buf, ft_memnew(list.width - tmp - (*i != '-' &&
			(list.plus == 1 || list.space == 1)), ' '), 0);
			((list.space == 1 && *i != '-') || (list.space == 1
						&& list.plus == 0)) ? ft_buf_add_c(buf, ' ') : 0;
			list.plus == 1 && *i != '-' ? ft_buf_add_c(buf, '+') : 0;
		}
		else
		{
			((list.space == 1 && *i != '-') || (list.space == 1 &&
			list.plus == 0)) ? ft_buf_add_c(buf, ' ') : 0;
			list.plus == 1 && *i != '-' ? ft_buf_add_c(buf, '+') : 0;
			*i == '-' ? ft_buf_add_c(buf, '-') : 0;
			*i == '-' ? i++ : 0;
			ft_buf_add_s(buf, ft_memnew(list.width - tmp -
						(list.plus || *i == '-') - list.space, '0'), 0);
		}
		ft_buf_add_s(buf, i, 0);
		list.hasht == 1 && list.precision == 0 ? ft_buf_add_c(buf, '.') : 0;
	}
	else
		just_print(list, i, buf);
}

static void		ft_type_f(t_param list, char *i, t_buf *buf)
{
	int	tmp;

	tmp = ft_strlen(i);
	if (list.precision == 0 && list.hasht == 1)
		tmp += 1;
	if (list.minus == 0)
		minus_neg(list, i, tmp, buf);
	if (list.minus == 1)
		minus_pos(list, i, tmp, buf);
}

void			ft_f_up(t_param list, va_list ap, t_buf *buf)
{
	char	*num;
	int		i;

	i = 0;
	list.precision == -1 ? list.precision = 6 : 0;
	list.precision == -2 ? list.precision = 0 : 0;
	if (list.length == 'L')
		num = ft_dota((long double)va_arg(ap, long double), list.precision);
	else
		num = ft_dota((double)va_arg(ap, double), list.precision);
	if (num[1] >= 'a' && num[1] <= 'z')
	{
		if (num[i] == '-')
			i++;
		while (num[i])
		{
			num[i] -= 32;
			i++;
		}
	}
	ft_type_f(list, num, buf);
}

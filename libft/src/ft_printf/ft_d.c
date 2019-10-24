/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:13:44 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:13:47 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	minus_pos(char *i, t_param list, int tmp, t_buf *buf)
{
	int	tmp_2;

	tmp_2 = tmp;
	*i == '-' ? tmp_2 = tmp - 1 : 0;
	if (list.space == 1 && *i != '-' && list.plus == 0)
		ft_buf_add_c(buf, ' ');
	else
		list.space = 0;
	if (list.plus == 1 && *i != '-')
		ft_buf_add_c(buf, '+');
	if (*i == '-')
		ft_buf_add_c(buf, '-');
	if (list.precision > tmp_2 && list.zero == 0)
		ft_buf_add_s(buf, ft_memnew(list.precision - tmp_2, '0'), 0);
	ft_buf_add_s(buf, i, 0);
	if (list.width > list.precision && list.width > tmp && list.zero == 1)
		ft_buf_add_s(buf, ft_memnew(list.width - list.space - list.plus -
				(list.precision > tmp_2 ? list.precision : tmp_2), '0'), 0);
	if (list.width > list.precision && list.width > tmp)
		ft_buf_add_s(buf, ft_memnew(list.width -
			(list.space == 1 || list.plus == 1 || (tmp != tmp_2)) -
				(list.precision > tmp_2 ? list.precision : tmp_2), ' '), 0);
}

static void	prec_neg(char *i, t_param list, int tmp, t_buf *buf)
{
	list.plus == 1 && *i != '-' ? tmp += 1 : 0;
	if (list.space == 1 && *i != '-' && list.plus == 0)
		ft_buf_add_c(buf, ' ');
	else
		list.space = 0;
	if (list.minus == 0 && list.zero == 0 && list.width > tmp)
		ft_buf_add_s(buf, ft_memnew(list.width - tmp -
			(list.space == 1 && list.plus == 0 && *i != '-'), ' '), 0);
	list.plus == 1 && *i != '-' ? ft_buf_add_c(buf, '+') : 0;
	if (*i == '-')
		ft_buf_add_c(buf, '-');
	if (list.minus == 0 && list.zero == 1 && list.width > tmp)
		ft_buf_add_s(buf, ft_memnew(list.width - tmp -
			(list.space == 1 && list.plus == 0 && *i != '-'), '0'), 0);
	ft_buf_add_s(buf, i, 0);
	if (list.minus == 1 && list.width > tmp)
		ft_buf_add_s(buf, ft_memnew(list.width - tmp - list.space, ' '), 0);
}

static void	prec_pos(char *i, t_param list, int tmp, t_buf *buf)
{
	int		tmp_2;

	tmp_2 = tmp;
	*i == '-' ? tmp_2 = tmp - 1 : 0;
	*i == '0' && list.precision == 0 ? tmp_2 -= 1 : 0;
	if (list.space == 1 && list.plus == 0 && *i != '-')
		ft_buf_add_c(buf, ' ');
	else
		list.space = 0;
	if (list.width > list.precision && list.width > tmp)
		ft_buf_add_s(buf, ft_memnew(list.width - list.space -
		(list.plus || *i == '-') - (list.precision > tmp_2 ? list.precision
		: tmp_2), ' '), 0);
	if (list.plus == 1 && *i != '-')
		ft_buf_add_c(buf, '+');
	*i == '-' ? ft_buf_add_c(buf, *i) : 0;
	if (list.precision > tmp_2)
		ft_buf_add_s(buf, ft_memnew(list.precision - tmp_2, '0'), 0);
	*i == '0' && list.precision == 0 ? NULL : ft_buf_add_s(buf, i, 0);
}

static void	ft_type_d(t_param list, char *i, t_buf *buf)
{
	if (list.precision <= -1)
		prec_neg(i, list, ft_strlen(i), buf);
	else if (list.minus == 0)
		prec_pos(i, list, ft_strlen(i), buf);
	else if (list.minus == 1)
		minus_pos(i, list, ft_strlen(i), buf);
}

void		ft_d(t_param list, va_list ap, t_buf *buf)
{
	if (list.length == 0)
		ft_type_d(list, ft_itoa_base((int)va_arg(ap, int), 10), buf);
	else if (list.length == 'l')
		ft_type_d(list, ft_itoa_base((long)va_arg(ap, long), 10), buf);
	else if (list.length == 'l' + 'l')
		ft_type_d(list,
			ft_itoa_base((long long)va_arg(ap, long long), 10), buf);
	else if (list.length == 'h')
		ft_type_d(list, ft_itoa_base((short)va_arg(ap, int), 10), buf);
	else if (list.length == 'h' + 'h')
		ft_type_d(list, ft_itoa_base((char)va_arg(ap, int), 10), buf);
	else if (list.length == 'j')
		ft_type_d(list, ft_itoa_base((intmax_t)va_arg(ap, intmax_t), 10), buf);
	else if (list.length == 'z')
		ft_type_d(list, ft_itoa_base((ssize_t)va_arg(ap, ssize_t), 10), buf);
}

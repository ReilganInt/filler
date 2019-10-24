/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:18:51 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:18:52 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_sym(wchar_t *s, t_buf *buf, size_t size)
{
	while (size--)
	{
		ft_buf_add_nc(buf, *s);
		s++;
	}
}

static void		minus_neg(t_param list, wchar_t *s, int tmp, t_buf *buf)
{
	if (list.width >
			(tmp < list.precision ? tmp : list.precision) && list.zero == 1)
		ft_buf_add_s(buf, ft_memnew(list.width -
					(tmp < list.precision ? tmp : list.precision), '0'), 0);
	else if (list.width > (tmp < list.precision ? tmp : list.precision))
		ft_buf_add_s(buf, ft_memnew(list.width -
					(tmp < list.precision ? tmp : list.precision), ' '), 0);
	if (s != NULL)
		print_sym(s, buf, tmp < list.precision ? tmp : list.precision);
	else
		ft_buf_add_ns(buf, "(null)", list.precision, 1);
}

static void		prec_pos(t_param list, wchar_t *s, int tmp, t_buf *buf)
{
	if (list.minus == 0)
		minus_neg(list, s, tmp, buf);
	else
	{
		if (s != NULL)
			print_sym(s, buf, tmp < list.precision ? tmp : list.precision);
		else
			ft_buf_add_ns(buf, "(null)", list.precision, 1);
		if (list.width >
			(tmp < list.precision ? tmp : list.precision) && list.zero == 1)
			ft_buf_add_s(buf, ft_memnew(list.width -
					(tmp < list.precision ? tmp : list.precision), '0'), 0);
		else if (list.width > (tmp < list.precision ? tmp : list.precision))
			ft_buf_add_s(buf, ft_memnew(list.width -
					(tmp < list.precision ? tmp : list.precision), ' '), 0);
	}
}

static void		prec_neg(t_param list, wchar_t *s, int tmp, t_buf *buf)
{
	if (list.minus == 0)
	{
		if (list.width > tmp && list.zero == 0)
			ft_buf_add_s(buf, ft_memnew(list.width - tmp, ' '), 0);
		else if (list.width > tmp)
			ft_buf_add_s(buf, ft_memnew(list.width - tmp, '0'), 0);
		if (s != NULL)
			print_sym(s, buf, tmp);
		else
			ft_buf_add_s(buf, "(null)", 1);
	}
	else
	{
		if (s != NULL)
			print_sym(s, buf, tmp);
		else
			ft_buf_add_s(buf, "(null)", 1);
		if (list.width > tmp && list.zero == 1)
			ft_buf_add_s(buf, ft_memnew(list.width - tmp, '0'), 0);
		else if (list.width > tmp)
			ft_buf_add_s(buf, ft_memnew(list.width - tmp, ' '), 0);
	}
}

void			ft_s_up(t_param list, wchar_t *s, t_buf *buf)
{
	int		tmp;
	wchar_t	*ss;

	ss = s;
	if (s)
		while (*ss)
			ss++;
	tmp = ss - s;
	if (list.precision > -1)
		prec_pos(list, s, tmp, buf);
	else
		prec_neg(list, s, tmp, buf);
}

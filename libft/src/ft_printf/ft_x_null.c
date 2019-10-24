/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:21:30 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:21:33 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	minus_neg_null(t_param list, int tmp, t_buf *buf)
{
	if ((list.width - (list.precision > tmp ? list.precision : tmp) -
										list.hasht) >= 0 && list.zero != 1)
		ft_buf_add_s(buf, ft_memnew(list.width - (list.precision > tmp ?
				list.precision : tmp) -
					(list.hasht == 1 && list.precision == -1), ' '), 0);
	if (list.precision == -1)
		ft_buf_add_s(buf, "0", 1);
	if ((list.width - (list.precision > tmp ? list.precision : tmp) -
										list.hasht) > 0 && list.zero == 1)
		ft_buf_add_s(buf, ft_memnew(list.width - tmp -
		(list.hasht == 1 && list.precision == -1), '0'), 0);
	if (list.precision > tmp)
		ft_buf_add_s(buf, ft_memnew(list.precision - tmp, '0'), 0);
}

void	minus_pos_null(t_param list, int tmp, t_buf *buf)
{
	if (list.precision == -1)
		ft_buf_add_s(buf, "0", 1);
	if (list.precision > tmp)
		ft_buf_add_s(buf, ft_memnew(list.precision - tmp, '0'), 0);
	if ((list.width - (list.precision > tmp ? list.precision : tmp) -
										list.hasht) >= 0 && list.zero != 1)
		ft_buf_add_s(buf,
		ft_memnew(list.width - (list.precision > tmp ? list.precision : tmp)
					- (list.hasht == 1 && list.precision == -1), ' '), 0);
}

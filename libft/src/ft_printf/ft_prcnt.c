/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prcnt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:17:50 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:17:51 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_prcnt(t_param list, t_buf *buf)
{
	if (list.minus == 0 && list.zero == 1 && list.width > 1)
		ft_buf_add_s(buf,
			ft_memset(ft_strnew(list.width - 1), '0', list.width - 1), 0);
	else if (list.width > 1 && list.minus == 0)
		ft_buf_add_s(buf,
			ft_memset(ft_strnew(list.width - 1), ' ', list.width - 1), 0);
	ft_buf_add_c(buf, '%');
	if (list.width > 1 && list.minus == 1)
		ft_buf_add_s(buf,
			ft_memset(ft_strnew(list.width - 1), ' ', list.width - 1), 0);
}

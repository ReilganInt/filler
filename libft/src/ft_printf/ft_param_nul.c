/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_nul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:17:27 by vmormont          #+#    #+#             */
/*   Updated: 2019/10/20 20:17:28 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_param_nul(t_param *param)
{
	param->precision = -1;
	param->width = 0;
	param->minus = 0;
	param->plus = 0;
	param->zero = 0;
	param->hasht = 0;
	param->space = 0;
	param->length = 0;
}

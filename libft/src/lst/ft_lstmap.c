/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 02:55:52 by vmormont          #+#    #+#             */
/*   Updated: 2019/04/20 15:41:20 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lstfree(t_list *lst)
{
	t_list		*new;

	new = lst;
	if (!lst)
		return ;
	while (new)
	{
		new = lst->next;
		free(lst);
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*tmp;
	t_list		*begin;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
		{
			ft_lstfree(begin);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (begin);
}

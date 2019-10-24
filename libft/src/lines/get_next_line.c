/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:03:53 by vmormont          #+#    #+#             */
/*   Updated: 2019/05/01 20:21:59 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_line_len(t_fd *cur, t_list *end, void *end_line)
{
	size_t			len;
	t_list			*del;

	del = cur->res;
	cur->res = ft_lstnew((void *)((char *)end_line + 1),
	end->content_size - (size_t)((char *)end_line - (char *)end->content) - 1);
	cur->state =
	cur->state - (int)((char *)end_line - (char *)end->content) - 1;
	len = (size_t)((char *)end_line - (char *)end->content);
	while (del != end)
	{
		len = len + del->content_size;
		del = del->next;
	}
	return (len);
}

static int			ft_get_line(t_fd *cur, t_list *end,
								char **line, void *end_line)
{
	size_t			len;
	size_t			i;
	t_list			*tmp;
	t_list			*del;

	i = 0;
	if (cur->state <= 0 || !end_line)
		return (0);
	del = cur->res;
	len = ft_line_len(cur, end, end_line);
	if (!(cur->res) || !(*line = ft_strnew(len + 1)))
		return (-1);
	while ((tmp = del))
	{
		ft_memccpy(*line + i, del->content, '\n', del->content_size);
		i = i + del->content_size;
		del = del->next;
		free(tmp->content);
		free(tmp);
	}
	(*line)[len] = ((*line)[len] == '\n') ? 0 : (*line)[len];
	cur->numlines = cur->numlines + 1;
	return (1);
}

static t_fd			*ft_check(const int fd, t_fd **fd_list)
{
	t_fd			*new;
	t_fd			*copy;

	copy = *fd_list;
	if (copy)
	{
		while (copy->next && copy->fd != fd)
			copy = copy->next;
		if (copy->fd == fd)
			return (copy);
	}
	if (!(new = (t_fd *)malloc(sizeof(t_fd) * 1)))
		return (NULL);
	if (*fd_list)
		copy->next = new;
	else
		*fd_list = new;
	new->fd = fd;
	new->state = 0;
	new->numlines = 0;
	new->next = NULL;
	if (!(new->res = ft_lstnew(NULL, 0)))
		return (NULL);
	return (new);
}

static int			ft_read_next(t_fd *cur, char **line, void *buff)
{
	int				file;
	t_list			*tmp;

	tmp = cur->res;
	while ((file = (int)read(cur->fd, buff, BUFF_SIZE)) > 0)
	{
		cur->state = file;
		if (!(tmp->next = ft_lstnew(buff, (size_t)cur->state)))
			return (-1);
		tmp = tmp->next;
		if ((file = ft_get_line(cur, tmp, line,
			ft_memchr(tmp->content, '\n', tmp->content_size))))
			return (file);
	}
	cur->state = (file) ? file : cur->state;
	if (cur->state == -1)
		return (-1);
	return (ft_get_line(cur, tmp, line,
		(void *)((char *)tmp->content + tmp->content_size - 1)));
}

int					get_next_line(const int fd, char **line)
{
	static t_fd		*fd_list = NULL;
	t_fd			*cur;
	int				res;
	void			*buff;

	if (fd < 0 || !line || !(cur = ft_check(fd, &fd_list)))
		return (-1);
	*line = NULL;
	if ((res = ft_get_line(cur, cur->res, line,
	ft_memchr(cur->res->content, '\n', cur->res->content_size)) != 0))
		return (res);
	if (!(buff = ft_memalloc(BUFF_SIZE)))
		return (-1);
	res = ft_read_next(cur, line, buff);
	ft_memdel(&buff);
	return (res);
}

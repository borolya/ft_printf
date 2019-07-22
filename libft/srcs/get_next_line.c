/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <bharmund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:57:23 by bharmund          #+#    #+#             */
/*   Updated: 2019/07/01 10:22:21 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void		free_lst_item(t_gnl **start, t_gnl *item)
{
	t_gnl *tmp;

	if (!start || !item)
		return ;
	if (*start == item)
	{
		tmp = item->next;
		free(item->text);
		free(item);
		*start = tmp;
		return ;
	}
	tmp = *start;
	while (tmp->next != item)
		tmp = tmp->next;
	tmp->next = item->next;
	tmp = item->next;
	free(item->text);
	free(item);
}

static t_gnl	*list_creat_add(t_gnl **start, int fd)
{
	t_gnl	*item;

	if (!start || !(item = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	item->text = ft_strdup("");
	item->fd = fd;
	item->next = *start;
	*start = item;
	return (item);
}

static char		*ft_get_part(char **line, char *text, int c)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (text[i] != (char)c && text[i] != '\0')
		i++;
	if (!(*line = ft_strsub(text, 0, i)))
		return (NULL);
	if (text[i] == '\0')
		tmp = ft_strdup(text + i);
	else
		tmp = ft_strdup(text + i + 1);
	free(text);
	return (tmp);
}

static int		find_line(char **line, int fd, char **text)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	while (!ft_strchr(*text, '\n'))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		if (ret == 0)
		{
			if (*text[0] != '\0')
				break ;
			return (0);
		}
		buff[ret] = '\0';
		tmp = ft_strjoin(*text, buff);
		free(*text);
		*text = tmp;
	}
	*text = ft_get_part(line, *text, '\n');
	if (*text == NULL)
		return (-1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*start;
	t_gnl			*item;
	int				gnl;

	if (fd < 0 || fd > FOPEN_MAX || !line || BUFF_SIZE < 1)
		return (-1);
	item = start;
	while (!!item)
	{
		if (item->fd == fd)
			break ;
		item = item->next;
	}
	if (!item)
		if (!(item = list_creat_add(&start, fd)))
			return (-1);
	gnl = find_line(line, item->fd, &(item->text));
	if (gnl <= 0)
		free_lst_item(&start, item);
	return (gnl);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:08:36 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/12 13:28:34 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		path_len(t_links *path)
{
	int i;

	i = 0;
	while ((path = path->next))
		i++;
	return (i);
}

static t_paths *new_path(t_links *data, int num)
{
	t_paths *new;

	if (!data)
		return (NULL);
	new = (t_paths*)malloc(sizeof(t_paths));
	new->path = data;
	new->num = num;
	new->len = path_len(data);
	new->next = NULL;
	return (new);
}

static void	add_path(t_paths *path, t_links *new, int num)
{
	while (path->next)
		path = path->next;
	path->next = new_path(new, num);
}

t_paths		*get_paths(t_room *start)
{
	t_paths	*paths;
	t_links	*tmp;
	int		num;

	num = 1;
	paths =	new_path(reverse(find_path(start)), num++);
	while ((tmp = find_path(start)))
	{
		add_path(paths, reverse(tmp), num++);
	}
	return (paths);
}
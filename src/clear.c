/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 12:43:45 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/12 12:44:00 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	clear_links(t_links *links)
{
	t_links *tmp;

	while (links)
	{
		tmp = links;
		links = links->next;
		free(tmp);
	}
}

void	clear_paths(t_paths *paths)
{
	t_paths *tmp;

	while (paths)
	{
		clear_links(paths->path);
		tmp = paths;
		paths = paths->next;
		free(tmp);
	}
}

void	clear_rooms(t_room *rooms)
{
	t_room *tmp;

	while (rooms)
	{
		ft_strdel(&rooms->name);
		clear_links(rooms->links);
		tmp = rooms;
		rooms = rooms->next;
		free(tmp);
	}
}

void	clear(t_paths *paths, t_room *rooms)
{
	clear_rooms(rooms);
	clear_paths(paths);
}

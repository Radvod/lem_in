/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 12:43:45 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/13 17:27:19 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_paths(t_path **paths, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		free(paths[i]);
		i++;
	}
	if (paths)
		free(paths);
	paths = NULL;
}

void	free_rooms(t_colony *colony)
{
	int i;

	i = 0;
	while (i < (colony)->room_num && (colony)->rooms)
	{
		free((colony)->rooms[i]->name);
		free((colony)->rooms[i]);
		i++;
	}
	if ((colony)->rooms)
		free((colony)->rooms);
}

void		free_all(t_colony *colony)
{
	int i;

	i = 0;
	if (colony)
	{
		while (i < (colony)->room_num && (colony)->link_arr)
		{
			if ((colony)->link_arr[i])
				free((colony)->link_arr[i]);
			i++;
		}
		if ((colony)->link_arr)
			free((colony)->link_arr);
		if ((colony)->rooms)
			free_rooms(colony);
		if ((colony)->paths)
			free_paths((colony)->paths, (colony)->path_num);
		if ((colony)->line)
			str_free((colony)->line, 0);
		free(colony);
	}
}
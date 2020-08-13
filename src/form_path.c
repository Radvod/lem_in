/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:16:31 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/13 16:17:04 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*create_path(t_room *head, int len)
{
	t_path *path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		ft_error("Error");
	path->head = head;
	path->len = len;
	path->comp = 0;
	return (path);
}

int		does_path_end(t_colony *colony, int room_id)
{
	int i;
	int len;

	len = 0;
	if (room_id == colony->room_num - 1)
		return (1);
	while (1)
	{
		i = 1;
		while (i < colony->room_num)
		{
			if (colony->link_arr[room_id][i] == 1)
			{
				len++;
				if (i == colony->room_num - 1)
					return ((len + 1) / 2);
				room_id = i;
				break ;
			}
			i++;
		}
		if (i == colony->room_num)
			ft_error("Error");
	}
}

void	set_next_prev(t_colony *colony, int room_id)
{
	int i;

	colony->rooms[room_id]->temp_prev = NULL;
	while (room_id != colony->room_num - 1)
	{
		i = 1;
		while (i < colony->room_num)
		{
			if (colony->link_arr[room_id][i] == 1)
			{
				colony->rooms[room_id]->temp_next = colony->rooms[i];
				if (i != colony->room_num - 1)
					colony->rooms[i]->temp_prev = colony->rooms[room_id];
				room_id = i;
				break ;
			}
			i++;
		}
	}
}

int		get_num_paths(t_colony *colony)
{
	int num;
	int i;

	num = 0;
	i = 0;
	while (i < colony->room_num)
	{
		if (colony->link_arr[0][i] == 1 &&
			(i == colony->room_num - 1 || does_path_end(colony, i)))
			num++;
		i++;
	}
	return (num);
}

t_path	**pathfinder(t_colony *colony)
{
	int		i;
	int		len;
	t_path	*one_path;

	colony->path_num = get_num_paths(colony);
	if (!(colony->paths = (t_path**)malloc(sizeof(t_path*) * colony->path_num)))
		ft_error("Error");
	i = 0;
	colony->path_num = 0;
	while (++i < colony->room_num)
	{
		if (colony->link_arr[0][i] == 1 &&
			(len = does_path_end(colony, i)))
		{
			one_path = create_path(colony->rooms[i], len);
			if (!one_path)
				return (NULL);
			set_next_prev(colony, i);
			colony->paths[colony->path_num] = one_path;
			colony->path_num++;
		}
	}
	sort_paths(colony->paths, colony->path_num - 1);
	define_comp_num(colony->paths, colony->path_num);
	return (colony->paths);
}

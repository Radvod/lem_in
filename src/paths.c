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

void	refresh_visited_and_lvl(t_room **rooms, int num)
{
	int i;

	i = 1;
	while (i < num - 1)
	{
		rooms[i]->visited = 0;
		rooms[i]->level = -1;
		rooms[i]->temp_prev = NULL;
		i++;
	}
	rooms[num - 1]->visited = 0;
}

void	find_path_backwards(t_colony *colony, int room_id)
{
	int prev;

	while (room_id != 0)
	{
		prev = colony->rooms[room_id]->temp_prev->num;
		if (colony->link_arr[prev][room_id] == 3)
		{
			colony->link_arr[prev][room_id] = 1;
			colony->link_arr[room_id][prev] = 2;
		}
		else if (colony->link_arr[prev][room_id] == 2)
		{
			colony->link_arr[prev][room_id] = 4;
			colony->link_arr[room_id][prev] = 3;
		}
		room_id = prev;
	}
}

int		find_level(t_colony *colony, int prev, int curr)
{
	if (colony->link_arr[prev][curr] == 3)
		return (colony->rooms[prev]->level + 1);
	else
		return (colony->rooms[prev]->level - 1);
}

void	set_true_prev(t_colony *colony)
{
	int i;

	i = 0;
	while (i < colony->room_num)
	{
		colony->rooms[i]->prev = colony->rooms[i]->temp_prev;
		colony->rooms[i]->next = colony->rooms[i]->temp_next;
		i++;
	}
}

void	set_optimal_path(t_colony *colony, int n_new)
{
	if (colony->paths_temp != NULL)
		free_paths(colony->paths_temp, colony->path_num_temp);
	colony->paths_temp = colony->paths;
	colony->paths = NULL;
	colony->path_num_temp = colony->path_num;
	colony->path_num = 0;
	colony->n_turns = n_new;
	set_true_prev(colony);
}

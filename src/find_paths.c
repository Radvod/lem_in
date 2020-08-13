/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:39:31 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/13 17:11:20 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	in_end_room(t_colony *colony, t_room *room, t_queue **q, int i)
{
	colony->link_arr[room->num][i] = 1;
	colony->link_arr[i][room->num] = 2;
	colony->rooms[i]->visited = 1;
	find_path_backwards(colony, room->num);
	free_queue(q);
}

void		add_node(t_colony *colony, t_queue **q, t_room *room, int i)
{
	t_queue		*new;

	if (!(new = new_queue_node(colony->rooms[i])))
		ft_error("Error");
	new->room->temp_prev = room;
	new->room->visited = 1;
	new->room->level = find_level(colony, room->num, new->room->num);
	push_node(q, new);
}

void		traverse_queue(t_colony *colony, t_queue **q)
{
	t_room		*room;
	int			i;

	room = pop_node(q);
	i = 0;
	while (i < colony->room_num)
	{
		if (i == colony->room_num - 1 && colony->link_arr[room->num][i] == 3)
		{
			in_end_room(colony, room, q, i);
			break ;
		}
		else if (i != colony->room_num - 1 && colony->rooms[i]->visited == 0 &&
				 (colony->link_arr[room->num][i] == 3 || colony->link_arr[room->num][i] == 2))
			add_node(colony, q, room, i);
		i++;
	}
}

int		end_ed_karp(t_colony *colony)
{
	colony->paths = colony->paths_temp;
	colony->path_num = colony->path_num_temp;
	return (0);
}

int		edmonds_karp(t_colony *colony)
{
	t_queue		*q;
	int			n_new;

	while (1)
	{
		refresh_visited_and_lvl(colony->rooms, colony->room_num);
		q = new_queue_node(colony->rooms[0]);
		while (q)
			traverse_queue(colony, &q);
		if ((colony->paths = pathfinder(colony)) == NULL
			|| (!(colony->paths_temp) && colony->path_num == 0))
			 ft_error("Path from start to end does not exist");
		n_new = count_turns(colony);
		if (n_new < colony->n_turns)
			set_optimal_path(colony, n_new);
		else
		{
			free_paths(colony->paths, colony->path_num);
			break ;
		}
	}
	return (end_ed_karp(colony));
}

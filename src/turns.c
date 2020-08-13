/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:15:44 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/13 17:15:44 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	count_move_all_in_path(t_colony *colony, t_room *room)
{
	t_room *temp;

	temp = room;
	if (temp->level == MAX_INT)
		return ;
	if (temp->temp_next->level == MAX_INT && temp->ant_name != -1)
	{
		colony->ant_end++;
		if (colony->ant_end == colony->ant_num)
			return ;
	}
	while (temp->temp_prev)
	{
		temp->ant_name = temp->temp_prev->ant_name;
		temp->temp_prev->ant_name = -1;
		temp = temp->temp_prev;
	}
}

void	count_move_from_start(t_colony *colony, int i)
{
	colony->paths[i]->head->ant_name = colony->ant_num - colony->ant_start + 1;
	colony->ant_start--;
	if (colony->paths[i]->head->level == MAX_INT)
		colony->ant_end++;
}

void	no_ants(t_colony *colony)
{
	int i;

	i = 0;
	while (i < colony->room_num)
	{
		colony->rooms[i]->ant_name = -1;
		i++;
	}
}

t_room	*count_find_last_room(t_room *head)
{
	t_room *temp;

	temp = head;
	if (!temp->temp_next)
		return (temp);
	if (!temp->temp_next->temp_next)
		return (temp);
	while (temp->temp_next->temp_next)
		temp = temp->temp_next;
	return (temp);
}

int		count_turns(t_colony *colony)
{
	int		i;
	t_room	*tail;
	int		count;

	count = 0;
	while (colony->ant_end != colony->ant_num)
	{
		i = -1;
		while (++i < colony->path_num)
		{
			if (colony->ant_end == colony->ant_num)
				break ;
			tail = count_find_last_room(colony->paths[i]->head);
			count_move_all_in_path(colony, tail);
			count_move_all_in_path(colony, tail);
			if (colony->ant_start > colony->paths[i]->comp)
				count_move_from_start(colony, i);
		}
		count++;
	}
	colony->ant_start = colony->ant_end;
	colony->ant_end = 0;
	no_ants(colony);
	return (count);
}

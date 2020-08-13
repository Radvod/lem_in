/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:55:41 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/12 16:03:23 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_move(int *is_start, int ant_name, char *next_name)
{
	if (*is_start != 1)
		ft_printf(" ");
	else
		*is_start = -1;
	ft_printf("L%d-%s", ant_name, next_name);
}

void	move_all_in_path(t_colony *colony, t_room *room, int *is_start, int even)
{
	t_room	*temp;
	int		k;

	k = 0;
	temp = room;
	if (temp->level == MAX_INT)
		return ;
	if (temp->next->level == MAX_INT && temp->ant_name != -1)
	{
		colony->ant_end++;
		if (even == 1)
			print_move(is_start, temp->ant_name, temp->next->name);
		if (colony->ant_end == colony->ant_num)
			return ;
	}
	while (temp->prev)
	{
		temp->ant_name = temp->prev->ant_name;
		if (temp->ant_name != -1 && k % 2 == 1 && even == 1)
			print_move(is_start, temp->ant_name, temp->name);
		k++;
		temp->prev->ant_name = -1;
		temp = temp->prev;
	}
}

t_room	*find_last_room(t_room *head)
{
	t_room *temp;

	temp = head;
	if (!temp->next)
		return (temp);
	if (!temp->next->next)
		return (temp);
	while (temp->next->next)
		temp = temp->next;
	return (temp);
}

void	move_from_start(t_colony *colony, int i, int *is_start)
{
	colony->paths[i]->head->ant_name = colony->ant_num - colony->ant_start + 1;
	colony->ant_start--;
	print_move(is_start, colony->paths[i]->head->ant_name,
			   colony->paths[i]->head->name);
	if (colony->paths[i]->head->level == MAX_INT)
		colony->ant_end++;
}

void	move_ants(t_colony *colony)
{
	int		i;
	int		is_start;
	t_room	*tail;

	while (colony->ant_end != colony->ant_num)
	{
		i = 0;
		is_start = 1;
		while (i < colony->path_num)
		{
			if (colony->ant_end == colony->ant_num)
				break ;
			tail = find_last_room(colony->paths[i]->head);
			move_all_in_path(colony, tail, &is_start, 0);
			move_all_in_path(colony, tail, &is_start, 1);
			if (colony->ant_start > colony->paths[i]->comp)
				move_from_start(colony, i, &is_start);
			i++;
		}
		ft_printf("\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:54:39 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/12 15:56:54 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	flag_correction(t_colony *colony)
{
	int	i;

	i = 0;
	while (i < colony->room_num)
	{
		colony->rooms[i]->flag = 0;
		colony->rooms[i]->label = 0;
		colony->rooms[i]->prev = NULL;
		i++;
	}
}

void	level_correction(t_colony *colony, int flag, int k, int i)
{
	int	j;

	flag_correction(colony);
	while (k != 0)
	{
		k = 0;
		flag = 0;
		j = i;
		while (j < colony->room_num - 1)
		{
			if (colony->link_arr[k][j] == 1)
			{
				if (flag == 0)
				{
					i = j + 1;
					flag = 1;
				}
				colony->rooms[j]->level = colony->rooms[k]->level + 1;
				k = j;
				j = 1;
			}
			j++;
		}
	}
}

void	move_directly(t_colony *colony)
{
	int		i;
	t_room	*room;

	i = 0;
	room = colony->paths[0]->head;
	while (i < colony->ant_num)
	{
		ft_printf("L%d-%s", i + 1, room->name);
		if (i != colony->ant_num - 1)
			ft_printf(" ");
		i++;
	}
	ft_printf("\n");
}

int		start(t_colony *colony)
{
	int i;

	colony->rooms[0]->level = 0;
	colony->rooms[colony->room_num - 1]->level = MAX_INT;
	edmonds_karp(colony);
	if (colony->path_num == 0)
		ft_error("Error");
	i = 0;
	while (colony->line[i])
	{
		ft_printf("%s\n", colony->line[i]);
		i++;
	}
	ft_printf("\n");
	if (colony->paths[0]->len == 1)
		move_directly(colony);
	else
		move_ants(colony);
	return (0);
}

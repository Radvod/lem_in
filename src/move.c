/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:54:39 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/12 14:41:46 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_paths	*find_free_path(t_paths *paths)
{
	while (paths)
	{
		if (((t_room*)paths->path->next->data)->name_ant == 0)
			return (paths);
		paths = paths->next;
	}
	return (NULL);
}

t_links	*choose_path(t_paths *paths, int num_on_start)
{
	t_paths *path;

	if (!(path = find_free_path(paths)))
		return (NULL);
	if (path->len - paths->len >= num_on_start)
		return (NULL);
	return (path->path);
}

void	next_step(t_ant *ant, t_paths *paths)
 {
 	if (!ant->path)
 		ant->path = choose_path(paths, ant->room->num_ants);
 	if (ant->path)
	{
 		ant->room->num_ants--;
 		ant->room->name_ant = 0;
 		ant->path = ant->path->next;
 		ant->room = ((t_room*)(ant->path->data));
 		ant->room->name_ant = ant->name;
 		ant->room->num_ants++;
	}
 }

t_edge	*make_ants_line(t_room *start)
{
	t_edge	*edge;
	int		name;

	name = 1;
	edge = e_new(new_ant(name++, start));
	while (name < start->num_ants)
		e_add(&edge, new_ant(name++, start));
	return (edge)
}

int		move(t_room *start, t_paths *paths)
{
	t_edge	*edge;
	t_ant	*ant;
	t_ant	*tmp;
	int		steps;

	tmp = NULL;
	steps = 1;
	edge = make_ants_line(start);
	while ((ant = (t_ant*)e_get(&edge)))
	{
		next_step(ant, paths);
		if (!ant->room-is_end)
			e_add(&edge, ant);
		steps += print_step(ant, &tmp);
		if (ant->room->is_end)
			free(ant);
	}
	ft_printf("\n");
	return (steps);
}
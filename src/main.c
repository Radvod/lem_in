/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:47:17 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/12 15:46:22 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*find_start(t_room *head)
{
	while (head)
	{
		if (head->is_start)
			return (head);
		head = head->next;
	}
	return (NULL);
}

int		main(int argc, char **argv)
{
	t_room	*head;
	t_room	*start;
	t_paths	*paths;
	int		steps;

	head = read_rooms();
	start = find_start(head);
	if (!(paths = get_paths(start)))
		ft_error("There are no solutions!\n");
	steps = move(start, paths);
	clear(paths, head);
	return (0);
}

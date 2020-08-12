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

t_ant		*new_ant(int name, t_room *start)
{
	t_ant *new;

	new = (t_ant*)malloc(sizeof(t_ant));
	new->name = name;
	new->room = start;
	new->path = NULL;
	return (new);
}

int		get_num_ants(void)
{
	int		ants;
	char	*line;

	get_next_line(0, &line);
	ants = ft_atoi(line);
	if	(ants < 1 || ft_strchr(line, ' '))
		ants = -1;
	free(line);
	return (ants);
}

void	add_ants_to_start(int num, t_room *head)
{
	while (head)
	{
		if (head->is_start)
		{
			head->num_ants = num;
			break ;
		}
		head = head->next;
	}
}
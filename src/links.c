/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:42:03 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/11 13:56:48 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_links		*new_link(void *data)
{
	t_links *new;

	new = (t_links*)malloc(sizeof(t_links));
	new->data = data;
	new->next = NULL;
	return (new);
}

static void		add_link(t_room *room, t_room *new)
{
	t_links *tmp;

	if (!room || !new || new->is_start)
		return ;
	if (!room->links)
		room-links = new_link(new);
	else
	{
		tmp = room->links;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_link(new);
	}
}

static void		make_link(char *name1, char *name2, t_room *head)
{
	t_room *link1;
	t_room *link2;

	link1 = NULL;
	link2 = NULL;
	while ((!link1 || !link2) && head)
	{
		if (ft_strequ(head->room_name, name1))
			link1 = head;
		else if (ft_strequ(head->room_name, name2))
			link2 = head;
		head = head->next;
	}
	add_link(link1, link2);
	add_link(link2, link1);
}

void		read_links(char *line, t_room *head)
{
	char **data;

	data = ft_strsplit(line, '-');
	make_link(data[0], data[1], head);
	ft_stackfree(data);
	while (get_next_line(0, &line))
	{
		if (is_comment(line))
			continue ;
		data = ft_strsplit(line, '-');
		make_link(data[0], data[1], head);
		ft_stackfree(data);
		free(line);
	}
	free(line);
}
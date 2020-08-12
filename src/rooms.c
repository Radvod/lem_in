/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:50:54 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/12 16:03:23 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		set_new_room(t_room *new)
{
	new->is_end = 0;
	new->is_start = 0;
	new->name_ant = 0;
	new->num_ants = 0;
	new->links = NULL;
	new->next = NULL;
	new->pre = NULL;
}

static int			start_end(char *line, t_room *new)
{
	static int	i_s;
	static int i_e;

	if (!line && !new)
		return(i_s + i_e);
	if (ft_strstr(line, "##start"))
		new->is_start = 1;
	else if (ft_strstr(line, "##end"))
		new->is_end = 1;
	else
		return (0);
	i_e += (new->is_end) ? 1 : 0;
	i_s += (new->is_start) ? 1 : 0;
	if (i_e > 1 || i_s > 1)
		ft_error("Error");
	return(1);
}

static t_room		*new_room(char	*line)
{
	t_room	*new;
	char	**data;
	char	*new_line;

	new_line = line;
	new = (t_room*)malloc(sizeof(t_room));
	set_new_room(new);
	if (start_end(line, new))
		get_next_line(0, &new_line);
	data = ft_strsplit(new_line, ' ');
	new->name = ft_strdup(data[0]);
	new->y = ft_atoi(data[1]);
	new->x = ft_atoi(data[2]);
	ft_stackfree(data);
	if (new_line != line)
		free(new_line);
	return (new);
}
static t_room		*get_rooms(void)
{
	t_room	*head;
	t_room	*tmp;
	char	*line;

	get_next_line(0, &line);
	head = new_room(line);
	free(line);
	tmp = head;
	while (get_next_line(0, &line))
	{
		if (is_comment(line))
			continue ;
		if (ft_strchr(line, '-'))
			break ;
		tmp->next = new_room(line);
		tmp = tmp->next;
		free(line);
	}
	read_links(line, head);
	free(line);
	return (head);
}

t_room		*read_rooms(void)
{
	t_room	*new;
	int		ants_num;

	if	((ants_num = get_num_ants()) == -1)
		ft_error("No ants!\n");
	new = get_rooms();
	if (start_end(NULL, NULL) != 2)
		ft_error("No start or end!\n");
	add_ants_to_start(ants_num, new);
	return (new);
}
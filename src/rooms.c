/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:50:54 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/13 18:04:53 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_start_end(t_colony *colony, char **str, int i)
{
	int j;

	if (ft_strcmp(colony->line[i - 1], "##start") == 0)
		j = 0;
	else
		j = colony->room_num - 1;
	if (!(colony->rooms[j]->name = ft_memalloc(ft_strlen(str[0]) + 1)))
		ft_error("Room initialization error");
	if (colony->rooms[j]->name[0] == 'L' || colony->rooms[j]->name[0] == '#')
		ft_error("Invalid characters in the room name");
	valid_coord(colony, str, j);
	colony->rooms[j]->num = j;
}

void		get_out_room(t_colony *colony, char **str)
{
	if (!(colony->rooms[colony->i]->name = ft_strjoin(str[0], "'")))
		ft_error("Name error!");
	if (colony->rooms[colony->i]->name[0] == 'L' ||
			colony->rooms[colony->i]->name[0] == '#')
		ft_error("L or # in room name!");
	valid_coord(colony, str, colony->i);
	colony->rooms[colony->i]->num = colony->i;
	colony->rooms[colony->i]->d_flag = colony->i - 1;
	colony->link_arr[colony->i][colony->i - 1] = 4;
	colony->link_arr[colony->i - 1][colony->i] = 3;
	colony->i++;
}

int		get_room(t_colony *colony, char *line, int i, int j)
{
	char	**str;

	if (!(ft_check_space(line)))
		ft_error("Room error!");
	str = ft_strsplit(line, ' ');
	while (str[j])
		j++;
	if (j != 3)
	{
		ft_printf("%d\n", j);
		ft_error("Room error!");
	}
	j = start_end_check(colony, i - 1, str);
	if (j == 0)
		return (0);
	if (!(colony->rooms[colony->i]->name = ft_memalloc(ft_strlen(str[0]) + 1)))
		ft_error("Error");
	ft_strcpy(colony->rooms[colony->i]->name, str[0]);
	valid_coord(colony, str, colony->i);
	colony->rooms[colony->i]->num = colony->i;
	colony->i++;
	colony->rooms[colony->i - 1]->d_flag = colony->i;
	get_out_room(colony, str);
	str_free(str, 0);
	return (0);
}

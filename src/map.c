/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 14:03:55 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/13 17:32:59 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	is_start_end(t_colony *colony, char **line, int i)
{
	if (ft_strcmp(line[i], "##end") == 0 &&
		ft_strcmp(line[i - 1], "##start") == 0)
		ft_error("No start and end");
	if (ft_strcmp(line[i], "##end") == 0)
	{
		if (colony->e_r_flag == 1)
			ft_error("More then one end");
		colony->e_r_flag = 1;
	}
	else if (ft_strcmp(line[i], "##start") == 0)
	{
		if (colony->s_r_flag == 1)
			ft_error("More then one start");
		colony->s_r_flag = 1;
	}
}

int		get_link(t_colony *colony, char *line, int i, int j)
{
	int		k;
	char	**str;

	k = -1;
	str = ft_strsplit(line, '-');
	if (str[2] || !str[0] || !str[1])
	{
		many_dashes_link(colony, line, 0);
		return (str_free(str, 0));
	}
	while (i < colony->room_num)
	{
		if (ft_strcmp(colony->rooms[i]->name, str[0]) == 0 &&
			ft_strcmp(colony->rooms[i]->name, str[1]) == 0)
			ft_error("Link error!");
		if (ft_strcmp(colony->rooms[i]->name, str[0]) == 0)
			j = colony->rooms[i]->num;
		if (ft_strcmp(colony->rooms[i]->name, str[1]) == 0)
			k = colony->rooms[i]->num;
		i++;
	}
	is_link(colony, j, k, str);
	return (str_free(str, 0));
}

void	get_ant(t_colony *colony, char *line)
{
	int		j;

	j = 0;
	while (line[j] != '\0')
	{
		if (ft_isdigit(line[j]) == 0)
			ft_error("Ants error!");
		j++;
	}
	if (ft_atoi_plus(&colony->ant_num, line) == -1)
		ft_error("More ants then MAX_INT");
	if (colony->ant_num <= 0)
		ft_error("No ants!");
	colony->ant_start = colony->ant_num;
}

void		get_map_p2(t_colony *colony, int i)
{
	if (colony->line[i][0] != '#')
	{
		if (link_or_room(colony, colony->line[i], 1) == 0)
		{
			if (colony->e_r_flag == 0 || colony->s_r_flag == 0 ||
				get_link(colony, colony->line[i], 0, -1) == -1)
				ft_error("No room or links");
			colony->flag = 1;
		}
		else
		{
			if (colony->flag == 1 || get_room(colony, colony->line[i], i, 0) != 0)
				ft_error("Error");
		}
	}
}

void		get_map(t_colony *colony, int i)
{
	if (!(colony->rooms = (t_room **)malloc(sizeof(t_room*) * colony->room_num)))
		ft_error("Error");
	while (++i < colony->room_num)
		colony->rooms[i] = init_room();
	colony->link_arr = init_link_arr(colony);
	i = 0;
	while (colony->line[i][0] == '#')
		i++;
	get_ant(colony, colony->line[i]);
	i++;
	while (colony->line[i])
	{
		get_map_p2(colony, i);
		if (colony->i >= colony->room_num)
			ft_error("Error");
		i++;
	}
	if (colony->e_l_flag != 1 || colony->s_l_flag != 1)
		ft_error("No end or start link!");
}

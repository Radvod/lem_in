/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 11:58:47 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/13 14:18:12 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	empty_line_check(const char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\n')
		ft_error("Empty line!");
	while (line[i] != '\0')
	{
		if	(line[i] == '\n')
		{
			if (line[i + 1] && line[i + 1] == '\n')
				ft_error("Line error!");
		}
		i++;
	}
}

int		start_end_check(t_colony *colony, int i, char **str)
{
	while (colony->line[i][0] == '#')
	{
		if (ft_strcmp(colony->line[i], "##start") == 0 ||
			ft_strcmp(colony->line[i], "##end") == 0)
		{
			get_start_end(colony, str, i + 1);
			str_free(str, 0);
			return (0);
		}
		i--;
	}
	return(1);
}

void	room_num_check(t_colony *colony, int i)
{
	while (colony->line[i][0] == '#')
		i++;
	i++;
	while (colony->line[i])
	{
		if (colony->line[i][0] == '#')
			is_start_end(colony, colony->line, i);
		if (colony->line[i][0] != '#' && link_or_room(colony, colony->line[i], 0) != 1)
			break ;
		if (colony->line[i][0] != '#')
		{
			if ((colony->room_num - 1) * 2 == MAX_INT)
				ft_error("Too many rooms!");
			colony->room_num++;
		}
		i++;
	}
	colony->room_num = (colony->room_num - 1) * 2;
	if (colony->room_num < 2 || colony->e_r_flag == 0 || colony->s_r_flag == 0)
		ft_error("No end or start!");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:41:46 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/13 18:26:47 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	valid_coord(t_colony *colony, char **str, int n)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (j < 3)
	{
		while (str[j][i] != '\0')
		{
			if (ft_isdigit(str[j][i]) == 0)
				ft_error("Not numbers in coordinates");
			i++;
		}
		i = 0;
		j++;
	}
	if (ft_atoi_plus(&colony->rooms[n]->x, str[1]) == -1)
		ft_error("x > MAX_INT");
	if (ft_atoi_plus(&colony->rooms[n]->y, str[2]) == -1)
		ft_error("y > MAX_INT");
}

void	link_error(t_colony *colony, int j, int k, char **str)
{
	if (k == -1 || j == -1)
		ft_error("Link error!");
	if (k == 0 || j == 0)
	{
		if (colony->link_arr[j][k] == 3 || colony->link_arr[k][j] == 3)
			ft_error("Two same link!");
	}
	if (k == colony->room_num - 1 || j == colony->room_num - 1)
	{
		if (k == colony->room_num - 1)
			if (colony->link_arr[j + 1][k] == 3)
				ft_error("Two same link!");
		if (j == colony->room_num - 1)
			if (colony->link_arr[k + 1][j] == 3)
				ft_error("Two same link!");
	}
	else if (colony->link_arr[j][k + 1] == 4 ||
			 colony->link_arr[k][j + 1] == 4)
		ft_error("Two same link!");
}

void	is_link(t_colony *colony, int j, int k, char **str)
{
	link_error(colony, j, k, str);
	if (k != 0 && j != 0 && k != colony->room_num - 1 && j != colony->room_num - 1)
	{
		colony->link_arr[j][k + 1] = 4;
		colony->link_arr[k + 1][j] = 3;
		colony->link_arr[j + 1][k] = 3;
		colony->link_arr[k][j + 1] = 4;
	}
	if (k == 0 || j == 0)
	{
		colony->link_arr[j][k] = 3;
		colony->link_arr[k][j] = 3;
		colony->s_l_flag = 1;
	}
	else if (k == colony->room_num - 1 || j == colony->room_num - 1)
	{
		if (k == colony->room_num - 1)
			colony->link_arr[j + 1][k] = 3;
		if (j == colony->room_num - 1)
			colony->link_arr[k + 1][j] = 3;
		colony->e_l_flag = 1;
	}
}

void	same_nc_valid(t_colony *colony)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < colony->room_num)
	{
		while (j < colony->room_num)
		{
			/*if (i != j)
			{
				if (ft_strcmp(colony->rooms[i]->name, colony->rooms[j]->name) == 0 ||
					(colony->rooms[i]->x == colony->rooms[j]->x &&
					colony->rooms[i]->y == colony->rooms[j]->y))
				if (colony->rooms[i]->d_flag != colony->rooms[j]->num)
						ft_error("Same coordinate or room name!");
			}*/
			j++;
		}
		j = 0;
		i++;
	}
}

int		link_or_room(t_colony *colony, const char *line, int flag)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != ' ')
		i++;
	if (line[i] == ' ')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
			ft_error("Line error");
		else
			return (1);
	}
	i = 0;
	if (flag == 1 && colony->flag == 0)
		same_nc_valid(colony);
	while (line[i] != '\0')
	{
		if (line[i] == '-' || line[0] == '#')
			return (0);
		i++;
	}
	ft_error("Line error");
	return (0);
}

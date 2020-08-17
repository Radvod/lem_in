/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 12:43:45 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/13 17:27:19 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		buff_free(char *buff)
{
	if (buff)
		free(buff);
	return (ERROR);
}

void	free_rooms(t_lem_in *lem_in)
{
	int i;

	i = 0;
	while (i < (lem_in)->room_num && (lem_in)->rooms)
	{
		free((lem_in)->rooms[i]->name);
		free((lem_in)->rooms[i]);
		i++;
	}
	if ((lem_in)->rooms)
		free((lem_in)->rooms);
}

int		ft_str_free(char **str, int i)
{
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		if (str)
			free(str);
	}
	return (0);
}

int		free_all(t_lem_in *lem_in)
{
	int i;

	i = 0;
	if (lem_in)
	{
		while (i < (lem_in)->room_num && (lem_in)->link_arr)
		{
			if ((lem_in)->link_arr[i])
				free((lem_in)->link_arr[i]);
			i++;
		}
		if ((lem_in)->link_arr)
			free((lem_in)->link_arr);
		if ((lem_in)->rooms)
			free_rooms(lem_in);
		if ((lem_in)->paths)
			free_paths((lem_in)->paths, (lem_in)->path_num);
		if ((lem_in)->line)
			str_free((lem_in)->line, 0);
		free(lem_in);
	}
	return (ERROR);
}

void	free_paths(t_path **paths, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		free(paths[i]);
		i++;
	}
	if (paths)
		free(paths);
	paths = NULL;
}

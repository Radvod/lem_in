/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:47:17 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/13 17:21:25 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		**init_link_arr(t_lem_in *l_i)
{
	char	**new;
	int		i;
	int		j;

	if (!(new = (char **)malloc(sizeof(char *) * l_i->room_num)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < l_i->room_num)
	{
		if (!(new[i] = (char *)malloc(sizeof(char) * l_i->room_num)))
			return (NULL);
		while (j < l_i->room_num)
		{
			new[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (new);
}

t_room		*init_room(void)
{
	t_room		*new;

	if (!(new = (t_room *)malloc(sizeof(struct s_room))))
		return (NULL);
	new->level = -1;
	new->x = 0;
	new->y = 0;
	new->name = NULL;
	new->num_input = 0;
	new->num_output = 0;
	new->visited = 1;
	new->flag = 0;
	new->label = 0;
	new->ant_name = -1;
	new->d_flag = 0;
	new->next = NULL;
	new->temp_next = NULL;
	new->prev = NULL;
	new->temp_prev = NULL;
	return (new);
}

t_lem_in	*init_l_i(void)
{
	t_lem_in	*new;

	if (!(new = (t_lem_in *)malloc(sizeof(struct s_lem_in))))
		return (NULL);
	new->ant_num = 0;
	new->ant_start = 0;
	new->ant_end = 0;
	new->room_num = 0;
	new->link_num = 0;
	new->line = NULL;
	new->link_arr = NULL;
	new->flag = 0;
	new->s_r_flag = 0;
	new->e_r_flag = 0;
	new->s_l_flag = 0;
	new->e_l_flag = 0;
	new->i = 1;
	new->j = 0;
	new->n_turns = MAX_INT;
	new->paths_temp = NULL;
	return (new);
}

int		map_reading(int fd, t_lem_in *l_i)
{
	char	*buff;
	int		data;

	buff = (char*)ft_memalloc(B_SIZE + 1);
	if ((data = read(fd, buff, B_SIZE)) < 32)
	{
		ft_printf("Error map\n");
		return (buff_free(buff));
	}
	buff[data] = '\0';
	if (empty_line_check(buff) == ERROR)
		return (buff_free(buff));
	l_i->line = ft_strsplit(buff, '\n');
	if (room_num_check(l_i, 0) == ERROR)
		return (buff_free(buff));
	if (get_map(l_i, -1) == ERROR)
		return (buff_free(buff));
	free(buff);
	return (0);
}

int		main(int ac, char **av)
{
	t_lem_in	*l_i;
	char		tmp;

	if (ac == 1 && av[1] == NULL)
	{
		if (!(l_i = init_l_i()))
			return (0);
		if (read(0, &tmp, 0) == 0)
		{
			if (map_reading(0, l_i) == ERROR)
				return (free_all(l_i));
		}
		else
			return (free_all(l_i));
	}
	else
		return (0);
	start_algo(l_i);
	free_all(l_i);
	exit(0);
}

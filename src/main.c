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

char		**init_link_arr(t_colony *colony)
{
	char	**new;
	int		i;
	int		j;

	if (!(new = (char **)malloc(sizeof(char *) * colony->room_num)))
		ft_error("Initialization error");
	i = 0;
	j = 0;
	while (i < colony->room_num)
	{
		if (!(new[i] = (char *)malloc(sizeof(char) * colony->room_num)))
			ft_error("Initialization error");
		while (j < colony->room_num)
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
		ft_error("Initialization error");
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

void		map_read(t_colony *colony)
{
	char	*buff;
	int		data;

	buff = (char*)malloc(B_SIZE + 1);
	if	((data = read(0, buff, B_SIZE)) < 32)
		ft_error("Map reading error");
	buff[data] = '\0';
	empty_line_check(buff);
	colony->line = ft_strsplit(buff, '\n');
	room_num_check(colony, 0);
	get_map(colony, -1);
	free(buff);
}

t_colony	*init_colony(void)
{
	t_colony *new;

	if	(!(new = (t_colony*)malloc(sizeof(struct s_colony))))
		ft_error("Initialization error");
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

int		main(int argc, char **argv)
{
	t_colony	*colony;
	char		tmp;

	if (argc == 1 && argv[1] == NULL)
	{
		colony = init_colony();
		if (read(0, &tmp, 0) == 0)
			map_read(colony);
		else
			ft_error("Error");
	}
	else
		return (0);
	start(colony);
	free_all(colony);
	return (0);
}

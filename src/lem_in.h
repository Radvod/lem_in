/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:37:33 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/12 15:56:24 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include "../utils/utils.h"

typedef struct 		s_links
{
	void			*data;
	struct	s_links *next;
	struct	s_links	*back;
}					t_links;

typedef	struct		s_room
{
	char			*name;
	int				path_num;
	int				is_start;
	int				is_end;
	int				num_ants;
	int				name_ant;
	struct	s_room 	*next;
	struct	s_room 	*pre;
	int				x;
	int				y;
	t_links			*links;
}					t_room;

typedef struct		s_paths
{
	t_links			*path;
	int				num;
	int				len;
	struct	s_paths	*next;
}					t_paths;

typedef	struct		s_ant
{
	int				name;
	t_room			*room;
	t_links			*path;
}					t_ant;

typedef struct		s_edge
{
	void			*data;
	struct	s_edge	*next;
}					t_edge;

int			get_num_ants(void);
t_ant		*new_ant(int name, t_room *start);
t_room		*read_rooms(void);
void		read_links(char *line, t_room *head);
t_edge		*e_new(void *data);
void		*e_get(t_edge **edge);
void		e_add(t_edge **edge, void *data);
void		e_del(t_edge **edge);
void		e_del(t_edge **edge);
t_links		*new_link(void *data);
t_paths		*get_paths(t_room *start);
void 		checked_add(t_links *link, t_links *checked);
int			is_checked(t_links *link, t_links *checked);
void		clear_links(t_links *links);
void		clear_paths(t_paths *paths);
void		clear_rooms(t_room *rooms);
void		clear(t_paths *paths, t_room *rooms);
t_links		*reverse(t_links *path);
t_links		*find_path(t_room *start);
int			print_step(t_ant *ant, t_ant **tmp);
int			move(t_room *start, t_paths *paths);
void	add_ants_to_start(int num, t_room *head);

#endif

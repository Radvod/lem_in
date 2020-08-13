/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:37:33 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/13 17:34:42 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEM_IN_H
# define LEM_IN_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define B_SIZE 3000000

# include "../libft/libft.h"
# include "../utils/utils.h"

typedef	struct		s_room
{
	char			*name;
	int				num;
	int				x;
	int				y;
	int				level;
	int				num_input;
	int				num_output;
	int				visited;
	int				flag;
	int				label;
	int				d_flag;
	struct s_room	*next;
	struct s_room	*prev;
	struct s_room	*temp_next;
	struct s_room	*temp_prev;
	int				ant_name;
}					t_room;

typedef struct		s_path
{
	t_room			*head;
	int				comp;
	int				len;
	struct	s_paths	*next;
}					t_path;

typedef struct		s_queue
{
	t_room			*room;
	struct	s_queue	*next;
}					t_queue;

typedef struct		s_colony
{
	int				i;
	int				j;
	int				flag;
	int				s_r_flag;
	int				e_r_flag;
	int				s_l_flag;
	int				e_l_flag;
	int				ant_num;
	int				ant_start;
	int				ant_end;
	int				room_num;
	int				link_num;
	char			**link_arr;
	char			**line;
	t_room			**rooms;
	t_path			**paths;
	int				path_num;
	t_path			**paths_temp;
	int				path_num_temp;
	int				bfs_level;
	int				n_turns;
}					t_colony;

void		free_paths(t_path **paths, int num);
void		valid_coord(t_colony *colony, char **str, int n);
void		link_error(t_colony *colony, int j, int k, char **str);
void		is_link(t_colony *colony, int j, int k, char **str);
void		same_nc_valid(t_colony *colony);
int			link_or_room(t_colony *colony, const char *line, int flag);
void		empty_line_check(const char *line);
int			start_end_check(t_colony *colony, int i, char **str);
void		is_start_end(t_colony *colony, char **line, int i);
void		room_num_check(t_colony *colony, int i);
void		many_dashes_link(t_colony *colony, const char *line, int i);
int			get_room(t_colony *colony, char *line, int i, int j);
char		**init_link_arr(t_colony *colony);
void		get_map(t_colony *colony, int i);
void		get_start_end(t_colony *colony, char **str, int i);
t_room		*init_room(void);
t_queue		*new_queue_node(t_room *room);
void		find_path_backwards(t_colony *colony, int room_id);
int			find_level(t_colony *colony, int prev, int curr);
int			count_turns(t_colony *colony);
void		define_comp_num(t_path **paths, int num);
void		move_ants(t_colony *colony);
void		sort_paths(t_path **paths, int right);
void		free_all(t_colony *colony);
int			link_or_room(t_colony *colony, const char *line, int flag);
void		push_node(t_queue **queue, t_queue *node);
t_room		*pop_node(t_queue **queue);
void		free_queue(t_queue **queue);
void		set_optimal_path(t_colony *colony, int n_new);
void		refresh_visited_and_lvl(t_room **rooms, int num);
t_path		**pathfinder(t_colony *colony);
int			edmonds_karp(t_colony *colony);
int			start(t_colony *colony);

#endif

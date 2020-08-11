/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:37:33 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/11 13:31:14 by hgalazza         ###   ########.fr       */
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

int		get_num_ants(void);
t_room	*read_rooms(void);

#endif

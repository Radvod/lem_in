/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:39:31 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/11 17:20:50 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_links	*find_path(t_room *start)
{
	t_links *path;
	t_room	*tmp;
	t_links *checked;
	t_edge *edge;

	path = NULL;
	checked = new_link(start);
	edge = e_new(start);
	while ((tmp = (t_room*)e_get(&edge)))
	{
		if (tmp->is_end)
		{
			path = get_path(tmp, start);
			break ;
		}
	}
}
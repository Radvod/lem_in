/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:20:37 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/12 13:20:37 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	swap_links(t_links **next, t_links **back)
{
	t_links *tmp;

	tmp = *next;
	*next = *back;
	*back = tmp;
}

t_links	*reverse(t_links *path)
{
	t_links *rev;

	if (!path)
		return (NULL);
	while (path->next)
		path = path->next;
	rev = path;
	while (path)
	{
		swap_links(&path->next, &path->back);
		path = path->next;
	}
	return (rev);
}
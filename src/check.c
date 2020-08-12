/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 11:58:47 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/12 12:20:35 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_checked(t_links *link, t_links *checked)
{
	while (checked)
	{
		if (checked->data == link->data)
			return (1);
		checked = checked->next;
	}
	return (0);
}

void 	checked_add(t_links *link, t_links *checked)
{
	while (checked->next)
		checked = checked->next;
	checked->next = new_link(link->data)
}
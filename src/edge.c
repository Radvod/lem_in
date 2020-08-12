/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:25:11 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/12 15:51:25 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

t_edge	*e_new(void *data)
{
	t_edge *new;

	new = (t_edge*)malloc(sizeof(t_edge));
	new->data = data;
	new->next = NULL;
	return (new);
}

void	*e_get(t_edge **edge)
{
	void	*data;
	t_edge	*tmp;

	if (!*edge)
		return (NULL);
	data = (*edge)->data;
	tmp = *edge;
	*edge = (*edge)->next;
	free(tmp);
	tmp = NULL;
	return (data);
}

void	e_add(t_edge **edge, void *data)
{
	t_edge *new;

	new = *edge;
	if (!new)
	{
		*edge = e_new(data);
		return ;
	}
	while (new->next)
		new = new->next;
	new->next = (t_edge*)malloc(sizeof(t_edge));
	new = new->next;
	new->data = data;
	new->next = NULL;
}

void	e_del(t_edge **edge)
{
	t_edge *tmp;
	t_edge *lnext;

	if	(edge != NULL)
	{
		tmp = *edge;
		lnext = *edge;
		while (tmp != NULL)
		{
			tmp = lnext->next;
			free(lnext);
			lnext = tmp;
		}
		*edge = NULL;
	}
}

void	*e_check(t_edge *edge)
{
	return (edge) ? edge->data : NULL;
}

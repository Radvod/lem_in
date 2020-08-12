/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:11:45 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/12 15:42:57 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		print_step(t_ant *ant, t_ant **tmp)
{
	int step;

	step = (ant == *tmp) ? 1 : 0;
	ft_printf("%s", (ant == *tmp) ? "\n" : "");
	if (!ant->room->is_start)
		ft_printf("L%d-%s ", ant->name,\
		ant->room->name);
	if (!*tmp)
		*tmp = ant;
	if (ant->room->is_end && *tmp == ant)
		*tmp = NULL;
	return (step);
}
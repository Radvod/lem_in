/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:55:41 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/11 12:56:26 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_num_ants(void)
{
	int		ants;
	char	*line;

	get_next_line(0, &line);
	ants = ft_atoi(line);
	if	(ants < 1 || ft_strchr(line, ' '))
		ants = -1;
	free(line);
	return (ants);
}
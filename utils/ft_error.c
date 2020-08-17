/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:13:39 by hgalazza          #+#    #+#             */
/*   Updated: 2020/07/28 13:13:39 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		free_len(int *len)
{
	free(len);
	return (-1);
}

int		error(int flag, char **str)
{
	if (str)
		str_free(str, 0);
	if (flag == 1)
		ft_printf("Map error! No end or start link\n");
	if (flag == 2)
		ft_printf("Map error! Ant error\n");
	if (flag == 3)
		ft_printf("Map error! Error line\n");
	if (flag == 4)
		ft_printf("Map error! Same coordinate or room\n");
	if (flag == 5)
		ft_printf("Map error! Error link\n");
	if (flag == 6)
		ft_printf("Map error! Same link\n");
	if (flag == 7)
		ft_printf("Map error! Error room\n");
	if (flag == 8)
		ft_printf("Map error! Error coordinate\n");
	if (flag == 9)
		ft_printf("Map error! Too many rooms\n");
	if (flag == 10)
		ft_printf("Map error! Error end or start\n");
	if (flag == 11)
		ft_printf("Map error! Same end and start\n");
	return (-1);
}

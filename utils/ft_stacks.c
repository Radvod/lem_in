/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:25:01 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/05 14:32:42 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_stacklen(char **stc)
{
	int	i;

	i = 0;
	while (stc[i])
		i++;
	return (i);
}

int		ft_stackfree(char **stc)
{
	int i;

	i = 0;
	while (stc[i])
	{
		ft_strdel(&stc[i]);
		i++;
	}
	free(stc);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:38:57 by hgalazza          #+#    #+#             */
/*   Updated: 2020/07/07 15:27:57 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t i;
	size_t neg;
	size_t res;

	res = 0;
	neg = 0;
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		if (res <= 9223372036854775807)
			res = res * 10 + (str[i] - '0');
		else if (res > 9223372036854775807 && neg == 1)
			return (0);
		else
			return (-1);
		i++;
	}
	return ((neg == 0) ? ((int)res) : ((int)-res));
}

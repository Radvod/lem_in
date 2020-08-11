/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 17:03:55 by hgalazza          #+#    #+#             */
/*   Updated: 2020/07/17 19:39:36 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		approximator(char *fract, double nbr)
{
	int apr;
	int i;

	i = ft_strlen(fract);
	nbr *= 10;
	apr = (int)nbr;
	apr %= 10;
	if (apr >= 5)
		while (i)
		{
			if (fract[--i] != '9')
			{
				fract[i] += 1;
				return (0);
			}
			else
				fract[i] = '0';
		}
	else
		return (0);
	return (1);
}

char	*ft_ftoa_long(long double nbr, unsigned int precision)
{
	int			i;
	size_t		whole;
	char		fract[501];
	int			sign;
	char		ch;

	ch = (precision) ? '.' : '\0';
	sign = (nbr < 0) ? -1 : 1;
	nbr = nbr * sign;
	whole = (size_t)nbr;
	nbr -= whole;
	i = 0;
	while (precision--)
	{
		nbr *= 10;
		fract[i++] = (size_t)nbr % 10 + '0';
		nbr -= (size_t)nbr;
	}
	fract[i] = '\0';
	whole += approximator(fract, nbr);
	return (sign < 0) ? ft_str_un("-",\
	ft_str_un(ft_addch(ft_itoa_unsigned(whole), ch), fract, 3), 2)\
	: ft_str_un(ft_addch(ft_itoa_unsigned(whole), ch), fract, 3);
}

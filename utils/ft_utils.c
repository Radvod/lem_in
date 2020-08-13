/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:25:01 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/13 17:10:22 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		str_free(char **str, int i)
{
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		if (str)
			free(str);
	}
	return (0);
}

int		ft_check_space(const char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strfromcpy(char *dst, const char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (str[len] != '\0')
	{
		dst[i] = str[len];
		i++;
		len++;
	}
	dst[i] = '\0';
	return (dst);
}

static int		ft_if_neg(const char *str, int i)
{
	int neg;

	neg = 0;
	if (str[i] == '-')
		neg = 1;
	return (neg);
}

int				ft_atoi_plus(int *n, const char *str)
{
	int			i;
	int			neg;
	long long	res;

	i = 0;
	res = 0;
	if (str == NULL || str[i] == '\0')
		return (-1);
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13 && str[i] != '\0'))
		i++;
	if ((neg = ft_if_neg(str, i)) && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((!neg && (res * 10 + (str[i] - '0') > 2147483647))
			|| (neg && (res * 10 + (str[i] - '0') > 2147483648)))
			return (-1);
		res = res * 10 + (str[i++] - '0');
	}
	if (neg)
		res = -(res);
	*n = (int)res;
	return (1);
}


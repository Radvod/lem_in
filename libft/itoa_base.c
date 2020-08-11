/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:52:53 by hgalazza          #+#    #+#             */
/*   Updated: 2020/07/16 18:20:44 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_unsigned(size_t nbr)
{
	char ch;
	char *str;

	str = NULL;
	if (nbr >= 10)
		str = ft_itoa_unsigned(nbr / 10);
	ch = nbr % 10 + '0';
	return (ft_addch(str, ch));
}

char	*ft_itoa_long(long nbr)
{
	if (nbr < 0)
		return (ft_str_un("-", ft_itoa_unsigned(-nbr), 2));
	else
		return (ft_itoa_unsigned(nbr));
}

char	convert(int i)
{
	char *nums;

	nums = "0123456789abcdef";
	return (nums[i]);
}

char	*ft_itoa_base(unsigned int nbr, int base)
{
	char ch;
	char *str;

	str = NULL;
	if (nbr >= (unsigned int)base)
		str = ft_itoa_base(nbr / base, base);
	ch = convert((nbr % base));
	return (ft_addch(str, ch));
}

char	*ft_itoa_base_unsigned(size_t nbr, int base)
{
	char ch;
	char *str;

	str = NULL;
	if (nbr >= (size_t)base)
		str = ft_itoa_base_unsigned(nbr / base, base);
	ch = convert(nbr % base);
	return (ft_addch(str, ch));
}

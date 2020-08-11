/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_specifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 12:26:10 by mcathery          #+#    #+#             */
/*   Updated: 2020/07/14 13:46:21 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mod(t_flags *flags, const char *str)
{
	while (str[flags->length] == 'l')
	{
		flags->l_flag++;
		flags->length++;
	}
	while (str[flags->length] == 'h')
	{
		flags->h_flag++;
		flags->length++;
	}
	while (str[flags->length] == 'L')
	{
		flags->bl_flag = 1;
		flags->length++;
	}
}

int		valid_flags(const char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	else
		return (0);
}

void	ft_flags(t_flags *flags, const char *str)
{
	flags->prec = -1;
	while (valid_flags(str[flags->length]))
	{
		if (str[flags->length] == '-')
			flags->minus = 1;
		if (str[flags->length] == '+')
			flags->plus = 1;
		if (str[flags->length] == ' ')
			flags->space = 1;
		if (str[flags->length] == '#')
			flags->sharp = 1;
		if (str[flags->length] == '0')
			flags->nul = 1;
		flags->length++;
	}
	if (flags->plus)
		flags->space = 0;
	if (flags->minus)
		flags->nul = 0;
	if (flags->nul)
		flags->fill = '0';
	else
		flags->fill = ' ';
}

t_flags	work_spec(const char *str)
{
	t_flags	flags;

	ft_bzero(&flags, sizeof(t_flags));
	if (*str == '\0')
		return (flags);
	ft_flags(&flags, str);
	if (str[flags.length] >= '1' && str[flags.length] <= '9')
	{
		flags.width = ft_atoi(&str[flags.length]);
		while (str[flags.length] >= '0' && str[flags.length] <= '9')
			flags.length++;
	}
	if (str[flags.length] == '.')
	{
		flags.length++;
		flags.prec = ft_atoi(&str[flags.length]);
		while (str[flags.length] >= '0' && str[flags.length] <= '9')
			flags.length++;
	}
	ft_mod(&flags, str);
	flags.spec = (str[flags.length++]);
	return (flags);
}

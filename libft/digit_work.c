/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:03:20 by hgalazza          #+#    #+#             */
/*   Updated: 2020/07/17 18:13:39 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sharp_work(int spec, char *arg, int prec)
{
	if (!ft_strcmp(arg, "0") && spec != 'p')
		return (arg);
	if (!ft_strcmp(arg, "0") && spec == 'p' && !prec)
		arg[0] = '\0';
	if (spec == 'x' || spec == 'p')
		return (ft_str_un("0x", arg, 2));
	else if (spec == 'o' && (prec == -1 || prec == 0))
		return (ft_str_un("0", arg, 2));
	return (arg);
}

char	*prec_work(char *arg, char *tire, t_flags flags)
{
	int		len;
	char	*s;
	char	*dot;

	dot = ft_strchr(arg, '.');
	if (flags.spec != 'f' || !dot)
	{
		len = ft_strlen(arg);
		if (tire)
			len--;
	}
	else
		len = ft_strlen(dot) - 1;
	if (flags.prec > len)
	{
		s = ft_strnew(flags.prec - len);
		ft_memset(s, '0', flags.prec - len);
		s = (flags.spec != 'f') ? ft_str_un(s, arg, 1)\
		: ft_str_un(arg, s, 1);
		if (tire)
			ft_swap(ft_strchr(s, '-'), s);
		return (s);
	}
	return (arg);
}

char	*width_work(char *arg, t_flags flags, int len)
{
	char	*str;
	char	*tire;

	tire = ft_strchr(arg, '-');
	if (len < flags.width)
	{
		str = ft_strnew(flags.width - len);
		ft_memset(str, flags.fill, flags.width - len);
		if (flags.spec == 'd' && flags.space && flags.fill == '0' && !tire)
			str[0] = ' ';
		arg = (flags.minus) ?\
		ft_str_un(arg, str, 1) : ft_str_un(str, arg, 1);
		tire = ft_strchr(arg, '-');
		if (tire && flags.fill == '0')
			ft_swap(arg, tire);
		if (flags.sharp && flags.fill == '0' && (str = ft_strchr(arg, 'x')))
			ft_swap(str, arg + 1);
		if (!tire && flags.plus && flags.fill == '0' &&\
		(flags.spec == 'd' || flags.spec == 'f'))
			ft_swap(ft_strchr(arg, '0'), ft_strchr(arg, '+'));
	}
	else if (flags.space && (flags.spec == 'd' || flags.spec == 'f') && !tire)
		arg = ft_str_un(" ", arg, 2);
	return (arg);
}

char	*digit_work(char *arg, t_flags flags, char spec)
{
	char	*tire;

	flags.spec = spec;
	tire = ft_strchr(arg, '-');
	arg = prec_work(arg, tire, flags);
	if (flags.sharp || spec == 'p')
		arg = sharp_work(spec, arg, flags.prec);
	if (!flags.prec && !ft_strcmp(arg, "0")\
	&& (spec == 'x' || spec == 'o' || spec == 'd')\
	&& !(flags.sharp && spec == 'o'))
		arg[0] = '\0';
	if (!tire && flags.plus && (spec == 'd' || spec == 'f'))
		arg = ft_str_un("+", arg, 2);
	if (flags.prec != -1 && spec != 'f')
		flags.fill = ' ';
	arg = width_work(arg, flags, ft_strlen(arg));
	return (arg);
}

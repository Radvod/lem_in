/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_s_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:06:10 by hgalazza          #+#    #+#             */
/*   Updated: 2020/07/17 19:27:38 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		putstr_for_null_char(char *s)
{
	size_t i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			if (s[i] == '@')
				ft_putchar(0);
			else
				ft_putchar(s[i]);
			i++;
		}
	}
	return (i);
}

char	*str_work(char *arg, t_flags flags)
{
	char	*str;
	int		len;

	len = ft_strlen(arg);
	if (flags.prec != -1 && flags.prec < len &&\
	flags.spec != '%' && flags.spec != 'N')
	{
		arg[flags.prec] = '\0';
		len = flags.prec;
	}
	if (len < flags.width)
	{
		str = ft_strnew(flags.width - len);
		ft_memset(str, flags.fill, flags.width - len);
		if (flags.minus)
			arg = ft_str_un(arg, str, 1);
		else
			arg = ft_str_un(str, arg, 1);
	}
	return (arg);
}

char	*work_s_c(t_flags *flags, va_list *ap)
{
	char *str;
	char ch;

	str = NULL;
	if (flags->spec == 's')
	{
		str = va_arg(*ap, char *);
		if (str)
			str = str_work(ft_strdup(str), *flags);
		else
			str = str_work(ft_strdup("(null)"), *flags);
	}
	else if (flags->spec == 'c')
	{
		ch = (char)va_arg(*ap, int);
		if (ch)
			str = str_work(ft_addch(NULL, ch), *flags);
		else
		{
			flags->spec = 'N';
			str = str_work(ft_strdup("@"), *flags);
		}
	}
	return (str);
}

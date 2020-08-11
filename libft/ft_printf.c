/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:09:22 by hgalazza          #+#    #+#             */
/*   Updated: 2020/07/14 14:05:34 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	char	*str;
	t_flags	flags;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%' && *format)
		{
			ft_putchar(*format);
			format++;
			i++;
			continue ;
		}
		flags = (*format) ? work_spec(++format) : work_spec(format);
		if (!(str = work_variable(&flags, &ap)))
			continue ;
		format += flags.length;
		i += (flags.spec != 'N') ? ft_putstr(str) : putstr_for_null_char(str);
		ft_strdel(&str);
	}
	va_end(ap);
	return (i);
}

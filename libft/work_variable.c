/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:01:03 by hgalazza          #+#    #+#             */
/*   Updated: 2020/07/17 18:15:41 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*work_d_i_u(t_flags flags, va_list *ap)
{
	char *s;

	s = NULL;
	if (flags.spec == 'd' || flags.spec == 'i')
	{
		if (flags.h_flag == 1)
			s = ft_itoa((short)va_arg(*ap, int));
		else if (flags.h_flag == 2)
			s = ft_itoa((signed char)va_arg(*ap, int));
		else if (flags.l_flag)
			s = ft_itoa_long(va_arg(*ap, long));
		else
			s = ft_itoa(va_arg(*ap, int));
		s = digit_work(s, flags, 'd');
	}
	else if (flags.spec == 'u')
	{
		s = (flags.l_flag) ? ft_itoa_unsigned(va_arg(*ap, unsigned long))\
		: ft_itoa_unsigned(va_arg(*ap, unsigned int));
		if (*s == '0' && flags.prec == 0)
			s = (char *)malloc(sizeof(char *));
		s = digit_work(s, flags, 'u');
	}
	return (s);
}

char	*work_f_x(t_flags flags, va_list *ap)
{
	char *s;

	s = NULL;
	if (flags.spec == 'f')
	{
		if (flags.prec == -1)
			flags.prec = 6;
		if (flags.bl_flag)
			s = digit_work(ft_ftoa_long(va_arg(*ap, long double), flags.prec),\
			flags, 'f');
		else
			s = digit_work(ft_ftoa_long(va_arg(*ap, double),\
			flags.prec), flags, 'f');
	}
	else if (flags.spec == 'x' || flags.spec == 'X')
	{
		if (flags.l_flag)
			s = digit_work(ft_itoa_base_unsigned(va_arg(*ap, size_t), 16),\
			flags, 'x');
		else
			s = digit_work(ft_itoa_base(va_arg(*ap, int), 16), flags, 'x');
		if (flags.spec == 'X')
			ft_strupper(s);
	}
	return (s);
}

char	*work_o(t_flags flags, va_list *ap)
{
	char *s;

	s = NULL;
	if (flags.h_flag == 1)
		s = ft_itoa_base((unsigned short)va_arg(*ap, int), 8);
	else if (flags.h_flag == 2)
		s = ft_itoa_base((unsigned char)va_arg(*ap, int), 8);
	else if (flags.l_flag)
		s = ft_itoa_base(va_arg(*ap, long), 8);
	else
		s = ft_itoa_base(va_arg(*ap, int), 8);
	s = digit_work(s, flags, 'o');
	return (s);
}

char	*work_variable(t_flags *flags, va_list *ap)
{
	char *str;

	str = NULL;
	if ((flags->spec == 's') || (flags->spec == 'c'))
		str = work_s_c(flags, ap);
	else if (flags->spec == 'p')
		str = digit_work(ft_itoa_base_unsigned(va_arg(*ap, size_t), 16),\
		*flags, 'p');
	else if (flags->spec == '%')
		str = str_work(ft_strdup("%"), *flags);
	else if (flags->spec == '\0')
		return (NULL);
	else if (flags->spec == 'd' || flags->spec == 'i' || flags->spec == 'u')
		str = work_d_i_u(*flags, ap);
	else if (flags->spec == 'x' || flags->spec == 'X' || flags->spec == 'f')
		str = work_f_x(*flags, ap);
	else if (flags->spec == 'b')
		str = digit_work(ft_itoa_base(va_arg(*ap, int), 2), *flags, 'o');
	else if (flags->spec == 'o')
		str = work_o(*flags, ap);
	return (str);
}

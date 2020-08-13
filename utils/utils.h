/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:28:17 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/13 17:10:22 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"

void	ft_error(char *str);
char	*ft_strfromcpy(char *dst, const char *str, size_t len);
int		str_free(char **str, int i);
int		ft_check_space(const char *line);
int				ft_atoi_plus(int *n, const char *str);

#endif

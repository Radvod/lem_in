/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dashes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:42:03 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/11 13:56:48 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	second_name(t_colony *colony, char *str1, int i)
{
	while (i < colony->room_num)
	{
		if (ft_strcmp(colony->rooms[i]->name, str1) == 0 && colony->j != i)
			break ;
		i++;
	}
	free(str1);
	if (i < colony->room_num)
	{
		is_link(colony, colony->j, i, NULL);
		colony->j = 0;
		return ;
	}
	ft_error("Error");
}

int		first_name(t_colony *colony, const char *line, int k, const int *len)
{
	char	*str1;
	int		i;

	i = 0;
	while (colony->j < k)
	{
		if (!(str1 = ft_memalloc(len[colony->j] + 1)))
			ft_error("Error");
		str1 = ft_strncpy(str1, line, len[colony->j]);
		str1[len[colony->j] + 1] = '\0';
		while (i < colony->room_num)
		{
			if (ft_strcmp(colony->rooms[i]->name, str1) == 0)
				break ;
			i++;
		}
		free(str1);
		if (i < colony->room_num)
			break ;
		colony->j++;
		i = 0;
	}
	if (colony->j == k)
		ft_error("Error");
	return (i);
}

void	len_search(const char *line, t_colony *colony, int k, int *len)
{
	int		i;

	i = 1;
	if (k != (int)ft_strlen(line) && colony->j == 0)
		i = 0;
	colony->j = 0;
	if (i == 1)
		len[0] = 1;
	else
		while (line[i] == '-')
		{
			len[0] += 1;
			i++;
		}
	while (line[i] != '\0')
	{
		if (line[i] == '-')
		{
			colony->j++;
			len[colony->j] = len[colony->j - 1];
		}
		len[colony->j] += 1;
		i++;
	}
}

int		only_dashes(t_colony *colony, const char *line, int i, int k)
{
	while (line[i] == '-')
		i++;
	colony->j = i;
	while (line[i] != '\0')
	{
		if (line[i] == '-')
			k++;
		i++;
	}
	if (k == 0 && line[colony->j] != '\0')
		k = colony->j;
	if (k == 0)
		k = ft_strlen(line);
	return (k);
}

void	many_dashes_link(t_colony *colony, const char *line, int i)
{
	int		k;
	int		flag;
	int		*len;
	char	*str1;

	k = only_dashes(colony, line, i, 0);
	flag = colony->j;
	if (!(len = (int *)malloc(sizeof(int) * k + 1)))
		ft_error("Error");
	len_search(line, colony, k, len);
	len[colony->j + 1] = -1;
	colony->j = 0;
	i = first_name(colony, line, k, len);
	if (k == (int)ft_strlen(line) || flag != 0)
		k--;
	if (!(str1 = ft_memalloc(len[k] - len[colony->j])))
		ft_error("Error");
	str1 = ft_strfromcpy(str1, line, len[colony->j] + 1);
	colony->j = i;
	second_name(colony, str1, 0);
	free(len);
}

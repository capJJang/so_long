/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_of_map_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:25:54 by segan             #+#    #+#             */
/*   Updated: 2022/11/22 20:08:29 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validation_of_map_shape(t_info	*info)
{
	size_t	row_check;
	size_t	i;
	size_t	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		if (i)
		{
			if (row_check != ft_strlen(info->map[i]))
				print_error();
		}
		row_check = ft_strlen(info->map[i]);
		if (info->map[i][0] != '1' || info->map[i][row_check - 1] != '1')
			print_error();
		i++;
	}
	i--;
	while (info->map[i][j] == '1' && info->map[0][j] == '1')
		j++;
	if (j != row_check)
		print_error();
}

int	validation_of_map_path(t_info *info)
{
	t_info	temp_info;

	temp_info = *info;
	return (check_path(&temp_info, info->i, info->j));
}

int	check_path(t_info *info, int i, int j)
{
	if (info->map[i][j] == 'C')
		info->c--;
	else if (info->map[i][j] == 'E')
		info->e--;
	else if (info->map[i][j] == '0' || info->map[i][j] == 'P')
		;
	else
		return (0);
	info->map[i][j] = 'V';
	if (!info->c && !info->e)
		return (1);
	if (check_path(info, i + 1, j))
		return (1);
	if (check_path(info, i - 1, j))
		return (1);
	if (check_path(info, i, j + 1))
		return (1);
	if (check_path(info, i, j -1))
		return (1);
	return (0);
}

int	is_valid(t_info	*info, int i, int j)
{
	if (info->map[i][j] == '0')
		return (1);
	if (info->map[i][j] == 'C')
		return (1);
	if (info->map[i][j] == 'E')
		return (1);
	return (0);
}

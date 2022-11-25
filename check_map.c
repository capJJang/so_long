/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:46:12 by segan             #+#    #+#             */
/*   Updated: 2022/11/25 22:27:30 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"

t_info	*check_map(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		exit(0);
	info->map = get_map();
	check_map_p(info);
	check_map_c(info);
	check_map_e(info);
	validation_of_map_shape(info);
	if (validation_of_map_path(info) == 0)
		print_error();
	return (info);
}

char	**get_map(void)
{
	char	*ret;
	char	*temp;
	int		fd;

	fd = open("./map.ber", O_RDONLY);
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == 0)
		{
			free_arr_1d(temp);
			return (ft_split(ret, '\n'));
		}
		ret = ft_strjoin(ret, temp);
	}
	return (ft_split(ret, '\n'));
}

void	check_map_p(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	info->p = 0;
	while (info->map[++i])
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == 'P')
			{
				info->p++;
				info->j = j;
				info->i = i;
			}
		}
	}
	if (info->p != 1)
		return (print_error());
}

void	check_map_c(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	info->c = 0;
	while (info->map[++i])
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == 'C')
				info->c++;
		}
	}
	if (!info->c)
		return (print_error());
}

void	check_map_e(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	info->e = 0;
	while (info->map[++i])
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == 'E')
				info->e++;
			if (info->map[i][j] != '0' && info->map[i][j] != '1' && \
			info->map[i][j] != 'P' && info->map[i][j] != 'C' && \
			info->map[i][j] != 'E')
				print_error();
		}
	}
	if (info->e != 1)
		return (print_error());
}

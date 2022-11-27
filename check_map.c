/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:46:12 by segan             #+#    #+#             */
/*   Updated: 2022/11/28 03:39:22 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"

t_map	*check_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit(0);
	map->map = get_map();
	check_map_p(map);
	check_map_c(map);
	check_map_e(map);
	validation_of_map_shape(map);
	if (validation_of_map_path(map) == 0)
		print_error();
	return (map);
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
	close(fd);
	return (ft_split(ret, '\n'));
}

void	check_map_p(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->p = 0;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
			{
				map->p++;
				map->j = j;
				map->i = i;
			}
		}
	}
	if (map->p != 1)
		return (print_error());
}

void	check_map_c(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->c = 0;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'C')
				map->c++;
		}
	}
	if (!map->c)
		return (print_error());
}

void	check_map_e(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->e = 0;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'E')
				map->e++;
			if (map->map[i][j] != '0' && map->map[i][j] != '1' && \
			map->map[i][j] != 'P' && map->map[i][j] != 'C' && \
			map->map[i][j] != 'E')
				print_error();
		}
	}
	if (map->e != 1)
		return (print_error());
}

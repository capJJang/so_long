/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_of_map_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:25:54 by segan             #+#    #+#             */
/*   Updated: 2022/11/29 23:59:55 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validation_of_map_shape(t_map *map)
{
	size_t	row_check;
	size_t	i;
	size_t	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		if (i)
		{
			if (row_check != ft_strlen(map->map[i]))
				print_error();
		}
		row_check = ft_strlen(map->map[i]);
		if (map->map[i][0] != '1' || map->map[i][row_check - 1] != '1')
			print_error();
		i++;
	}
	i--;
	while (map->map[i][j] == '1' && map->map[0][j] == '1')
		j++;
	if (j != row_check)
		print_error();
	map->height = i + 1;
	map->width = j;
}

int	validation_of_map_path(t_map *map, char *argv)
{
	t_map	temp_map;
	int		ret;

	temp_map = *map;
	temp_map.map = get_map(argv);
	ret = check_path(&temp_map, map->i, map->j);
	free_all(temp_map.map);
	return (ret);
}

int	check_path(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'C')
		map->c--;
	else if (map->map[i][j] == 'E')
		map->e--;
	else if (map->map[i][j] == '0' || map->map[i][j] == 'P')
		;
	else
		return (0);
	map->map[i][j] = 'V';
	if (!map->c && !map->e)
		return (1);
	if (check_path(map, i + 1, j))
		return (1);
	if (check_path(map, i - 1, j))
		return (1);
	if (check_path(map, i, j + 1))
		return (1);
	if (check_path(map, i, j -1))
		return (1);
	return (0);
}

int	is_valid(t_map	*map, int i, int j)
{
	if (map->map[i][j] == '0')
		return (1);
	if (map->map[i][j] == 'C')
		return (1);
	if (map->map[i][j] == 'E')
		return (1);
	if (map->map[i][j] == 'P')
		return (1);
	return (0);
}

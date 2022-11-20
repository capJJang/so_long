/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:46:12 by segan             #+#    #+#             */
/*   Updated: 2022/11/20 22:30:26 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"

void	check_map(void)
{
	char	**map;

	map = get_map();
	validation_of_map_pce(map);
	validation_of_map_shape(map);
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

void	validation_of_map_pce(char **map)
{
	size_t	i;
	size_t	j;
	int		p;
	int		c;
	int		e;

	i = 0;
	p = 0;
	c = 0;
	e = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			else if (map[i][j] == 'C')
				c = 1;
			else if (map[i][j] == 'E')
				e++;
			else
				print_error();
			j++;
		}
		i++;
	}
	if (!p || !c || !e)
		print_error();
}

void	validation_of_map_shape(char **map)
{
	size_t	row_check;
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (i)
		{
			if (row_check != ft_strlen(map[i]))
				print_error();
		}
		row_check = ft_strlen(map[i]);
		if (map[i][0] != '1' || map[i][row_check - 1] != '1')
			print_error();
		i++;
	}
	i--;
	while (map[i][j] == '1' && map[0][j] == '1')
		j++;
	if (j != (row_check - 1))
		print_error();
}

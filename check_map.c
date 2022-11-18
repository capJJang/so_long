/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:46:12 by segan             #+#    #+#             */
/*   Updated: 2022/11/18 20:46:26 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"

void	check_map(void)
{
	char	*map;

	map = get_map();
	validation_of_map(map);
}

char	*get_map(void)
{
	char	*ret;
	char	*temp;
	int		fd;

	fd = open("./map.ber", O_RDONLY);
	while (1)
	{
		temp = get_next_line(fd);
		if (*temp == NULL)
		{
			free_arr(temp);
			return (ret);
		}
		ret = ft_strtrim(ft_strjoin(ret, temp), '\n');
	}
	return (ret);
}

void	validation_of_map(char *map)
{
	int		p;
	int		c;
	int		e;
	int		w;
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			e++;
		if (map[i] == 'C')
			c++;
		if (map[i] == 'E')
			e++;
		i++;
	}
	if (!p || !c || !e)
		print_error();
}

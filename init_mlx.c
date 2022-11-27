/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:27:55 by segan             #+#    #+#             */
/*   Updated: 2022/11/28 03:58:33 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

t_mlx	*init_mlx(t_map *map)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit(0);
	init_img(mlx);
	mlx->width = map->width * mlx->img->width;
	mlx->height = map->height * mlx->img->height;
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "so_long");
	if (!mlx->win)
		exit(0);
	draw_entire_map(mlx, map);
	return (mlx);
}

void	init_img(t_mlx *mlx)
{
	mlx->img = (t_img *)malloc(sizeof(t_img));
	mlx->img->p = mlx_xpm_file_to_image(mlx->mlx, "./assets/ship.xpm", \
	&mlx->img->width, &mlx->img->height);
	mlx->img->e = mlx_xpm_file_to_image(mlx->mlx, "./assets/exit.xpm", \
	&mlx->img->width, &mlx->img->height);
	mlx->img->w = mlx_xpm_file_to_image(mlx->mlx, "./assets/wall.xpm", \
	&mlx->img->width, &mlx->img->height);
	mlx->img->t = mlx_xpm_file_to_image(mlx->mlx, "./assets/tile.xpm", \
	&mlx->img->width, &mlx->img->height);
	mlx->img->c = mlx_xpm_file_to_image(mlx->mlx, "./assets/collectible.xpm", \
	&mlx->img->width, &mlx->img->height);
}

void	draw_entire_map(t_mlx *mlx, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == 'P')
				draw_p(mlx, j * mlx->img->width, i * mlx->img->height);
			else if (map->map[i][j] == 'C')
				draw_c(mlx, j * mlx->img->width, i * mlx->img->height);
			else if (map->map[i][j] == 'E')
				draw_e(mlx, j * mlx->img->width, i * mlx->img->height);
			else if (map->map[i][j] == '1')
				draw_w(mlx, j * mlx->img->width, i * mlx->img->height);
			else if (map->map[i][j] == '0')
				draw_t(mlx, j * mlx->img->width, i * mlx->img->height);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:38:54 by segan             #+#    #+#             */
/*   Updated: 2022/11/25 23:02:40 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mlx	*mlx;
	t_info	*map;
	
	map = check_map();
	mlx = init_mlx();
	int		img_width;
	int		img_height;
	void *ship_img = mlx_xpm_file_to_image(mlx->mlx, "./assets/ship.xpm", &img_width, &img_height);
	void *wall_img = mlx_xpm_file_to_image(mlx->mlx, "./assets/exit.xpm", &img_width, &img_height);
	void *exit_img = mlx_xpm_file_to_image(mlx->mlx, "./assets/wall.xpm", &img_width, &img_height);
	void *tile_img = mlx_xpm_file_to_image(mlx->mlx, "./assets/tile.xpm", &img_width, &img_height);
	
	mlx_put_image_to_window(mlx->mlx, mlx->win, tile_img, 0,0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, ship_img, 0,0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, wall_img, 128,0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, exit_img, 256,0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, tile_img, 384,0);
	mlx_loop(mlx->mlx);
}

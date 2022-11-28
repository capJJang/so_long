/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:38:54 by segan             #+#    #+#             */
/*   Updated: 2022/11/29 03:55:51 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	main(void)
{
	t_mlx	*mlx;
	t_map	*map;
	t_game	g;

	map = check_map();
	mlx = init_mlx(map);
	g.map = map;
	g.mlx = mlx;
	mlx_key_hook(mlx->win, press_key, &g);
	mlx_hook(mlx->win, 17, 0, click_mouse, (void *)&g);
	mlx_loop(mlx->mlx);
}

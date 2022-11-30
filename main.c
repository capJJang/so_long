/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:38:54 by segan             #+#    #+#             */
/*   Updated: 2022/11/30 22:22:02 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;
	t_map	*map;
	t_game	g;

	if (argc != 2)
		print_arg_error();
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		print_arg_error();
	map = check_map(argv[1]);
	mlx = init_mlx(map);
	g.map = map;
	g.mlx = mlx;
	mlx_key_hook(mlx->win, press_key, &g);
	mlx_hook(mlx->win, 17, 0, click_mouse, (void *)&g);
	mlx_loop(mlx->mlx);
}

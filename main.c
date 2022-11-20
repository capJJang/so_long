/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:38:54 by segan             #+#    #+#             */
/*   Updated: 2022/11/20 21:51:07 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	check_map();
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "test");
	mlx_loop(mlx);
}

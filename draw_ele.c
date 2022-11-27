/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ele.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:25:01 by segan             #+#    #+#             */
/*   Updated: 2022/11/28 04:27:10 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	draw_t(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->t, x, y);
}

void	draw_p(t_mlx *mlx, int x, int y)
{
	draw_t(mlx, x, y);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->p, x, y);
}

void	draw_c(t_mlx *mlx, int x, int y)
{
	draw_t(mlx, x, y);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->c, x, y);
}

void	draw_e(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->e, x, y);
}

void	draw_w(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->w, x, y);
}

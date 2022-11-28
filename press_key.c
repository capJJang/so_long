/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 05:08:33 by segan             #+#    #+#             */
/*   Updated: 2022/11/29 02:20:57 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	press_key(int key_code, t_game *g)
{
	if (key_code == 0)
	{
		if (is_valid(g->map, g->map->i, g->map->j - 1))
			mov(g, g->map->j - 1, g->map->i);
	}
	else if (key_code == 2)
	{
		if (is_valid(g->map, g->map->i, g->map->j + 1))
			mov(g, g->map->j + 1, g->map->i);
	}
	else if (key_code == 13)
	{
		if (is_valid(g->map, g->map->i - 1, g->map->j))
			mov(g, g->map->j, g->map->i - 1);
	}
	else if (key_code == 1)
	{
		if (is_valid(g->map, g->map->i + 1, g->map->j))
			mov(g, g->map->j, g->map->i + 1);
	}
	else if (key_code == 53)
		exit_so_long(g);
	return (0);
}

void	mov(t_game *g, int x, int y)
{
	if (g->map->map[y][x] == 'C')
		g->map->c--;
	if (!g->map->c && g->map->map[y][x] == 'E')
		exit_so_long(g);
	g->map->mov_cnt++;
	ft_printf("%d\n", g->map->mov_cnt);
	draw_p(g->mlx, x * g->mlx->img->width, y * g->mlx->img->height);
	draw_t(g->mlx, g->map->j * g->mlx->img->width, \
	g->map->i * g->mlx->img->width);
	if (g->map->map[g->map->i][g->map->j] == 'E')
		draw_e(g->mlx, g->map->j * g->mlx->img->width, \
		g->map->i * g->mlx->img->width);
	g->map->i = y;
	g->map->j = x;
}

void	exit_so_long(t_game *g)
{
	mlx_destroy_window(g->mlx->mlx, g->mlx->win);
	exit(0);
}

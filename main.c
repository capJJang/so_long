/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:38:54 by segan             #+#    #+#             */
/*   Updated: 2022/11/22 21:41:19 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	check_map();
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (0);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	if (!win_ptr)
		return (0);
	mlx_loop(mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:47:02 by segan             #+#    #+#             */
/*   Updated: 2022/12/01 02:03:32 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_error(void)
{
	write(1, "Error\n", 6);
	write(1, "invalid map\n", 12);
	exit(0);
}

void	print_mlx_error(void)
{
	write(1, "Error\n", 6);
	write(1, "mlx problem\n", 12);
	exit(0);
}

void	print_arg_error(void)
{
	write(1, "Error\n", 6);
	write(1, "invalid arg\n", 13);
	exit(0);
}

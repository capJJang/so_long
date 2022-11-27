/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:43:59 by segan             #+#    #+#             */
/*   Updated: 2022/11/28 02:52:46 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdlib.h>

typedef struct s_map
{
	int		i;
	int		j;
	int		p;
	int		c;
	int		e;
	char	**map;
	int		width;
	int		height;
}				t_map;

typedef struct s_img
{
	void	*p;
	void	*c;
	void	*e;
	void	*w;
	void	*t;
	int		width;
	int		height;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_img	*img;
}				t_mlx;

t_map	*check_map(void);
char	*get_next_line(int fd);
char	**get_map(void);
void	free_arr_1d(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	c_is_in_2darr(char **map, char c);
void	check_map_p(t_map *map);
void	check_map_c(t_map *map);
void	check_map_e(t_map *map);
void	validation_of_map_shape(t_map *map);
int		validation_of_map_path(t_map *map);
int		check_path(t_map *map, int i, int j);
void	print_error(void);
t_mlx	*init_mlx(t_map *map);
void	draw_entire_map(t_mlx *mlx, t_map *map);
void	init_img(t_mlx *mlx);
void	draw_t(t_mlx *mlx, int x, int y);
void	draw_p(t_mlx *mlx, int x, int y);
void	draw_c(t_mlx *mlx, int x, int y);
void	draw_e(t_mlx *mlx, int x, int y);
void	draw_w(t_mlx *mlx, int x, int y);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:43:59 by segan             #+#    #+#             */
/*   Updated: 2022/11/22 20:08:06 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdlib.h>

typedef struct s_info
{
	int		i;
	int		j;
	int		p;
	int		c;
	int		e;
	char	**map;
}				t_info;

void	check_map(void);
char	*get_next_line(int fd);
char	**get_map(void);
void	free_arr_1d(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	c_is_in_2darr(char **map, char c);
void	check_map_p(t_info *info);
void	check_map_c(t_info *info);
void	check_map_e(t_info *info);
void	validation_of_map_shape(t_info *info);
int		validation_of_map_path(t_info *info);
int		check_path(t_info *info, int i, int j);
void	print_error(void);

#endif
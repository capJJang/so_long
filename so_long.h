/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:43:59 by segan             #+#    #+#             */
/*   Updated: 2022/11/20 21:50:30 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdlib.h>

void	check_map(void);
char	*get_next_line(int fd);
char	**get_map(void);
void	free_arr_1d(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int o);
size_t	ft_strlen(const char *s);
void	validation_of_map_pce(char **map);
void	validation_of_map_shape(char **map);
void	print_error(void);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:43:59 by segan             #+#    #+#             */
/*   Updated: 2022/11/18 20:50:18 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

void	check_map(void);
char	*get_next_line(int fd);
char	*get_map(void);
void	free_arr(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *s2);
void	validation_of_map(char *map);
void	print_error(void);

#endif
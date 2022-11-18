/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:48:18 by segan             #+#    #+#             */
/*   Updated: 2022/11/18 18:00:46 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1000

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int o);
char	*concat_line(char *ret, char *buff, int read_count);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*free_arr(char **arr);
char	*slicing_line(char	*ret, char **leftover, int read_count);
char	*return_only_leftover(char **ret, char **leftover);

#endif

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segan <segan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 17:45:15 by segan             #+#    #+#              #
#    Updated: 2022/11/18 20:46:58 by segan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror $(FWKFLAGS) $(HDRFLAGS) $(LIBFLAGS) -o

FWKFLAGS = -framework OpenGl -framework AppKit

HDRFLAGS = -I /usr/local/include

LIBFLAGS = -L /usr/Local/lib/ -lmlx -L ./libft -l ft

SRCS = main.c check_map.c get_next_line.c get_next_line_utils.c print_error.c\
		free_arr.c

all = $(NAME)

$(NAME) :
	make -C ./libft
	$(CC) $(CFLAGS) $(NAME) $(SRCS)

clean :
	make clean -C ./libft

fclean :
	make fclean -C ./libft
	rm -rf $(NAME)

re :
	make fclean
	make all

.Phony : clean fclean re

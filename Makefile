# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segan <segan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 17:45:15 by segan             #+#    #+#              #
#    Updated: 2022/11/20 22:31:11 by segan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address $(FWKFLAGS) $(HDRFLAGS) $(LIBFLAGS) -o

FWKFLAGS = -framework OpenGl -framework AppKit

HDRFLAGS = -I /usr/local/include

LIBFLAGS = -L /usr/Local/lib/ -lmlx -L ./libft -l ft

SRCS = main.c check_map.c get_next_line.c get_next_line_utils.c print_error.c\
		free_arr_1d.c

all : $(NAME)

$(NAME) :
	make -C ./libft
	$(CC) $(CFLAGS) $(NAME) $(SRCS)

clean :
	make clean -C ./libft

fclean :
	make fclean -C ./libft
	rm -rf $(NAME)
	rm -rf $(NAME).dSYM

re :
	make fclean
	make all

.Phony : clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segan <segan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 17:45:15 by segan             #+#    #+#              #
#    Updated: 2022/11/29 23:51:10 by segan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror $(FWKFLAGS) $(HDRFLAGS) $(LIBFLAGS) -o

FWKFLAGS = -framework OpenGl -framework AppKit

HDRFLAGS = -I /usr/local/include

LIBFLAGS = -L /usr/Local/lib/ -lmlx -L ./libft -l ft -L ./ft_printf -l ftprintf

SRCS = main.c check_map.c get_next_line.c get_next_line_utils.c errors.c\
		free_arr_1d.c validation_of_map_path.c init_mlx.c draw_ele.c \
		press_key.c click_mouse.c

all : $(NAME)

$(NAME) :
	make -C ./libft
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(NAME) $(SRCS)

clean :
	make clean -C ./libft
	make clean -C ./ft_printf

fclean :
	make fclean -C ./libft
	make fclean -C ./ft_printf
	rm -rf $(NAME)

re :
	make fclean
	make all

.Phony : clean fclean re

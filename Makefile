# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segan <segan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 17:45:15 by segan             #+#    #+#              #
#    Updated: 2022/11/17 19:18:34 by segan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror $(FWKFLAGS) $(HDRFLAGS) $(LIBFLAGS) -o

FWKFLAGS = -framework OpenGl -framework AppKit

HDRFLAGS = -I /usr/local/include

LIBFLAGS = -L /usr/Local/lib/ -lmlx

SRCS = main.c

all = $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(NAME) $(SRCS)

clean :

fclean :
	rm -rf $(NAME)

re :
	make fclean
	make all

.Phony : clean fclean re

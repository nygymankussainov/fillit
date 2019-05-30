# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/05/30 19:36:47 by vhazelnu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

NAME = fillit

INCLUDES = -I ./ -I ./libft_v2.0/

SRC = fillit.c map.c fillmap.c print.c validation.c link_hash.c store_fig.c expand_map.c insert_fig.c fillmap2.c delete_row.c

OBJECTS = $(SRC:.c=.o)

LIB = -L ./libft_v2.0/ -lft

LIB_FOLDER = libft_v2.0/

all:
	@make -C $(LIB_FOLDER)
	gcc -Wall -Wextra -Werror $(SRC) $(LIB) $(INCLUDES) -o $(NAME) -g

clean:
	@make clean -C $(LIB_FOLDER)

fclean:	clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_FOLDER)

re:	fclean all

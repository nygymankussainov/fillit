# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/11/12 15:09:58 by vhazelnu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LOG_NOCOLOR = \033[0m
LOG_GREEN = \033[32m

NAME = fillit

INCLUDES = -I ./ -I ./libft/

LIBFT = ./libft/

LIB_A = ./libft/libft.a

SRC = fillit.c create_map.c fillmap.c print_map.c validation.c link_hash.c store_fig.c ft_free.c \
	expand_map.c insert_fig.c fillmap2.c force.c delete_row.c stack.c ft_delete_fig.c insert_matrix.c

SRCDIR = src
SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
OBJDIR = obj

CCFL = -Wall -Wextra -Werror

.PHONY: all clean fclean re obj_dir library

all: obj_dir library $(NAME)

obj_dir:
	@mkdir -p $(OBJDIR)

library:
	@make -sC $(LIBFT)

$(NAME): $(OBJ)
	@gcc $(CCFL) -o $(NAME) $(OBJ) $(LIB_A) $(INCLUDES)
	@echo "$(LOG_GREEN)Fillit has compiled successfully!$(LOG_NOCOLOR)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@gcc $(CCFL) -o $@ -c $< $(INCLUDES)

clean:
	@make clean -C $(LIBFT)
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)

re: fclean all

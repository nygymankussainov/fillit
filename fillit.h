/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:23:21 by deladia           #+#    #+#             */
/*   Updated: 2019/05/30 19:55:40 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

typedef struct			s_fig
{
	char				hash;
	size_t				i;
	struct s_fig		*right;
	struct s_fig		*left;
	struct s_fig		*up;
	struct s_fig		*down;
}						t_fig;

typedef struct			s_map
{
	char				letter;
	int					x;
	int					y;
	struct s_map		*right;
	struct s_map		*left;
	struct s_map		*up;
	struct s_map		*down;
}						t_map;

typedef struct			s_list_fig
{
	t_fig				*figure;
	struct s_list_fig	*next;
	struct s_list_fig	*prev;
}						t_list_fig;

int						ft_valid_1(char *buf);
int						ft_valid_2(char *buf);
void					print(t_map *m, int cnt);
int						ft_fillmap(t_map *map, t_list_fig *list);
void					link_hash(t_fig **fig);
void					link_hash_minus(t_fig **l1, t_fig **l2);
void					link_hash_plus(t_fig **l1, t_fig **l2);
void					store_fig(t_list_fig **list, char *buf, char letter);
void					create_fig(t_fig **fig, int i, char letter);
t_map					*create_map(int	a);
t_map					*create_cell(int x, int y);
t_map					*find(t_map *m, int x, int y);
t_list_fig				*create_list(t_list_fig **list, t_fig **hash);
void					add_row(t_map *m);
void					add_col(t_map *m);
void					ft_delete_fig(t_map *map, t_list_fig *list);
t_map					*insert_fig(t_map *map, t_map *matrix, t_list_fig *list, int a);
int						ft_sqrt1(int nb);
int						find_col(t_map *matrix);
t_map					*fillmap2(t_map *map, t_map *matrix, int y);
t_map					*delete_row(t_map *matrix);
void					print_matrix(t_map *matrix, int side);
t_map					*find_one(t_map *matrix, int y);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_fig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 20:21:31 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/11 15:22:31 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	find_matrix(t_map **matrix, int x, int y)
{
	while ((*matrix)->x != x)
	{
		if ((*matrix)->x > x)
			*matrix = (*matrix)->left;
		else if ((*matrix)->x < x)
			*matrix = (*matrix)->right;
	}
	while ((*matrix)->y != y)
	{
		if ((*matrix)->y > y)
			*matrix = (*matrix)->left;
		else if ((*matrix)->y < y)
			*matrix = (*matrix)->right;
	}
}

void	insert_hash(t_map **map, t_map **matrix, int a)
{
	int		i;
	int		j;

	i = 1;
	while (i <= a)
	{
		j = 1;
		while (j <= a)
		{
			find(map, i, j);
			if ((*map)->letter >= 'A' && (*map)->letter <= 'Z')
			{
				find_matrix(matrix, i, j);
				(*matrix)->letter = (*map)->letter;
			}
			j++;
		}
		i++;
	}
}

int		insert_fig_2(t_struct **str, int x, int key)
{
	int		y;

	y = 1;
	while (y <= (*str)->side)
	{
		find(&(*str)->map, x, y);
		if (ft_fillmap(&(*str)->map, &(*str)->list) == 1)
		{
			key = 1;
			if (!(*str)->matrix)
				insert_matrix_1(&(*str)->map, &(*str)->matrix, (*str)->side);
			else
				insert_matrix_2(&(*str)->map, &(*str)->matrix, (*str)->side);
		}
		ft_delete_fig(&(*str)->map, &(*str)->list);
		y++;
	}
	return (key);
}

void	ft_free(t_map **matrix)
{
	t_map *tmp;

	find_matrix(matrix, 1, 1);
	while ((*matrix)->up)
		*matrix = (*matrix)->up;
	while (*matrix)
	{
		if (!(*matrix)->left)
			while (*matrix)
			{
				tmp = *matrix;
				if (!(*matrix)->right)
				{
					if (!(*matrix)->down)
					{
						free(tmp);
						tmp = NULL;
						*matrix = NULL;
						return ;
					}
					*matrix = (*matrix)->down;
					break ;
				}
				*matrix = (*matrix)->right;
				free(tmp);
				tmp = NULL;
			}
		if (!(*matrix)->right)
			while (*matrix)
			{
				tmp = *matrix;
				if (!(*matrix)->left)
				{
					if (!(*matrix)->down)
					{
						free(tmp);
						tmp = NULL;
						*matrix = NULL;
						return ;
					}
					*matrix = (*matrix)->down;
					break ;
				}
				*matrix = (*matrix)->left;
				free(tmp);
				tmp = NULL;
			}
	}
}

int		insert_fig(t_struct **str)
{
	int		key;
	int		x;

	x = 1;
	key = 0;
	while (x <= (*str)->side)
	{
		key = insert_fig_2(str, x, key);
		x++;
	}
	if (key == 0)
	{
		add_col(&(*str)->map);
		add_row(&(*str)->map);
		(*str)->side++;
		ft_free(&(*str)->matrix);
		while ((*str)->list->prev)
			(*str)->list = (*str)->list->prev;
		insert_fig(str);
		return ((*str)->side);
	}
	return ((*str)->side);
}

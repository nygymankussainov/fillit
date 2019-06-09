/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_fig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 20:21:31 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/06/09 16:00:02 by vhazelnu         ###   ########.fr       */
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

void	print_matrix(t_map *matrix, int side)
{
	t_map	*ptr;
	int		i;
	int		j;

	i = 1;
	j = 1;
	find_matrix(&matrix, 1, 1);
	ptr = matrix;
	while (i <= side)
	{
		j = 1;
		while (j <= side)
		{
			find_matrix(&matrix, i, j);
			ptr = matrix;
			write(1, &ptr->letter, 1);
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
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
		insert_fig(str);
		return ((*str)->side);
	}
	return ((*str)->side);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_fig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 20:21:31 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/05/30 19:49:26 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*find_matrix(t_map *matrix, int	x, int y)
{
	t_map	*to_find;

	to_find = matrix;
	while (to_find->x != x)
	{
		if (to_find->x > x)
		{
			if (!to_find->left)
				break ;
			to_find = to_find->left;
		}
		else if (to_find->x < x)
		{
			if (!to_find->right)
				break ;
			to_find = to_find->right;
		}
	}
	while (to_find->y != y)
	{
		if (to_find->y > y)
		{
			if (!to_find->left)
				break ;
			to_find = to_find->left;
		}
		else if (to_find->y < y)
		{
			if (!to_find->right)
				break ;
			to_find = to_find->right;
		}
	}
	return (to_find);
}

int		find_col(t_map *matrix)
{
	int i;
	int j;
	int y;
	int min;

	y = 1;
	matrix = find_matrix(matrix, 1, 1);
	while (matrix->right)
	{
		i = 0;
		if (matrix->down)
		{
			while (matrix)
			{
				if (matrix->letter == '1')
					i++;
				if (!matrix->down)
					break ;
				matrix = matrix->down;
			}
		}
		else if (matrix->up)
		{
			while (matrix)
			{
				if (matrix->letter == '1')
					i++;
				if (!matrix->up)
					break ;
				matrix = matrix->up;
			}
		}
		if (y == 1 || (i > 0 && i < j))
		{
			min = y;
			j = i;
		}
		matrix = matrix->right;
		y++;
	}
	return (min);
}

void	print_matrix(t_map *matrix, int side)
{
	t_map	*ptr;
	int		i;
	int		j;

	i = 1;
	j = 1;
	matrix = find_matrix(matrix, 1, 1);
	ptr = matrix;
	while (i <= side)
	{
		j = 1;
		while(j <= side)
		{
			ptr = find_matrix(matrix, i, j);
			write(1, &ptr->letter, 1);
			j++;
		}
		i++;
	}
	write(1, "\n", 2);
}

void	insert_hash(t_map *map, t_map *matrix, int a) //ищет хэши и кладет в нужные места в матрице
{
	int		i;
	int		j;

	i = 1;
	while (i <= a)
	{
		j = 1;
		while (j <= a)
		{
			map = find(map, i, j);
			if ('A' <= map->letter && map->letter <= 'Z')
			{
				matrix = find_matrix(matrix, i, j);
				matrix->letter =  '1';
			}
			j++;
		}
		i++;
	}
}

t_map	*insert_matrix_1(t_map *map, t_map *matrix, int a) //создает первую строку матрицы
{
	int		i;
	int		j;

	i = 1;;
	while (i <= a)
	{
		j = 1;
		while (j <= a)
		{
			if (!matrix)
				matrix = create_cell(i, j);
			else
			{
				matrix->right = create_cell(i, j);
				matrix->right->left = matrix;
				matrix = matrix->right;
			}
			j++;
		}
		i++;
	}
	insert_hash(map, matrix, a);
///////////////////////////////////////
	// print_matrix(matrix, a);
	return (matrix);
}

t_map	*insert_matrix_2(t_map *map, t_map *matrix, int a) //создает остальные строки матрицы
{
	int		i;
	int		j;
	t_map	*ptr;

	i = 1;
	matrix = find_matrix(matrix, 1, 1);
	ptr = matrix;
	ptr->down = create_cell(1, 1);
	ptr->down->up = ptr;
	ptr = ptr->down;
	matrix = matrix->right;
	while (i <= a)
	{
		j = 1;
		while (j <= a)
		{
			if (i == 1 && j == 1)
			{
				j++;
				continue ;
			}
			ptr->right = create_cell(i, j);
			ptr->right->left = ptr;
			ptr->right->up = matrix;
			ptr = ptr->right;
			matrix->down = ptr;
			if (matrix->right)
				matrix = matrix->right;
			j++;
		}
		i++;
	}
	matrix = ptr;
	insert_hash(map, matrix, a);
///////////////////////////////////////
	// print_matrix(ptr, a);
	return (matrix);
}


t_map	*insert_fig(t_map *map, t_map *matrix, t_list_fig *list, int a)
{
	int		key;
	int		x;
	int		y;

	x = 1;
	key = 0;
	while (x <= a)
	{
		y = 1;
		while (y <= a)
		{
			map = find(map, x, y);
			if (ft_fillmap(map, list) == 1)
			{
				key = 1;
				// print(map, a);
				// write(1, "\n", 1);
				//нужно сделать что если matrix не существует вызываем insert_matrix
				//если существует вызываем add_row для matrix и хуевертим все дела
				if (!matrix)
					matrix = insert_matrix_1(map, matrix, a); //записывает в матрицу
				else
					matrix = insert_matrix_2(map, matrix, a);
				print_matrix(matrix, a);
			}
			ft_delete_fig(map, list);
			y++;
		}
		x++;
	}
	if (key == 0)
	{
		add_col(map);
		add_row(map);
		a++;
		insert_fig(map, matrix, list, a);
		printf("%d\n", a);
		return (matrix);
	}
	// printf("%d\n", a);
	return (matrix);
}

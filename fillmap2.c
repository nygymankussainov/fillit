/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillmap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:07:55 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/05/30 19:55:43 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*find_one(t_map *matrix, int y)
{
	int i;

	i = 1;
	while (matrix->left)
		matrix = matrix->left;
	while (matrix->up)
		matrix = matrix->up;
	while (i != y)
	{
		matrix = matrix->right;
		i++;
	}
	while (matrix->letter != '1')
		matrix = matrix->down;
	return (matrix);
}

void	fillmap3(t_map *map, int x, int y)
{
	map = find(map, x, y);
	map->letter = '#';
}

t_map	*fillmap2(t_map *map, t_map *matrix, int y)
{
	t_map *tmp;

	matrix = find_one(matrix, y);
	tmp = matrix;
	while (tmp)
	{
		if (tmp->letter == '1')
			fillmap3(map, tmp->x, tmp->y);
		if (!tmp->left)
			break ;
		tmp = tmp->left;
	}
	while (matrix)
	{
		if (matrix->letter == '1')
			fillmap3(map, matrix->x, matrix->y);
		if (!matrix->right)
			break ;
		matrix = matrix->right;
	}
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_row.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:47:10 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/05/30 20:13:43 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*delete_row(t_map *matrix)
{
	t_map *tmp1;
	t_map *tmp2;


	tmp1 = matrix->up;
	tmp2 = matrix->down;
	while (matrix)
	{
		while (matrix->up)
		{
			if (matrix->letter == '1')
			{
				while (matrix->right)
				{
					matrix->up->down = matrix->down;
					matrix->down->up = matrix->up;
					matrix = matrix->right;
				}
				while (matrix->left)
				{
					matrix->up->down = matrix->down;
					matrix->down->up = matrix->up;
					matrix = matrix->left;
				}
			}
			matrix = matrix->up;
		}
		while (matrix->down)
		{
			if (matrix->letter == '1')
			{
				while (matrix->right)
				{
					matrix->up->down = matrix->down;
					matrix->down->up = matrix->up;
					matrix = matrix->right;
				}
				while (matrix->left)
				{
					matrix->up->down = matrix->down;
					matrix->down->up = matrix->up;
					matrix = matrix->left;
				}
			}
			matrix = matrix->down;
		}
		matrix = matrix->right;
	}
	print_matrix(matrix, 4);
	return (matrix);
}

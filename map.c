/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:38:14 by deladia           #+#    #+#             */
/*   Updated: 2019/05/23 18:34:06 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*create_cell(int x, int y)
{
	t_map		*new_cell;

	new_cell = (t_map *)ft_memalloc(sizeof(t_map));
	new_cell->right = NULL;
	new_cell->left = NULL;
	new_cell->up = NULL;
	new_cell->down = NULL;
	new_cell->x = x;
	new_cell->y = y;
	new_cell->letter = '.';
	return (new_cell);
}

t_map		*create_map(int	a)
{
	int		x;
	int		y;
	t_map	*first;
	t_map	*second;

	x = 1;
	y = 1;
	first = create_cell(x, y);
	while (x < a)
	{
		y = 1;
		second = create_cell(x + 1, y);
		while (y < a)
		{
			if (x == 1)
			{
				first->right = create_cell(x, y + 1);
				first->right->left = first;
				first = first->right;
			}
			second->right = create_cell(x + 1, y + 1);
			second->right->left = second;
			second = second->right;
			y++;
		}
		while (y >= 1)
		{
			first->down = second;
			second->up = first;
			if (first->left && second->left)
			{
				first = first->left;
				second = second->left;
			}
			y--;
		}
		while (second->right)
			second = second->right;
		first = second;
		x++;
	}
	first = find(first, 1, 1);
	return (first);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 00:18:50 by deladia           #+#    #+#             */
/*   Updated: 2019/05/23 18:34:56 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add_row(t_map *m)
{
	t_map	*ptr;
	int		x;
	int		y;

	x = 1;
	y = 1;
	ptr = find(m, 1, 1);
	while (ptr->down)
	{
		ptr = ptr->down;
		x++;
	}
	ptr->down = create_cell(x + 1, y);
	ptr->down->up = ptr;
	ptr = ptr->down;
	m = find(m, x, 2);
	while (m)
	{
		y++;
		ptr->right = create_cell(x + 1, y);
		ptr->right->left = ptr;
		ptr->right->up = m;
		m->down = ptr->right;
		ptr = ptr->right;
		m = m->right;
	}
}

void	add_col(t_map *m)
{
	t_map	*ptr;
	int		x;
	int		y;

	x = 1;
	y = 1;
	ptr = find(m, 1, 1);
	while (ptr->right)
	{
		ptr = ptr->right;
		y++;
	}
	ptr->right = create_cell(x, y + 1);
	ptr->right->left = ptr;
	ptr = ptr->right;
	m = find(m, 2, y);
	while (m)
	{
		x++;
		ptr->down = create_cell(x, y + 1);
		ptr->down->up = ptr;
		ptr->down->left = m;
		m->right = ptr->down;
		ptr = ptr->down;
		m = m->down;
	}
}

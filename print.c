/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:16:30 by deladia           #+#    #+#             */
/*   Updated: 2019/05/23 18:34:45 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*find(t_map *m, int x, int y)
{
	t_map	*to_find;
	int		cur_x;
	int		cur_y;
	
	to_find = m;
	cur_x = to_find->x;
	cur_y = to_find->y;
	while (cur_x != x)
	{
	   if (cur_x > x)
	   {
		   to_find = to_find->up;
		   cur_x--;
	   }
	   else if (cur_x < x)
	   {
		   to_find = to_find->down;
		   cur_x++;
	   }
	}
	while (cur_y != y)
	{
	   if (cur_y > y)
	   {
		   to_find = to_find->left;
		   cur_y--;
	   }
	   else if (cur_y < y)
	   {
		   to_find = to_find->right;
		   cur_y++;
	   }
	}
	return(to_find);
}

void	print(t_map *m, int side)
{
	t_map	*ptr;
	int		i;
	int		j;

	i = 1;
	j = 1;
	m = find(m, 1, 1);
	ptr = m;
	while (i <= side)
	{
		j = 1;
		while(j <= side)
		{
			ptr = find(m, i, j);
			write(1, &ptr->letter, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

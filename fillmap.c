/* ************************************************************************** */
/*	                                                                    */
/*                                                        :::      ::::::::   */
/*   fillmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 20:05:53 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/05/23 02:02:12 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_delete_fig(t_map *map, t_list_fig *list)
{
	if (map->letter == list->figure->hash)
		map->letter = '.';
	if (!map->right && list->figure->right)
		return ;
	else if (list->figure->right && list->figure->right->hash == map->right->letter && map->right->letter == '.')
	{
		map = map->right;
		list->figure = list->figure->right;
		ft_delete_fig(map, list);
		map = map->left;
		list->figure = list->figure->left;
	}
	if (!map->down && list->figure->down)
		return ;
	else if (list->figure->down && list->figure->down->hash == map->down->letter && map->down->letter == '.')
	{
		map = map->down;
		list->figure = list->figure->down;
		ft_delete_fig(map, list);
		map = map->up;
		list->figure = list->figure->up;
	}
	if (!map->left && list->figure->left)
		return ;
	else if (list->figure->left && list->figure->left->hash == map->left->letter && map->left->letter == '.')
	{
		map = map->left;
		list->figure = list->figure->left;
		ft_delete_fig(map, list);
		map = map->right;
		list->figure = list->figure->right;
	}
	if (!map->up && list->figure->up)
		return ;
	else if (list->figure->up && list->figure->up->hash == map->up->letter && map->up->letter == '.')
	{
		map = map->up;
		list->figure = list->figure->up;
		ft_delete_fig(map, list);
		map = map->down;
		list->figure = list->figure->down;
	}
}

int		ft_fillmap(t_map *map, t_list_fig *list)
{
	int ret;

	ret = 1;
	if (map->letter != list->figure->hash)
		map->letter = list->figure->hash;
	if (!map->right && list->figure->right)
		return (0);
	else if (list->figure->right && list->figure->right->hash != map->right->letter && map->right->letter == '.')
	{
		map = map->right;
		list->figure = list->figure->right;
		if (ft_fillmap(map, list) == 0)
			ret = 0;
		map = map->left;
		list->figure = list->figure->left;
	}
	if (!map->down && list->figure->down)
		return (0);
	else if (list->figure->down && list->figure->down->hash != map->down->letter && map->down->letter == '.')
	{
		map = map->down;
		list->figure = list->figure->down;
		if (ft_fillmap(map, list) == 0)
			ret = 0;
		map = map->up;
		list->figure = list->figure->up;
	}
	if (!map->left && list->figure->left)
		return (0);
	else if (list->figure->left && list->figure->left->hash != map->left->letter && map->left->letter == '.')
	{
		map = map->left;
		list->figure = list->figure->left;
		if (ft_fillmap(map, list) == 0)
			ret = 0;
		map = map->right;
		list->figure = list->figure->right;
	}
	if (!map->up && list->figure->up)
		return (0);
	else if (list->figure->up && list->figure->up->hash != map->up->letter && map->up->letter == '.')
	{
		map = map->up;
		list->figure = list->figure->up;
		if (ft_fillmap(map, list) == 0)
			ret = 0;
		map = map->down;
		list->figure = list->figure->down;
	}
	return (ret);
}

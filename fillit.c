/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:24:15 by deladia           #+#    #+#             */
/*   Updated: 2019/05/30 19:56:24 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt1(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

t_list_fig	*create_list(t_list_fig **list, t_fig **hash)
{
	if (hash == NULL)
	{
		if (!(*list = (t_list_fig *)ft_memalloc(sizeof(t_list_fig))))
			return (0);
		(*list)->figure = NULL;
		(*list)->next = NULL;
		(*list)->prev = NULL;
	}
	else
	{
		if (!(*list)->figure)
			(*list)->figure = *hash;
		else
		{
			(*list)->next = (t_list_fig *)ft_memalloc(sizeof(t_list_fig));
			(*list)->next->figure = *hash;
			(*list)->next->prev = *list;
			(*list)->next->next = NULL;
			(*list) = (*list)->next;
		}
	}
	return (*list);
}

int				ft_read_2(int fd, t_list_fig **list, t_map **map, char letter)
{
	char		buf[22];
	size_t		cnt_fig;
	int			ret;
	int			ret_pre;
	t_map		*matrix;
	int 		m;

	cnt_fig = 0;
	matrix = NULL;
	while ((ret = read(fd, buf, 21)) >= 20)
	{
		buf[ret] = '\0';
		if (ft_valid_1(buf) == -1)
			return (-1);
		if (ft_valid_2(buf) == -1)
			return (-1);
		ret_pre = ret;
		store_fig(list, buf, letter);
		cnt_fig++;
		letter++;
	}
	if (ret != 0 || ret_pre != 20)
		return (-1);
	while ((*list)->prev)
		*list = (*list)->prev;
	while (*list)
	{
		*map = create_map(ft_sqrt1(4 * cnt_fig));
		matrix = insert_fig(*map, matrix, *list, ft_sqrt1(4 * cnt_fig));
		if (!(*list)->next)
			break ;
		*list = (*list)->next;
	}
	m = find_col(matrix);
	matrix = find_one(matrix, m);
	delete_row(matrix);
	*map = fillmap2(*map, matrix, m);
	print(*map, 4);
	printf("%d\n", m);
	return (0);
}

int				ft_read_1(int fd, t_list_fig **list, t_map **map)
{
	char		letter;

	letter = 'A';
	create_list(list, NULL);
	if (ft_read_2(fd, list, map, letter) < 0)
		return (-1);
	return (0);
}

int			main(/* int argc, char **argv */)
{
	int			fd;
	t_list_fig	*list;
	t_map		*map;
	// if (argc == 2)
	// {
		if ((fd = open("data", O_RDONLY)) < 0)
			return (-1);
		while (ft_read_1(fd, &list, &map) < 0)
		{
			ft_putstr("error");
			return (-1);
		}
		// else
		// {
			//ft_fillmap(&map, &list);
			// add_col(map);
			// add_row(map);
			// expand_map(&map);
			// ft_fillmap(&map, &list);
			// ft_delete_fig(&map, &list);
			// print(map, 3);
		// }	
	// }
	// else
	// 	ft_putstr("usage: ./fillit sample_file");
	return (0);
}

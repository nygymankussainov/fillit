/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:39:19 by deladia           #+#    #+#             */
/*   Updated: 2019/06/07 20:39:23 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			push(t_list_matrix **head, t_map **matrix)
{
	t_list_matrix	*tmp;

	tmp = (t_list_matrix *)ft_memalloc(sizeof(t_list_matrix));
	tmp->next = *head;
	tmp->matrix = *matrix;
	*head = tmp;
}

t_list_matrix	*pop(t_list_matrix **head)
{
	t_list_matrix	*out;

	out = *head;
	if (!(*head)->next)
		return (out);
	*head = (*head)->next;
	return (out);
}

t_map			*restore_row(t_list_matrix *stack)
{
	t_list_matrix	*ptr;
	t_map			*matrix;

	ptr = pop(&stack);
	find_matrix(&ptr->matrix, 1, 1);
	matrix = ptr->matrix;
	if (!matrix->up && !matrix->down)
		return (matrix);
	while (matrix)
	{
		if (matrix->up)
			matrix->up->down = matrix;
		if (matrix->down)
			matrix->down->up = matrix;
		if (!matrix->right)
			break ;
		matrix = matrix->right;
	}
	return (matrix);
}

t_map			*restore_all_in_stack(t_list_matrix **stack, int restore)
{
	t_map	*matrix;

	while (restore--)
	{
		matrix = restore_row(*stack);
		if (!(*stack)->next)
			break ;
		*stack = (*stack)->next;
	}
	return (matrix);
}

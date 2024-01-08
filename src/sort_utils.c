/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:36:50 by risasada          #+#    #+#             */
/*   Updated: 2023/10/30 16:36:55 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sort_check(t_stack *stack)
{
	t_node	*tmp;
	size_t	size;

	size = stack_size(stack);
	tmp = stack->head;
	if (size < 2)
		return (true);
	else if (size == 2 && tmp->index <= tmp->next->index)
		return (false);
	while (tmp->next != stack->head)
	{
		if (tmp->index <= tmp->next->index)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	sort_check_half(t_stack *stack, size_t init_size)
{
	t_node	*tmp;
	size_t	init_pivot;

	init_pivot = (init_size / 2);
	tmp = stack->head;
	while (init_pivot > 0)
	{
		if (tmp->index != init_pivot)
			return (false);
		tmp = tmp->next;
		init_pivot --;
	}
	return (true);
}

size_t	find_max_index(t_stack *stack)
{
	size_t	size;
	size_t	max_index;
	t_node	*tmp;

	tmp = stack->head;
	size = stack_size(stack);
	max_index = 0;
	while (size)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
		size --;
	}
	return (max_index);
}

size_t	find_min_index(t_stack *stack)
{
	size_t	size;
	size_t	min_index;
	t_node	*tmp;

	tmp = stack->head;
	size = stack_size(stack);
	min_index = SIZE_T_MAX;
	while (size)
	{
		if (tmp->index < min_index)
			min_index = tmp->index;
		tmp = tmp->next;
		size --;
	}
	return (min_index);
}

size_t	choose_pivot(t_stack *stack)
{
	size_t	max;
	size_t	min;

	max = find_max_index(stack);
	min = find_min_index(stack);
	return ((min + max) / 2);
}

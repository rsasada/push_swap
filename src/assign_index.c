/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:36:05 by risasada          #+#    #+#             */
/*   Updated: 2023/10/30 16:36:08 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "includes/ft_printf.h"
#include "libft/libft.h"

static t_node	*find_highest_for_assign_index(t_stack *stack);

void	assign_index(t_stack *stack_a)
{
	t_node	*highest;
	size_t	size;

	highest = NULL;
	size = stack_size(stack_a);
	while (size)
	{
		highest = find_highest_for_assign_index(stack_a);
		if (highest != NULL)
			highest->index = size;
		size --;
	}
}

static t_node	*find_highest_for_assign_index(t_stack *stack)
{
	size_t	size;
	int		value;
	t_node	*tmp;
	t_node	*highest;

	highest = NULL;
	size = stack_size(stack);
	value = INT_MIN;
	tmp = stack->head;
	while (size)
	{
		if (tmp->value == INT_MIN && tmp->index == 0)
				tmp->index = 1;
		if (tmp->value > value && tmp->index == 0)
		{
			value = tmp->value;
			highest = tmp;
		}
			tmp = tmp->next;
		size --;
	}
	return (highest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:12:03 by risasada          #+#    #+#             */
/*   Updated: 2023/10/27 17:12:09 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "includes/ft_printf.h"

int	swap_stack(t_stack *stack)
{
	size_t	size;
	t_node	*node1;
	t_node	*node2;

	if (stack == NULL || stack->head == NULL)
		return (-1);
	size = stack_size(stack);
	if (size < 2)
		return (-1);
	node1 = stack->head->prev;
	node2 = stack->head->prev->prev;
	if (size == 2)
	{
		rotate(stack);
		return (0);
	}
	node2->prev->next = node1;
	node1->next = node2;
	node1->prev = node2->prev;
	node2->prev = node1;
	node2->next = stack->head;
	stack->head->prev = node2;
	return (0);
}

int	sa(t_stack *stack)
{
	if (-1 == swap_stack(stack))
		return (-1);
	ft_printf("sa\n");
	return (0);
}

int	sb(t_stack *stack)
{
	if (-1 == swap_stack(stack))
		return (-1);
	ft_printf("sb\n");
	return (0);
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_a) < 2 || stack_size(stack_b) < 2)
		return (-1);
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
	return (0);
}

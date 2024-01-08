/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:55:04 by risasada          #+#    #+#             */
/*   Updated: 2023/10/27 20:55:06 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "includes/ft_printf.h"

int	reverse_rotate(t_stack *stack)
{
	size_t	size;

	size = stack_size(stack);
	if (!stack || !stack->head || size < 2)
		return (-1);
	stack->head = stack->head->next;
	return (0);
}

int	rra(t_stack *stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_printf("rra\n");
	return (0);
}

int	rrb(t_stack *stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_printf("rrb\n");
	return (0);
}

int	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_a) < 2 || stack_size(stack_b) < 2)
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rrr\n");
	return (0);
}

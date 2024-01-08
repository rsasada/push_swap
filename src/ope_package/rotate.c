/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:00:15 by risasada          #+#    #+#             */
/*   Updated: 2023/10/27 19:00:17 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "includes/ft_printf.h"

int	rotate(t_stack *stack)
{
	size_t	size;

	size = stack_size(stack);
	if (!stack || !stack->head || size < 2)
		return (-1);
	stack->head = stack->head->prev;
	return (0);
}

int	ra(t_stack *stack)
{
	if (rotate(stack) == -1)
		return (-1);
	ft_printf("ra\n");
	return (0);
}

int	rb(t_stack *stack)
{
	if (rotate(stack) == -1)
		return (-1);
	ft_printf("rb\n");
	return (0);
}

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_a) < 2 || stack_size(stack_b) < 2)
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
	return (0);
}

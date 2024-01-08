/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:34:39 by risasada          #+#    #+#             */
/*   Updated: 2023/10/27 17:34:46 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "includes/ft_printf.h"

int	push(t_stack *stack1, t_stack *stack2)
{
	t_node	*top_stack1;
	t_node	*top_stack2;
	t_node	*popped_node;

	top_stack1 = stack1->head->prev;
	popped_node = stack1->head->prev;
	if (stack2->head == NULL)
	{
		top_stack1 = top_stack1->prev;
		top_stack1->next = stack1->head;
		stack1->head->prev = top_stack1;
		stack2->head = popped_node;
		stack2->head->next = popped_node;
		stack2->head->prev = popped_node;
		return (0);
	}
	top_stack2 = stack2->head->prev;
	top_stack1 = top_stack1->prev;
	top_stack1->next = stack1->head;
	stack1->head->prev = top_stack1;
	popped_node->prev = top_stack2;
	popped_node->next = stack2->head;
	stack2->head->prev = popped_node;
	top_stack2->next = popped_node;
	return (0);
}

int	push_last_one(t_stack *stack1, t_stack *stack2)
{
	t_node	*last_node;
	t_node	*top_stack2;

	last_node = stack1->head;
	top_stack2 = stack2->head->prev;
	stack1->head = NULL;
	top_stack2->next = last_node;
	last_node->next = stack2->head;
	last_node->prev = top_stack2;
	stack2->head->prev = last_node;
	return (0);
}

int	pa(t_stack *stack_b, t_stack *stack_a)
{
	size_t	size;

	size = stack_size(stack_b);
	if (!stack_a || !stack_b || !size)
		return (-1);
	if (size == 1)
		push_last_one(stack_b, stack_a);
	else
		push(stack_b, stack_a);
	ft_printf("pa\n");
	return (0);
}

int	pb(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size;

	size = stack_size(stack_a);
	if (!stack_a || !stack_b || !size)
		return (-1);
	if (size == 1)
		push_last_one(stack_a, stack_b);
	else
		push(stack_a, stack_b);
	ft_printf("pb\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:36:37 by risasada          #+#    #+#             */
/*   Updated: 2023/10/30 16:36:39 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_6_or_under(t_stack *stack_a, t_stack *stack_b);
static bool	judge_ra_or_rra(t_stack *stack);

void	sort_3(t_stack *stack)
{
	t_node	*tmp;
	size_t	idx[3];

	if (stack == NULL || stack->head == NULL || stack_size(stack) != 3)
		return ;
	tmp = stack->head;
	idx[0] = tmp->index;
	idx[1] = tmp->next->index;
	idx[2] = tmp->prev->index;
	if (idx[0] < idx[1] && idx[1] > idx[2] && idx[0] > idx[2])
	{
		rra(stack);
		sa(stack);
	}
	else if (idx[0] < idx[1] && idx[1] > idx[2] && idx[0] < idx[2])
		rra(stack);
	else if (idx[0] > idx[1] && idx[1] < idx[2] && idx[0] > idx[2])
		sa(stack);
	else if (idx[0] > idx[1] && idx[1] < idx[2] && idx[0] < idx[2])
		ra(stack);
	else if (idx[0] < idx[1] && idx[1] < idx[2])
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_3_for_stack_b(t_stack *stack)
{
	t_node	*tmp;
	size_t	idx[3];

	if (stack == NULL || stack->head == NULL || stack_size(stack) != 3)
		return ;
	tmp = stack->head;
	idx[0] = tmp->index;
	idx[1] = tmp->next->index;
	idx[2] = tmp->prev->index;
	if (idx[0] < idx[1] && idx[1] > idx[2] && idx[0] > idx[2])
	{
		rrb(stack);
		sb(stack);
	}
	else if (idx[0] < idx[1] && idx[1] > idx[2] && idx[0] < idx[2])
		rrb(stack);
	else if (idx[0] > idx[1] && idx[1] < idx[2] && idx[0] > idx[2])
		sb(stack);
	else if (idx[0] > idx[1] && idx[1] < idx[2] && idx[0] < idx[2])
		rb(stack);
	else if (idx[0] < idx[1] && idx[1] < idx[2])
	{
		sb(stack);
		rrb(stack);
	}
}

void	sort_6_or_under(t_stack *stack_a, t_stack *stack_b)
{
	size_t	min_index;
	size_t	size;
	bool	flag;

	min_index = 1;
	flag = judge_ra_or_rra(stack_a);
	size = stack_size(stack_a);
	while (size > 3)
	{
		while (stack_a->head->prev->index != min_index)
		{
			if (flag == true)
				rra(stack_a);
			else
				ra(stack_a);
		}
		pb(stack_a, stack_b);
		size --;
		min_index ++;
	}
	if (sort_check(stack_a) != true)
		sort_3(stack_a);
	while (min_index --)
		pa(stack_b, stack_a);
}

static bool	judge_ra_or_rra(t_stack *stack)
{
	t_node	*tail;
	size_t	size;

	tail = stack->head;
	size = stack_size(stack);
	if (tail->index == 1)
		return (true);
	else
		return (false);
}

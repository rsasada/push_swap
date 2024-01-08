/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:10:54 by risasada          #+#    #+#             */
/*   Updated: 2023/10/29 20:10:56 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "includes/ft_printf.h"

bool	is_split_to_limit(t_stack *stack_a, t_stack *stack_b);
size_t	split_stack_b_by_pivot(t_stack *stack_a, t_stack *stack_b);
void	quick_sort(t_stack *stack_a, t_stack *stack_b);
void	split_stack_a_in_half(t_stack *stack_a, t_stack *stack_b);

void	sort_7_or_above(t_stack *stack_a, t_stack *stack_b)
{
	size_t	init_size;
	size_t	count_pb;

	init_size = stack_size(stack_a);
	split_stack_a_in_half(stack_a, stack_b);
	if (sort_check_half(stack_a, init_size) != true)
		quick_sort(stack_a, stack_b);
	count_pb = init_size - (init_size / 2);
	if (sort_check(stack_a) != true)
	{
		while (count_pb)
		{
			pb(stack_a, stack_b);
			count_pb --;
		}
		quick_sort(stack_a, stack_b);
	}
}

void	split_stack_a_in_half(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*top;
	size_t	size;
	size_t	pivot;

	size = stack_size(stack_a);
	pivot = size / 2;
	while (size)
	{
		top = stack_a->head->prev;
		if (top->index <= pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		size --;
	}
}

void	quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size_b;
	size_t	count_pa;

	count_pa = 0;
	size_b = stack_size(stack_b);
	if (is_split_to_limit(stack_a, stack_b) == true)
		return ;
	else if (size_b > 3)
	{
		count_pa = split_stack_b_by_pivot(stack_a, stack_b);
		quick_sort(stack_a, stack_b);
	}
	while (count_pa)
	{
		pb(stack_a, stack_b);
		count_pa --;
	}
	quick_sort(stack_a, stack_b);
}

size_t	split_stack_b_by_pivot(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*top;
	size_t	pivot;
	size_t	size_b;
	size_t	count_pa;

	size_b = stack_size(stack_b);
	pivot = choose_pivot(stack_b);
	count_pa = 0;
	while (count_pa != size_b / 2)
	{
		top = stack_b->head->prev;
		if (top->index > pivot)
		{
			pa(stack_b, stack_a);
			count_pa ++;
		}
		else
			rb(stack_b);
	}
	return (count_pa);
}

bool	is_split_to_limit(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size_b;

	size_b = stack_size(stack_b);
	if (size_b > 3)
		return (false);
	if (size_b == 3)
		sort_3_for_stack_b(stack_b);
	else if (size_b == 2 && sort_check(stack_b) == false)
		sb(stack_b);
	while (size_b > 0)
	{
		pa(stack_b, stack_a);
		ra(stack_a);
		size_b --;
	}
	return (true);
}

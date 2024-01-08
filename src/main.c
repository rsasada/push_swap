/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:27:27 by risasada          #+#    #+#             */
/*   Updated: 2023/10/22 21:27:29 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "includes/ft_printf.h"

void	free_stack(t_stack	*stack);

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	size_t	init_size;

	if (argc < 2)
		return (0);
	ft_check_args(argc, argv);
	init_stack_a(&stack_a, 0, argc, argv);
	assign_index(&stack_a);
	init_size = stack_size(&stack_a);
	if (sort_check(&stack_a) == true)
		init_size = 0;
	if (init_size == 2)
		sa(&stack_a);
	else if (init_size == 3)
		sort_3(&stack_a);
	else if (init_size > 3 && init_size <= 6)
		sort_6_or_under(&stack_a, &stack_b);
	else if (init_size > 6)
		sort_7_or_above(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	exit (0);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	size_t	size;

	size = stack_size(stack);
	if (size == 0)
		return ;
	if (size == 1)
	{
		free(stack->head);
		return ;
	}
	tmp = stack->head;
	while (size > 0)
	{
		if (size != 1)
			tmp = stack->head->next;
		free(stack->head);
		if (size != 1)
			stack->head = tmp;
		size --;
	}
	stack->head = NULL;
}

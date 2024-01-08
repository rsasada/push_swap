/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:23:25 by risasada          #+#    #+#             */
/*   Updated: 2023/10/23 16:23:26 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "includes/ft_printf.h"
#include "libft/libft.h"

void	insert_node_at_end(t_stack *stack, int data);

void	init_stack_a(t_stack *stack_a, ssize_t count, int argc, char **argv)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		while (args[count])
			count ++;
		count --;
	}
	else
	{
		args = argv;
		count = argc - 1;
	}
	while (count > 0)
	{
		insert_node_at_end(stack_a, ft_atoi(args[count]));
		count --;
	}
	if (argc == 2)
	{
		insert_node_at_end(stack_a, ft_atoi(args[0]));
		ft_free_all(args);
	}
}

t_node	*new_node(void)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		handle_error("Memory allocation failed.");
	new->index = 0;
	new->value = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	insert_node_at_end(t_stack *stack, int data)
{
	t_node	*tmp;
	t_node	*new;

	new = new_node();
	if (stack->head == NULL)
	{
		stack->head = new;
		stack->head->value = data;
		stack->head->next = stack->head;
		stack->head->prev = stack->head;
		return ;
	}
	tmp = stack->head->prev;
	tmp->next = new;
	stack->head->prev = new;
	new->prev = tmp;
	new->next = stack->head;
	new->value = data;
}

size_t	stack_size(t_stack *stack)
{
	size_t	count;
	t_node	*tmp;

	if (stack == NULL || stack->head == NULL)
		return (0);
	count = 1;
	tmp = stack->head;
	while (tmp->next != stack->head)
	{
		tmp = tmp->next;
		count ++;
	}
	return (count);
}

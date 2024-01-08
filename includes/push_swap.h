/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:03:12 by risasada          #+#    #+#             */
/*   Updated: 2023/11/08 16:03:14 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	size_t			index;
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	struct s_node	*head;
}	t_stack;

int		ps_atoi(const char *str);
void	ft_free_all(char **args);
void	ft_check_args(int argc, char **argv);

size_t	stack_size(t_stack *stack);
void	init_stack_a(t_stack *stack_a, ssize_t count, int argc, char **argv);
void	assign_index(t_stack *stack_a);

int		sa(t_stack *stack);
int		sb(t_stack *stack);
int		ss(t_stack *stack_a, t_stack *stack_b);

int		pa(t_stack *stack_b, t_stack *stack_a);
int		pb(t_stack *stack_a, t_stack *stack_b);

int		rotate(t_stack *stack);
int		ra(t_stack *stack);
int		rb(t_stack *stack);
int		rr(t_stack *stack_a, t_stack *stack_b);

int		rra(t_stack *stack_a);
int		rrb(t_stack *stack_b);
int		rrr(t_stack *stack_a, t_stack *stack_b);

void	sort_3(t_stack *stack);
void	sort_3_for_stack_b(t_stack *stack);
void	sort_6_or_under(t_stack *stack_a, t_stack *stack_b);
void	sort_7_or_above(t_stack *stack_a, t_stack *stack_b);
bool	sort_check(t_stack *stack);
bool	sort_check_half(t_stack *stack, size_t init_size);

size_t	find_max_index(t_stack *stack);
size_t	find_min_index(t_stack *stack);
size_t	choose_pivot(t_stack *stack);

#endif

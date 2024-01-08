/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:53:39 by risasada          #+#    #+#             */
/*   Updated: 2023/10/22 21:53:44 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "includes/ft_printf.h"
#include "libft/libft.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ps_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		if (!ft_isdigit(num[1]))
			return (0);
		i++;
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	int		tmp;
	char	**args;	

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (args == NULL || args[0] == NULL)
			handle_error("Error");
	}
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ps_atoi(args[i]);
		if (ft_contains(tmp, args, i) || !ft_isnum(args[i]))
			handle_error("Error");
		i++;
	}
	if (argc == 2)
		ft_free_all(args);
}

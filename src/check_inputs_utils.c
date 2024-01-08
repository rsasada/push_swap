/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:00:34 by risasada          #+#    #+#             */
/*   Updated: 2023/11/08 16:00:37 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	"includes/ft_printf.h"
#include	"libft/libft.h"

static void	short_cut(size_t *j, int *i, char *str);
static int	check_overflow(long n, char c, int sign);

int	ps_atoi(const char *str)
{
	int		n;
	int		i;
	size_t	j;
	int		sign;

	n = 0;
	j = 0;
	i = 1;
	sign = 0;
	if (*str == '\0')
		return (0);
	short_cut(&j, &i, (char *)str);
	while (str[j] >= '0' && str[j] <= '9')
	{
		sign = check_overflow(n, str[j], i);
		if (sign == 1)
			handle_error("Error");
		else if (sign == -1)
			handle_error("Error");
		n *= 10;
		n += str[j] - 48;
		j ++;
	}
	return ((int)(n * i));
}

static void	short_cut(size_t *j, int *i, char *str)
{
	while (((str[*j] <= 13 && str[*j] >= 9) || str[*j] == 32) && str[*j])
	{
		*j += 1;
	}
	if (str[*j] == '-')
	{
		*j += 1;
		*i *= -1;
	}
	else if (str[*j] == '+')
		*j += 1;
}

static int	check_overflow(long n, char c, int sign)
{
	if (n > (INT_MAX / 10))
	{
		if (sign == 1)
			return (1);
		else if (sign == -1)
			return (-1);
	}
	else if (sign == 1 && n == (INT_MAX / 10)
		&& (c - '0') > (INT_MAX % 10))
	{
		return (1);
	}
	else if (sign == -1 && n == (INT_MAX / 10)
		&& (c - '0') > (INT_MAX % 10) + 1)
	{
		return (-1);
	}
	return (0);
}

void	ft_free_all(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i ++;
	}
	if (i != 0)
		free(args);
}

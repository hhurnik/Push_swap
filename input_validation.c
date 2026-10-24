/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:45:47 by hhurnik           #+#    #+#             */
/*   Updated: 2024/12/09 20:32:08 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	are_all_arguments_empty(int argc, char **argv)
{
	int	j;
	int	i;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isspace(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_in_int_range(char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		num = num * 10 + (*str - '0');
		if (sign == 1 && num > 2147483647)
			return (0);
		if (sign == -1 && (-1) * num < -2147483648)
			return (0);
		str++;
	}
	return (1);
}

int	is_sorted(int *stack, int size)
{
	int	i;

	if (!stack || size <= 1)
		return (1);
	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// Function to display error and exit
void	display_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_isspace(char c)
{
	return (c == 32 || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v');
}

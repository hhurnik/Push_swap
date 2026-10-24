/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:55:04 by hhurnik           #+#    #+#             */
/*   Updated: 2024/12/04 17:52:18 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// the first becomes the last in both stack a and stack b
void	rr(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	temp;
	int	i;

	temp = (*stack_a)[0];
	i = 0;
	while (i < *size_a - 1)
	{
		(*stack_a)[i] = (*stack_a)[i + 1];
		i++;
	}
	(*stack_a)[i] = temp;
	temp = (*stack_b)[0];
	i = 0;
	while (i < *size_b - 1)
	{
		(*stack_b)[i] = (*stack_b)[i + 1];
		i++;
	}
	(*stack_b)[i] = temp;
	printf("%s\n", "rr");
}

// the last becomes the first
void	rra(int **stack_a, int *size_a)
{
	int	i;
	int	temp;

	if (*size_a < 2)
		return ;
	i = 0;
	temp = (*stack_a)[*size_a - 1];
	i = *size_a - 1;
	while (i > 0)
	{
		(*stack_a)[i] = (*stack_a)[i - 1];
		i--;
	}
	(*stack_a)[0] = temp;
	printf("%s\n", "rra");
}

// the last becomes the first
void	rrb(int **stack_b, int *size_b)
{
	int	i;
	int	temp;

	if (*size_b < 2)
		return ;
	i = 0;
	temp = (*stack_b)[*size_b - 1];
	i = *size_b - 1;
	while (i > 0)
	{
		(*stack_b)[i] = (*stack_b)[i - 1];
		i--;
	}
	(*stack_b)[0] = temp;
	printf("%s\n", "rrb");
}

void	rrr(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	i;
	int	temp;

	temp = (*stack_a)[*size_a - 1];
	i = *size_a - 1;
	while (i > 0)
	{
		(*stack_a)[i] = (*stack_a)[i - 1];
		i--;
	}
	(*stack_a)[0] = temp;
	temp = (*stack_b)[*size_b - 1];
	i = *size_b - 1;
	while (i > 0)
	{
		(*stack_b)[i] = (*stack_b)[i - 1];
		i--;
	}
	(*stack_b)[0] = temp;
	printf("%s\n", "rrr");
}

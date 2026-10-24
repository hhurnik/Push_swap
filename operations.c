/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:46:38 by hhurnik           #+#    #+#             */
/*   Updated: 2024/12/09 18:48:24 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(int **stack_a, int *size_a)
{
	int	temp;

	if (*size_a > 1)
	{
		temp = (*stack_a)[0];
		(*stack_a)[0] = (*stack_a)[1];
		(*stack_a)[1] = temp;
		printf("%s\n", "sa");
	}
}

void	sb(int **stack_b, int *size_b)
{
	int	temp;

	if (*size_b > 1)
	{
		temp = (*stack_b)[0];
		(*stack_b)[0] = (*stack_b)[1];
		(*stack_b)[1] = temp;
		printf("%s\n", "sb");
	}
}

void	ss(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	temp;

	if (*size_a > 1)
	{
		temp = (*stack_a)[0];
		(*stack_a)[0] = (*stack_a)[1];
		(*stack_a)[1] = temp;
	}
	if (*size_b > 1)
	{
		temp = (*stack_b)[0];
		(*stack_b)[0] = (*stack_b)[1];
		(*stack_b)[1] = temp;
	}
	printf("%s\n", "ss");
}

// the first becomes the last
void	ra(int **stack_a, int *size_a)
{
	int	temp;
	int	i;

	i = 0;
	if (*stack_a == NULL || *size_a < 2)
		return ;
	temp = (*stack_a)[0];
	while (i < *size_a - 1)
	{
		(*stack_a)[i] = (*stack_a)[i + 1];
		i++;
	}
	(*stack_a)[*size_a - 1] = temp;
	printf("%s\n", "ra");
}

void	rb(int **stack_b, int *size_b)
{
	int	temp;
	int	i;

	i = 0;
	if (*stack_b == NULL || *size_b < 2)
		return ;
	temp = (*stack_b)[0];
	while (i < *size_b - 1)
	{
		(*stack_b)[i] = (*stack_b)[i + 1];
		i++;
	}
	(*stack_b)[*size_b - 1] = temp;
	printf("%s\n", "rb");
}

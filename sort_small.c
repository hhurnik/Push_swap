/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:11:21 by hhurnik           #+#    #+#             */
/*   Updated: 2024/12/04 19:42:50 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_two(int **stack_a, int *size_a)
{
	if (*size_a == 2 && ((*stack_a)[1] < (*stack_a)[0]))
	{
		sa(stack_a, size_a);
	}
}

void	sort_three(int **stack_a, int *size_a)
{
	if ((*stack_a)[0] < (*stack_a)[1] && (*stack_a)[1] > (*stack_a)[2]
		&& (*stack_a)[0] < (*stack_a)[2])
	{
		sa(stack_a, size_a);
		ra(stack_a, size_a);
	}
	if ((*stack_a)[0] < (*stack_a)[1] && (*stack_a)[1] > (*stack_a)[2]
		&& (*stack_a)[0] > (*stack_a)[2])
		rra(stack_a, size_a);
	if ((*stack_a)[0] > (*stack_a)[1] && (*stack_a)[1] < (*stack_a)[2]
		&& (*stack_a)[0] < (*stack_a)[2])
		sa(stack_a, size_a);
	if ((*stack_a)[0] > (*stack_a)[1] && (*stack_a)[1] > (*stack_a)[2]
		&& (*stack_a)[0] > (*stack_a)[2])
	{
		sa(stack_a, size_a);
		rra(stack_a, size_a);
	}
	if ((*stack_a)[0] > (*stack_a)[1] && (*stack_a)[1] < (*stack_a)[2]
		&& (*stack_a)[0] > (*stack_a)[2])
		ra(stack_a, size_a);
}

// przerzucanie z b do a, jesli w a sa 3 posortowane, a w b tylko 1 element
void	fourth(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	if ((*stack_b)[0] > (*stack_a)[2])
	{
		pa(stack_a, stack_b, size_a, size_b);
		ra(stack_a, size_a);
	}
	else if ((*stack_b)[0] > (*stack_a)[1])
	{
		rra(stack_a, size_a);
		pa(stack_a, stack_b, size_a, size_b);
		rra(stack_a, size_a);
		rra(stack_a, size_a);
	}
	else if ((*stack_b)[0] > (*stack_a)[0])
	{
		ra(stack_a, size_a);
		pa(stack_a, stack_b, size_a, size_b);
		rra(stack_a, size_a);
	}
	else
	{
		pa(stack_a, stack_b, size_a, size_b);
	}
}

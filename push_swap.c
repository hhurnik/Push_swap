/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:37:20 by hhurnik           #+#    #+#             */
/*   Updated: 2024/12/09 19:09:05 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_first_two(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	if (*size_a >= 5)
	{
		pb(stack_a, stack_b, size_a, size_b);
		pb(stack_a, stack_b, size_a, size_b);
	}
}

// wziac id najmniejszego kosztu, wyciagnac pairs[id], sprawdzic czy rra/ra
// i to zrobic dla B
// potem dla A,
// na koniec wysnuc nowe targets i costs. Do this az nie zostana
// tylko 3 elem w A
// podzielona funkcja move_up
// rr / rrr  RRRRRRRAARRRRRRRR
// zakladam tylko rotowanie do gory,
// bo rrr moznaby robic tylko w przypadku size_a = size_b

/// dobry - ale probuje dwa stacki wrzucic ponizej
// void	rotate_both(int *the_pair, int **stack_a, int **stack_b, int *size_a,
// int *size_b)
// {
// 	if (the_pair[1] == the_pair[0])
// 	{
// 		while (the_pair[1] > 0)
// 		{
// 			rr(stack_a, stack_b, size_a, size_b);
// 			the_pair[1]--;
// 		}
// 	}
// }

void	rotate_a(int *the_pair, int median_a, int **stack_a, int *size_a)
{
	if (the_pair[0] < median_a)
	{
		while (the_pair[0] > 0)
		{
			ra(stack_a, size_a);
			the_pair[0]--;
		}
	}
	else
	{
		while (the_pair[0] < *size_a)
		{
			rra(stack_a, size_a);
			the_pair[0]++;
		}
	}
}

void	rotate_b(int *the_pair, int median_b, int **stack_b, int *size_b)
{
	if (the_pair[1] < median_b)
	{
		while (the_pair[1] > 0)
		{
			rb(stack_b, size_b);
			the_pair[1]--;
		}
	}
	else
	{
		while (the_pair[1] < *size_b)
		{
			rrb(stack_b, size_b);
			the_pair[1]++;
		}
	}
}

void	rotate_both(int *the_pair, int **stacks[], int *size_a, int *size_b)
{
	if (the_pair[1] == the_pair[0])
	{
		while (the_pair[1] > 0)
		{
			rr(stacks[0], stacks[1], size_a, size_b);
			the_pair[1]--;
		}
	}
}

void	move_up(int **pairs, int **stacks[], int *size_a, int *size_b)
{
	int	median_a;
	int	median_b;
	int	*the_pair;

	median_a = *size_a / 2;
	median_b = *size_b / 2;
	the_pair = pairs[min_cost_id(pairs, *size_a, *size_b)];
	rotate_both(the_pair, stacks, size_a, size_b);
	if (the_pair[0] != the_pair[1])
	{
		rotate_b(the_pair, median_b, stacks[1], size_b);
		rotate_a(the_pair, median_a, stacks[0], size_a);
	}
	pb(stacks[0], stacks[1], size_a, size_b);
}

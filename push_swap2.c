/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:59:01 by hhurnik           #+#    #+#             */
/*   Updated: 2024/12/09 20:09:29 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	handle_small_stacks(int **stack_a, int **stack_b, int *size_a,
		int *size_b)
{
	if (*size_a == 2)
		sort_two(stack_a, size_a);
	else if (*size_a == 3)
		sort_three(stack_a, size_a);
	else if (*size_a == 4)
	{
		pb(stack_a, stack_b, size_a, size_b);
		sort_three(stack_a, size_a);
		fourth(stack_a, stack_b, size_a, size_b);
	}
}

// prerzucam to stack_b until 3 are left in stack_a
void	handle_large_stack(int **stack_a, int **stack_b, int *size_a,
		int *size_b)
{
	int	i;
	int	**pairs;
	int	***stacks;

	stacks = malloc(2 * sizeof(int **));
	if (!stacks)
		return (ft_putstr_fd("Error\n", 2));
	stacks[0] = stack_a;
	stacks[1] = stack_b;
	i = 0;
	push_first_two(stack_a, stack_b, size_a, size_b);
	while (*size_a > 3)
	{
		pairs = find_target(*stack_a, *stack_b, *size_a, *size_b);
		if (pairs == NULL)
			return (ft_putstr_fd("Error\n", 2));
		move_up(pairs, stacks, size_a, size_b);
		while (i < *size_a)
		{
			free(pairs[i]);
			i++;
		}
		free(pairs);
	}
	free(stacks);
}

void	perform_rotation(int **stack_a, int *size_a, int id_stack_a)
{
	int	rotation_count;

	if (id_stack_a < *size_a / 2)
	{
		rotation_count = id_stack_a;
		while (rotation_count > 0)
		{
			ra(stack_a, size_a);
			rotation_count--;
		}
	}
	else
	{
		rotation_count = *size_a - id_stack_a;
		while (rotation_count > 0)
		{
			rra(stack_a, size_a);
			rotation_count--;
		}
	}
}

void	back_to_stack_a(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	id_stack_a;
	int	stack_b_el;

	while (*size_b > 0)
	{
		stack_b_el = (*stack_b)[0];
		id_stack_a = find_closest_bigger_id(stack_b_el, *stack_a, *size_a);
		if (id_stack_a == 0)
		{
			pa(stack_a, stack_b, size_a, size_b);
		}
		else
		{
			perform_rotation(stack_a, size_a, id_stack_a);
			pa(stack_a, stack_b, size_a, size_b);
		}
	}
}

// szuka min value and returns the index of this element
void	final_sort(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	rotation_count;
	int	min_id;

	handle_small_stacks(stack_a, stack_b, size_a, size_b);
	if (*size_a <= 4)
		return ;
	handle_large_stack(stack_a, stack_b, size_a, size_b);
	sort_three(stack_a, size_a);
	back_to_stack_a(stack_a, stack_b, size_a, size_b);
	min_id = find_min_value_id(*stack_a, *size_a);
	if (min_id <= *size_a / 2)
	{
		while (min_id-- > 0)
			ra(stack_a, size_a);
	}
	else
	{
		rotation_count = *size_a - min_id;
		while (rotation_count > 0)
		{
			rra(stack_a, size_a);
			rotation_count--;
		}
	}
}

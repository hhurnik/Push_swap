/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:56:11 by hhurnik           #+#    #+#             */
/*   Updated: 2024/12/09 19:11:34 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_closest_bigger(int stack_b_elem, int *stack_a, int size_a)
{
	int	closest_bigger_index;
	int	k;
	int	closest_bigger_value;

	closest_bigger_index = -1;
	closest_bigger_value = -2147483648;
	k = 0;
	while (k < size_a)
	{
		if (stack_a[k] > stack_b_elem)
		{
			if (closest_bigger_index == -1 || stack_a[k] < closest_bigger_value)
			{
				closest_bigger_value = stack_a[k];
				closest_bigger_index = k;
			}
		}
		k++;
	}
	return (closest_bigger_index);
}

int	find_min_value_id(int *stack_a, int size_a)
{
	int	min_index;
	int	min_value;
	int	k;

	min_index = 0;
	min_value = stack_a[0];
	k = 1;
	while (k < size_a)
	{
		if (stack_a[k] < min_value)
		{
			min_value = stack_a[k];
			min_index = k;
		}
		k++;
	}
	return (min_index);
}

int	find_closest_bigger_id(int stack_b_elem, int *stack_a, int size_a)
{
	int	closest_bigger_index;

	if (stack_a == NULL || size_a <= 0)
	{
		return (-1);
	}
	closest_bigger_index = find_closest_bigger(stack_b_elem, stack_a, size_a);
	if (closest_bigger_index != -1)
	{
		return (closest_bigger_index);
	}
	else
	{
		return (find_min_value_id(stack_a, size_a));
	}
}

int	**find_target_a(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	**pairs;
	int	i;

	i = 0;
	pairs = initialize_pairs(size_b);
	if (!pairs)
	{
		printf("Error: Memory allocation for pairs failed.\n");
		return (NULL);
	}
	while (i < size_b)
	{
		pairs[i][0] = i;
		pairs[i][1] = find_closest_bigger_id(stack_b[i], stack_a, size_a);
		i++;
	}
	return (pairs);
}

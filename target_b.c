/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:56:11 by hhurnik           #+#    #+#             */
/*   Updated: 2024/12/09 18:48:51 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_closest_smaller(int stack_a_elem, int *stack_b, int size_b)
{
	int	closest_smaller_index;
	int	closest_smaller_value;
	int	k;

	closest_smaller_index = -1;
	closest_smaller_value = 2147483647;
	k = 0;
	while (k < size_b)
	{
		if (stack_b[k] < stack_a_elem)
		{
			if (closest_smaller_index == -1
				|| stack_b[k] > closest_smaller_value)
			{
				closest_smaller_value = stack_b[k];
				closest_smaller_index = k;
			}
		}
		k++;
	}
	return (closest_smaller_index);
}

int	find_max_value_id(int *stack_b, int size_b)
{
	int	max_index;
	int	max_value;
	int	k;

	max_index = 0;
	max_value = stack_b[0];
	k = 1;
	while (k < size_b)
	{
		if (stack_b[k] > max_value)
		{
			max_value = stack_b[k];
			max_index = k;
		}
		k++;
	}
	return (max_index);
}

int	find_closest_smaller_id(int stack_a_elem, int *stack_b, int size_b)
{
	int	closest_smaller_index;

	if (stack_b == NULL || size_b <= 0)
	{
		return (-1);
	}
	closest_smaller_index = find_closest_smaller(stack_a_elem, stack_b, size_b);
	if (closest_smaller_index != -1)
	{
		return (closest_smaller_index);
	}
	else
	{
		return (find_max_value_id(stack_b, size_b));
	}
}

int	**initialize_pairs(int size)
{
	int	**pairs_init;
	int	j;

	j = 0;
	if (size <= 0)
		return (NULL);
	pairs_init = (int **)malloc(size * sizeof(int *));
	if (pairs_init == NULL)
		return (NULL);
	while (j < size)
	{
		pairs_init[j] = (int *)malloc(2 * sizeof(int));
		if (pairs_init[j] == NULL)
		{
			while (--j >= 0)
				free(pairs_init[j]);
			free(pairs_init);
			return (NULL);
		}
		j++;
	}
	return (pairs_init);
}

int	**find_target(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	**pairs;
	int	i;

	i = 0;
	pairs = initialize_pairs(size_a);
	if (!pairs)
	{
		printf("Error: Memory allocation for pairs failed.\n");
		return (NULL);
	}
	while (i < size_a)
	{
		pairs[i][0] = i;
		pairs[i][1] = find_closest_smaller_id(stack_a[i], stack_b, size_b);
		i++;
	}
	return (pairs);
}

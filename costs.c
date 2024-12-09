/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:13:47 by hhurnik           #+#    #+#             */
/*   Updated: 2024/12/09 19:57:28 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	calculate_individual_costs(int *pair, int *cost, int size_a, int size_b)
{
	if (pair[0] == pair[1] && size_a == size_b)
	{
		if (pair[0] <= size_a / 2)
		{
			cost[0] = -1;
			cost[1] = pair[0];
		}
		else
		{
			cost[0] = -1;
			cost[1] = size_a - pair[0] + 1;
		}
	}
	else
	{
		if (pair[0] <= size_a / 2)
			cost[0] = pair[0];
		else
			cost[0] = size_a - pair[0] + 1;
		if (pair[1] <= size_b / 2)
			cost[1] = pair[1];
		else
			cost[1] = size_b - pair[1] + 1;
	}
}

// liczy pary kosztow  (A, B), (A, B), ...
// divided into calculate_individual_costs
int	**calculate_costs(int **pairs, int size_a, int size_b)
{
	int	i;
	int	**costs;

	i = 0;
	costs = initialize_pairs(size_a);
	if (!costs)
		return (NULL);
	while (i < size_a)
	{
		calculate_individual_costs(pairs[i], costs[i], size_a, size_b);
		i++;
	}
	return (costs);
}

// liczt sume kosztow danej pary (koszt 1, koszt2, ...)
int	*calculate_costs_sum(int **costs, int size_a)
{
	int	i;
	int	*costs_sum;

	i = 0;
	costs_sum = (int *)malloc(size_a * sizeof(int));
	if (!costs_sum)
		return (NULL);
	while (i < size_a)
	{
		if (costs[i][0] == -1)
			costs_sum[i] = costs[i][1];
		else
			costs_sum[i] = costs[i][0] + costs[i][1];
		i++;
	}
	return (costs_sum);
}

// lista wspolnych kosztow
//	- funkcja laczaca calculate_costs i calculate_costs_sum
int	*min_cost(int **pairs, int size_a, int size_b)
{
	int	*costs_sum;
	int	**costs;
	int	i;

	costs = calculate_costs(pairs, size_a, size_b);
	if (!costs)
		return (NULL);
	costs_sum = calculate_costs_sum(costs, size_a);
	i = 0;
	while (i < size_a)
	{
		free(costs[i]);
		i++;
	}
	free(costs);
	return (costs_sum);
}

// bierze sume kosztow {lpszt1, koszt2, ...} i znajduje index tego najmniejszego
int	min_cost_id(int **pairs, int size_a, int size_b)
{
	int	i;
	int	min_id;
	int	*costs_sum;

	i = 1;
	min_id = 0;
	costs_sum = min_cost(pairs, size_a, size_b);
	if (!costs_sum)
		return (-1);
	while (i < size_a)
	{
		if (costs_sum[min_id] > costs_sum[i])
			min_id = i;
		i++;
	}
	free(costs_sum);
	return (min_id);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:43:39 by hhurnik           #+#    #+#             */
/*   Updated: 2024/12/09 19:45:04 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Function to validate input and check for duplicates
int	*validate_and_parse(int argc, char **argv, int *size)
{
	int	*stack_a;

	stack_a = parse_input(argc, argv, size);
	if (!stack_a)
		display_error();
	if (is_duplicate(stack_a, *size))
	{
		free(stack_a);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (stack_a);
}

int	*initialize_and_parse(int argc, char **argv, int *size_a)
{
	int	*stack_a;

	if (argc <= 1)
		exit(EXIT_SUCCESS);
	if (are_all_arguments_empty(argc, argv))
	{
		display_error();
		exit(EXIT_SUCCESS);
	}
	stack_a = validate_and_parse(argc, argv, size_a);
	if (!stack_a)
		exit(EXIT_FAILURE);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;

	stack_b = NULL;
	size_b = 0;
	stack_a = initialize_and_parse(argc, argv, &size_a);
	if (is_sorted(stack_a, size_a) == 1)
	{
		free(stack_a);
		return (EXIT_SUCCESS);
	}
	final_sort(&stack_a, &stack_b, &size_a, &size_b);
	free(stack_a);
	if (stack_b)
		free(stack_b);
	return (EXIT_SUCCESS);
}

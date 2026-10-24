/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:39:02 by hhurnik           #+#    #+#             */
/*   Updated: 2024/12/09 19:07:29 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	validate_and_free_words(char **words, int *result)
{
	int	k;

	k = 0;
	while (words[k])
	{
		free(words[k]);
		k++;
	}
	free(words);
	free(result);
	display_error();
}

void	split_and_process_words(char *arg, int *result, int *count)
{
	char	**words;
	int		j;

	words = ft_split_words(arg);
	if (!words)
	{
		free(result);
		display_error();
	}
	j = 0;
	while (words[j])
	{
		if (!is_valid_int(words[j]) || !is_in_int_range(words[j]))
		{
			validate_and_free_words(words, result);
		}
		result[(*count)++] = atoi(words[j]);
		free(words[j]);
		j++;
	}
	free(words);
}

void	process_words(int argc, char **argv, int *result)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i < argc)
	{
		split_and_process_words(argv[i], result, &count);
		i++;
	}
}

int	*parse_input(int argc, char **argv, int *size)
{
	int	*result;

	*size = calculate_size(argc, argv);
	result = allocate_result(*size);
	process_words(argc, argv, result);
	return (result);
}

// Function to check for duplicates in the integer array
int	is_duplicate(int *stack_a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack_a[i] == stack_a[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

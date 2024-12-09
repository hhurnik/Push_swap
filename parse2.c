/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:08:48 by hhurnik           #+#    #+#             */
/*   Updated: 2024/12/09 19:06:33 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Function to check if the string represents a valid integer
int	is_valid_int(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

// Function to count words (numbers) in a string
int	words_counter(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (!ft_isspace(*s))
		{
			count++;
			while (*s && !ft_isspace(*s))
				s++;
		}
		else
		{
			s++;
		}
	}
	return (count);
}

char	**ft_split_words(char *s)
{
	char	**result;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	result = (char **)malloc((words_counter(s) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (!(ft_isspace(*s)))
		{
			len = 0;
			while (s[len] && (!(ft_isspace(s[len]))))
				len++;
			result[i++] = ft_substr(s, 0, len);
			s += len;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}

int	calculate_size(int argc, char **argv)
{
	int	size;
	int	i;

	size = 0;
	i = 1;
	while (i < argc)
	{
		size += words_counter(argv[i]);
		i++;
	}
	return (size);
}

int	*allocate_result(int size)
{
	int	*result;

	result = (int *)malloc(size * sizeof(int));
	if (!result)
		display_error();
	return (result);
}

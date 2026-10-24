/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:52:26 by hhurnik           #+#    #+#             */
/*   Updated: 2024/12/09 20:12:59 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_number_size(int n)
{
	unsigned int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		length += 1;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char			*string;
	unsigned int	length;

	length = ft_number_size(n);
	string = malloc(sizeof(char) * (length + 1));
	if (!string)
		return (NULL);
	if (n == 0)
		string[0] = '0';
	if (n < 0)
		string[0] = '-';
	string[length] = '\0';
	while (n != 0)
	{
		if (n > 0)
			string[--length] = n % 10 + '0';
		else
		{
			string[length - 1] = n % 10 * -1 + '0';
			length--;
		}
		n = n / 10;
	}
	return (string);
}

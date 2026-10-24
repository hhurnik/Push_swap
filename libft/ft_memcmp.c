/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:36:09 by hhurnik           #+#    #+#             */
/*   Updated: 2024/04/24 17:20:23 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*string1;
	char	*string2;

	string1 = (char *)s1;
	string2 = (char *)s2;
	while (n > 0)
	{
		if (*string1 != *string2)
			return ((unsigned char)(*string1) - (unsigned char)(*string2));
		string1++;
		string2++;
		n--;
	}
	return (0);
}

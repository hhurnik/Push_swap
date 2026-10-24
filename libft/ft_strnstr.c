/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:03:58 by hhurnik           #+#    #+#             */
/*   Updated: 2024/04/24 17:21:39 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	little_len;
	char	*b;

	i = 0;
	b = (char *)big;
	little_len = ft_strlen(little);
	if (little_len == 0 || big == little)
		return (b);
	while (b[i] != '\0' && i < len)
	{
		c = 0;
		while (b[i + c] != '\0' && little[c] != '\0' && b[i + c] == little[c]
			&& i + c < len)
			c++;
		if (c == little_len)
			return (b + i);
		i++;
	}
	return (0);
}

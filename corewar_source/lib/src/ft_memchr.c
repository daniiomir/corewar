/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:27:44 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*arr2;

	if (n + 1 <= 0 || n == 0 || n + 1 < n)
		return (NULL);
	i = 0;
	arr2 = (unsigned char *)s;
	while (n--)
	{
		if (arr2[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

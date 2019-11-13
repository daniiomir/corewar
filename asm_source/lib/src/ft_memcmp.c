/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:44:02 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*array1;
	unsigned char	*array2;

	if (n + 1 <= 0 || n == 0 || n + 1 < n)
		return (0);
	i = 0;
	array1 = (unsigned char *)s1;
	array2 = (unsigned char *)s2;
	if (!array1 && !array2 && !n)
		return (0);
	while (n--)
	{
		if (array1[i] != array2[i])
			return (array1[i] - array2[i]);
		i++;
	}
	return (0);
}

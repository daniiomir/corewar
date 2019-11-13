/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:37:40 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*array1;
	unsigned char	*array2;

	if (n == 0 || n + 1 <= 0 || n + 1 < n)
		return (dst);
	array1 = (unsigned char *)dst;
	array2 = (unsigned char *)src;
	while (n != 0)
	{
		*array1++ = *array2++;
		n--;
	}
	return ((void *)dst);
}

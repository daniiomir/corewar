/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:32:27 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_unsigned_itoa(unsigned int n)
{
	size_t		size;
	size_t		tmp;
	char		*array;

	tmp = n;
	size = 1;
	while ((tmp /= 10))
		size++;
	array = ft_strnew(size);
	if (array == NULL)
		return (NULL);
	while (size--)
	{
		array[size] = (n % 10) + '0';
		n /= 10;
	}
	return (array);
}

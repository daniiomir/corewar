/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:00:55 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long int n)
{
	long long int		size;
	long long int		negative;
	long long int		tmp;
	char				*array;

	tmp = n;
	size = 1;
	negative = 0;
	if (n < 0)
		negative = 1;
	while ((tmp /= 10))
		size++;
	array = ft_strnew(size + negative);
	if (array == NULL)
		return (NULL);
	if (negative)
		array[0] = '-';
	while (size--)
	{
		array[size + negative] = (negative ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	return (array);
}

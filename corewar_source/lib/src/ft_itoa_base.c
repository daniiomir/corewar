/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:32:44 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_helper(unsigned long long int tmp, int base,
	unsigned long long int size)
{
	while (tmp /= base)
		size++;
	size = size + 1;
	return (size);
}

char		*ft_itoa_base(unsigned long long int value, int base)
{
	char					*str;
	char					*tab;
	unsigned long long int	size;
	unsigned long long int	tmp;

	size = 0;
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	tmp = value;
	size = ft_itoa_helper(tmp, base, size);
	str = ft_strnew(size);
	while (size)
	{
		str[size - 1] = tab[value % base];
		size--;
		value /= base;
	}
	return (str);
}

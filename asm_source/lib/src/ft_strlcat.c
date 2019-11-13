/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:42:25 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			j;
	size_t			len;
	size_t			size_min;
	char			*array;

	i = 0;
	j = 0;
	if (size + 1 <= 0 || size + 1 < size)
		return (0);
	size_min = size - 1;
	array = (char *)src;
	len = ft_strlen(array) + ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (ft_strlen(array) + size);
	while (dst[i] != '\0' && size_min--)
		i++;
	while (array[j] != '\0' && size_min--)
		dst[i++] = array[j++];
	dst[i] = '\0';
	return (len);
}

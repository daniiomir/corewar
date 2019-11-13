/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:36:41 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*array;

	i = 0;
	j = 0;
	if (n + 1 <= 0 || n + 1 < n)
		return (NULL);
	array = (unsigned char *)s2;
	while (s1[i] != '\0')
		i++;
	while (array[j] != '\0' && n--)
		s1[i++] = array[j++];
	s1[i] = '\0';
	return ((char *)s1);
}

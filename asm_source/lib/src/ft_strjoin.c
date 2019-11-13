/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 22:05:29 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	h;
	char	*for_malloc;

	i = 0;
	j = 0;
	h = 0;
	if (!s1)
		return (NULL);
	if (!s2)
		return ((char *)s1);
	for_malloc = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2));
	if (for_malloc == NULL)
		return (NULL);
	while (s1[i] != '\0')
		for_malloc[h++] = s1[i++];
	while (s2[j] != '\0')
		for_malloc[h++] = s2[j++];
	for_malloc[h] = '\0';
	return (for_malloc);
}

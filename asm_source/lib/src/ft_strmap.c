/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:05:47 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*for_malloc;

	if (!s || !f)
		return (NULL);
	i = 0;
	for_malloc = ft_strnew(ft_strlen((char *)s));
	if (for_malloc == NULL)
		return (NULL);
	while (s[i])
	{
		for_malloc[i] = (*f)(s[i]);
		i++;
	}
	return (for_malloc);
}

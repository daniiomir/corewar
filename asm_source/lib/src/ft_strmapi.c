/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:48:42 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*for_malloc;

	i = 0;
	if (!s || !f)
		return (NULL);
	for_malloc = ft_strnew(ft_strlen((char *)s));
	if (for_malloc == NULL)
		return (NULL);
	while (s[i])
	{
		for_malloc[i] = (*f)(i, s[i]);
		i++;
	}
	return (for_malloc);
}

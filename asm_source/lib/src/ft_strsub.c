/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:34:23 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*for_malloc;

	i = 0;
	if (!s || len + 1 <= 0 || start + 1 <= 0)
		return (NULL);
	for_malloc = ft_strnew(len);
	if (for_malloc == NULL)
		return (NULL);
	while (i < len && (char)s[start] != '\0')
		for_malloc[i++] = (char)s[start++];
	for_malloc[i] = '\0';
	return (for_malloc);
}

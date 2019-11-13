/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:33:57 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*for_malloc;

	if (s)
	{
		i = 0;
		j = 0;
		len = ft_strlen((char *)s);
		while ((char)s[i] == ' ' || (char)s[i] == '\n' || (char)s[i] == '\t')
			i++;
		if ((char)s[i] == '\0')
			return (ft_strdup((char *)s + i));
		while ((char)s[len - 1] == ' ' || (char)s[len - 1] == '\n' \
			|| (char)s[len - 1] == '\t')
			len--;
		for_malloc = ft_strnew(len - i);
		if (for_malloc == NULL)
			return (NULL);
		while (i < len)
			for_malloc[j++] = (char)s[i++];
		return (for_malloc);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:08:54 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		result;
	size_t		count;

	result = 0;
	if (ft_strcmp("", needle) == 0)
		return ((char *)haystack);
	while (haystack[result] != '\0')
	{
		count = 0;
		while (needle[count] == haystack[result + count]
				&& haystack[result + count] != '\0')
			count++;
		if (needle[count] == '\0')
			return ((char *)&haystack[result]);
		result++;
	}
	return (NULL);
}

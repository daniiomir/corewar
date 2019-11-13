/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:17:49 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*l;

	if (len + 1 <= 0 || len + 1 < len)
		return (NULL);
	l = needle;
	if (*l == '\0')
		return ((char*)haystack);
	while (len--)
	{
		if (*l == *haystack)
			l++;
		else
		{
			haystack -= (l - needle);
			len += (l - needle);
			l = needle;
		}
		haystack++;
		if (*l == '\0')
			return ((char*)(haystack - (l - needle)));
		if (*haystack == '\0')
			break ;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:43:52 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s1)
{
	int		len;
	char	*for_malloc;

	len = ft_strlen((char *)s1);
	for_malloc = (char *)malloc(sizeof(char) * (len + 1));
	if (for_malloc != NULL)
		ft_strcpy(for_malloc, (char *)s1);
	else
		return (NULL);
	return (for_malloc);
}

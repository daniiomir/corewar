/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 00:08:38 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t iterator;

	iterator = 0;
	if (len == 0 || len + 1 <= 0 || len + 1 < len)
		return (dst);
	while (src[iterator] != '\0' && (iterator < len))
	{
		dst[iterator] = src[iterator];
		iterator++;
	}
	while (iterator < len)
		dst[iterator++] = '\0';
	return (dst);
}

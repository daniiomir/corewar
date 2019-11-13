/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:46:19 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*for_malloc;

	if (size + 1 <= 0 || size + 1 < size)
		return (NULL);
	for_malloc = (char *)malloc(sizeof(char) * (size + 1));
	if (for_malloc == NULL)
		return (NULL);
	ft_bzero(for_malloc, size + 1);
	return (for_malloc);
}

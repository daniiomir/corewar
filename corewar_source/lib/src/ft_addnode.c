/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 01:08:59 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addnode(t_list **val_list, char *buffer, int size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->content = ft_strdup(buffer);
	new->content_size = size;
	new->next = NULL;
	ft_lstadd_end(val_list, new);
	ft_strclr(buffer);
}

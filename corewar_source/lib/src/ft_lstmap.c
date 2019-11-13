/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:31:33 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static t_list	*error_processing(t_list *first_elem)
{
	t_list		*i;

	if (!first_elem)
		return (NULL);
	while (first_elem->next)
	{
		i = first_elem->next;
		free(first_elem->content);
		free(first_elem);
		first_elem = i;
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*temp;
	t_list		*new_list;
	t_list		*previous_list;
	t_list		*first_elem;

	if (!lst || !f)
		return (NULL);
	previous_list = f(lst);
	first_elem = previous_list;
	while (lst->next)
	{
		temp = lst->next;
		if (!(new_list = f(temp)))
			return (error_processing(first_elem));
		previous_list->next = new_list;
		previous_list = previous_list->next;
		lst = lst->next;
	}
	return (first_elem);
}

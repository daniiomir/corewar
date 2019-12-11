/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:29:15 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/11 18:29:17 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void 	dead_cursor(t_cursor **cursor, t_cursor **start)
{
	t_cursor	*wst;

	if ((*cursor))
	{
		if ((*cursor)->prev)
		{
			(*cursor)->prev->next = (*cursor)->next;
			wst = (*cursor);
			(*cursor) = (*cursor)->prev;
			free(wst);
		}
		if (!((*cursor)->prev))
		{
			(*start) = (*cursor)->next;
			wst = (*cursor);
			(*cursor) = (*cursor)->next;
			free(wst);
		}
	}
}
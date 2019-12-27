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

#include "corewar.h"

void		cursor_operations_exec(t_arena *arena, t_cursor **cursors)
{
	t_cursor	*wst;

	wst = *cursors;
	while (wst)
	{
		if (wst->cycles_remaining == 0)
		{
			wst->current_op = arena->map[wst->current_position];
			if (wst->current_op >= 0x01 && wst->current_op <= 0x10)
				wst->cycles_remaining = op_tab[(int)wst->current_op].need_cycles;
		}
		if (wst->cycles_remaining > 0)
			wst->cycles_remaining--;
		if (wst->cycles_remaining == 0)
			do_operation(wst, arena);
		wst = wst->next;
	}
}

void		kill_cursor(t_cursor **search_cursor, t_cursor **first_cursor)
{
	t_cursor *prev_cursor;

	prev_cursor = (*first_cursor);
	if (prev_cursor == *(search_cursor))
	{
		(*first_cursor) = (*first_cursor)->next;
		free((*search_cursor));
		(*search_cursor) = (*first_cursor);
		return ;
	}
	while (prev_cursor->next != (*search_cursor) && prev_cursor != NULL)
		prev_cursor = prev_cursor->next;
	prev_cursor->next = (*search_cursor)->next;
	free((*search_cursor));
	(*search_cursor) = prev_cursor->next;
}

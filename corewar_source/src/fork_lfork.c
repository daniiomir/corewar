/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:10:51 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 14:10:53 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_cursor	*copy_cursor(t_cursor *to, t_cursor *from)
{
	to->f_carry = from->f_carry;
	to->last_live_cycle = from->last_live_cycle;
	ft_memcpy(to->reg, from->reg, REG_NUMBER);
	return (to);
}

void		op_fork(t_gstate *gstate, t_cursor *cursor)
{
	t_cursor	*cursor_copy;
	t_cursor	*tmp;
	int			arg;

	cursor->next_op_steps += 1;
	cursor_copy = copy_cursor(init_cursor(cursor->player_id, cursor->reg[0]), cursor);
	gstate->processes_num++;
	arg = get_arg(gstate->arena, cursor, T_DIR, 0);
	cursor_copy->cur_pos = get_map_ind(cursor->cur_pos, arg % IDX_MOD);
	tmp = gstate->first_cursor;
	gstate->first_cursor = cursor_copy;
	cursor_copy->next = tmp;
}

void		op_lfork(t_gstate *gstate, t_cursor *cursor)
{
	t_cursor	*cursor_copy;
	t_cursor	*tmp;
	int			arg;

	cursor->next_op_steps += 1;
	cursor_copy = copy_cursor(init_cursor(cursor->player_id, cursor->reg[0]), cursor);
	gstate->processes_num++;
	arg = get_arg(gstate->arena, cursor, T_DIR, 0);
	cursor_copy->current_op = get_map_ind(cursor->cur_pos, arg);
	tmp = gstate->first_cursor;
	gstate->first_cursor = cursor_copy;
	cursor_copy->next = tmp;
}

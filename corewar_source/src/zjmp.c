/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:51:05 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 12:51:19 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

void	op_zjmp(t_gstate *gstate, t_cursor *cursor)
{
	int addr;

	cursor->next_op_steps += 1;
	addr = get_arg(gstate->arena, cursor, T_DIR, 1);
	if (cursor->f_carry)
	{
		if (gstate->f_v)
			gstate->vis->map[cursor->cur_pos].is_cursor = 0;
//		cursor->cur_pos = get_map_ind(cursor->cur_pos, addr % IDX_MOD);
		cursor->next_op_steps = get_map_ind(cursor->cur_pos, addr % IDX_MOD);
		if (gstate->f_v)
			gstate->vis->map[cursor->cur_pos].is_cursor = 0;
	}
}

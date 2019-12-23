/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exactly_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:57:20 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/14 17:57:21 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_arg(t_arena *arena, t_cursor *cursor, int current_position, int mod)
{
	int 	value;
	int		addr;
	t_op	*op;

	value = 0;
	addr = 0;
	op = &op_tab[INDEX(cursor->current_code)];
	if (cursor->current_code & T_DIR)
	{
		value = byte_shift(&cursor->current_code, op->t_dir_size);
		cursor->next_op_steps += op->t_dir_size;
	}
	if (cursor->current_code & T_REG)
	{
		value = cursor->reg[INDEX(current_position)];
		cursor->next_op_steps += T_REG_SIZE;
	}
	if (cursor->current_code & T_IND)
	{
		addr = byte_shift(&cursor->current_code, IND_SIZE);
		value = byte_shift(&arena->map[current_position + (mod ? (addr % IDX_MOD) : addr)], DIR_SIZE);
		cursor->next_op_steps += T_IND_SIZE;
	}
	return (value);
}
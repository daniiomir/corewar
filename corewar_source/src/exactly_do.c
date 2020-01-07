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

int	get_arg(t_arena *arena, t_cursor *cursor, unsigned char arg, int mod)
{
	int 			value;
	int				addr;
	t_op			*op;

	value = 0;
	op = &op_tab[cursor->current_op];
	if (arg == T_DIR)
	{
		value = get_map_int(arena, cursor->cur_pos + cursor->next_op_steps, op->t_dir_size);
		cursor->next_op_steps += op->t_dir_size;
	}
	if (arg == T_REG)
	{
		addr = get_map_ind(cursor->cur_pos, cursor->next_op_steps);
		value = cursor->reg[INDEX(arena->map[addr])];
		cursor->next_op_steps += T_REG_SIZE;
	}
	if (arg + 1 == T_IND)
	{
		addr = get_map_int(arena, cursor->cur_pos + cursor->next_op_steps, IND_SIZE);
		value = get_map_int(arena, cursor->cur_pos + (mod ? (addr % IDX_MOD) : addr), DIR_SIZE);
		cursor->next_op_steps += T_IND_SIZE;
	}
	return (value);
}

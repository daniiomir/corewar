/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exactly_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:07:49 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 14:07:50 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_arg(t_arena *arena, t_cursor *cursor, unsigned char arg, int mod)
{
	int				value;
	int				addr;
	t_op			*op;

	value = 0;
	op = &g_op_tab[cursor->current_op];
	if (arg == T_DIR)
	{
		value = get_map_int(arena, cursor->pos + cursor->steps, op->dir_size);
		cursor->steps += op->dir_size;
	}
	if (arg == T_REG)
	{
		addr = get_map_ind(cursor->pos, cursor->steps);
		value = cursor->reg[INDEX(arena->map[addr])];
		cursor->steps += T_REG_SIZE;
	}
	if (arg + 1 == T_IND)
	{
		addr = get_map_int(arena, cursor->pos + cursor->steps, IND_SIZE);
		value = get_map_int(arena, cursor->pos +
			(mod ? (addr % IDX_MOD) : addr), DIR_SIZE);
		cursor->steps += T_IND_SIZE;
	}
	return (value);
}

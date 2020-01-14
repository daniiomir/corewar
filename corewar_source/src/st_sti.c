/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:07:50 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 13:07:51 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_vis.h"

void	write_to_map(t_gstate *gstate, int what, int where, int size)
{
	int		i;
	int		j;
	int		index;

	i = 0;
	j = 0;
	while (i < size)
	{
		index = get_map_ind(where, size - i - 1);
		gstate->arena->map[index] = (what >> j) & 0xFF;
		j += 8;
		i++;
	}
}

void	vis_write_to_map(t_gstate *gstate,
		t_cursor *cursor, int where, int size)
{
	int		i;
	int		index;

	i = 0;
	while (i < size)
	{
		index = get_map_ind(where, size - i - 1);
		gstate->vis->map[index].player_id = cursor->player_id;
		gstate->vis->map[index].is_cursor = 0;
		i++;
	}
}

void	op_st(t_gstate *gstate, t_cursor *cursor)
{
	int reg;
	int arg2;
	int addr;

	cursor->steps += 2;
	reg = get_arg(gstate->arena, cursor, cursor->args[0], 0);
	if (cursor->args[1] == T_REG)
	{
		arg2 = get_cur_pos_byte(gstate->arena, cursor);
		cursor->reg[INDEX(arg2)] = reg;
	}
	else
	{
		arg2 = get_map_int(gstate->arena,
				cursor->pos + cursor->steps, T_IND_SIZE);
		addr = cursor->pos + (arg2 % IDX_MOD);
		write_to_map(gstate, reg, addr, DIR_SIZE);
		if (gstate->f_v)
			vis_write_to_map(gstate, cursor, addr, DIR_SIZE);
		cursor->steps += IND_SIZE;
	}
}

void	op_sti(t_gstate *gstate, t_cursor *cursor)
{
	int reg;
	int arg2;
	int arg3;
	int addr;

	cursor->steps += 2;
	reg = get_arg(gstate->arena, cursor, cursor->args[0], 0);
	arg2 = get_arg(gstate->arena, cursor, cursor->args[1], 1);
	arg3 = get_arg(gstate->arena, cursor, cursor->args[2], 1);
	addr = cursor->pos + ((arg2 + arg3) % IDX_MOD);
	write_to_map(gstate, reg, addr, DIR_SIZE);
	if (gstate->f_v)
		vis_write_to_map(gstate, cursor, addr, DIR_SIZE);
}

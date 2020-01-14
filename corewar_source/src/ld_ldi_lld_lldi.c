/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_ldi_lld_lldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:40:20 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 13:40:21 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_ld(t_gstate *gstate, t_cursor *cursor)
{
	int arg;
	int reg;

	cursor->steps += 2;
	arg = get_arg(gstate->arena, cursor, cursor->args[0], 1);
	reg = get_cur_pos_byte(gstate->arena, cursor);
	cursor->reg[INDEX(reg)] = arg;
	cursor->f_carry = (arg == 0) ? 1 : 0;
}

void	op_lld(t_gstate *gstate, t_cursor *cursor)
{
	int arg;
	int reg;

	cursor->steps += 2;
	arg = get_arg(gstate->arena, cursor, cursor->args[0], 0);
	reg = get_cur_pos_byte(gstate->arena, cursor);
	cursor->reg[INDEX(reg)] = arg;
	cursor->f_carry = (arg == 0) ? 1 : 0;
}

void	op_ldi(t_gstate *gstate, t_cursor *cursor)
{
	int arg1;
	int arg2;
	int reg;
	int addr;

	cursor->steps += 2;
	arg1 = get_arg(gstate->arena, cursor, cursor->args[0], 1);
	arg2 = get_arg(gstate->arena, cursor, cursor->args[1], 1);
	reg = get_cur_pos_byte(gstate->arena, cursor);
	addr = cursor->pos + ((arg1 + arg2) % IDX_MOD);
	cursor->reg[INDEX(reg)] = get_map_int(gstate->arena, addr, 4);
}

void	op_lldi(t_gstate *gstate, t_cursor *cursor)
{
	int arg1;
	int arg2;
	int reg;
	int addr;

	cursor->steps += 2;
	arg1 = get_arg(gstate->arena, cursor, cursor->args[0], 1);
	arg2 = get_arg(gstate->arena, cursor, cursor->args[1], 1);
	reg = get_cur_pos_byte(gstate->arena, cursor);
	addr = cursor->pos + arg1 + arg2;
	cursor->reg[INDEX(reg)] = get_map_int(gstate->arena, addr, 4);
}

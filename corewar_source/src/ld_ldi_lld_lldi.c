#include "corewar.h"

void	op_ld(t_arena *arena, t_cursor *cursor)
{
	int arg;
	int reg;

	cursor->next_op_steps += 2;
	arg = get_arg(arena, cursor, cursor->args[0], 1);
	reg = get_cur_pos_byte(arena, cursor);
	cursor->reg[INDEX(reg)] = arg;
	cursor->f_carry = (arg == 0) ? 1 : 0;
}

void	op_lld(t_arena *arena, t_cursor *cursor)
{
	int arg;
	int reg;

	cursor->next_op_steps += 2;
	arg = get_arg(arena, cursor, cursor->args[0], 0);
	reg = get_cur_pos_byte(arena, cursor);
	cursor->reg[INDEX(reg)] = arg;
	cursor->f_carry = (arg == 0) ? 1 : 0;
}

void	op_ldi(t_arena *arena, t_cursor *cursor)
{
	int arg1;
	int arg2;
	int reg;
	int addr;

	cursor->next_op_steps += 2;
	arg1 = get_arg(arena, cursor, cursor->args[0], 1);
	arg2 = get_arg(arena, cursor, cursor->args[1], 1);
	reg = get_cur_pos_byte(arena, cursor);
	addr = cursor->cur_pos + ((arg1 + arg2) % IDX_MOD);
	cursor->reg[INDEX(reg)] = get_map_int(arena, addr, 4);
}

void	op_lldi(t_arena *arena, t_cursor *cursor)
{
	int arg1;
	int arg2;
	int reg;
	int addr;

	cursor->next_op_steps += 2;
	arg1 = get_arg(arena, cursor, cursor->args[0], 1);
	arg2 = get_arg(arena, cursor, cursor->args[1], 1);
	reg = get_cur_pos_byte(arena, cursor);
	addr = cursor->cur_pos + arg1 + arg2;
	cursor->reg[INDEX(reg)] = get_map_int(arena, addr, 4);
}
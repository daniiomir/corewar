#include "corewar.h"

void	op_and(t_arena *arena, t_cursor *cursor)
{
	int arg1;
	int arg2;
	int reg;

	cursor->next_op_steps += 2;
	arg1 = get_arg(arena, cursor, cursor->args[0], 0);
	arg2 = get_arg(arena, cursor, cursor->args[1], 0);
	reg = get_cur_pos_byte(arena, cursor);
	cursor->reg[INDEX(reg)] = arg1 & arg2;
	cursor->f_carry = (cursor->reg[INDEX(reg)] == 0) ? 1 : 0;
}

void	op_or(t_arena *arena, t_cursor *cursor)
{
	int arg1;
	int arg2;
	int reg;

	cursor->next_op_steps += 2;
	arg1 = get_arg(arena, cursor, cursor->args[0], 0);
	arg2 = get_arg(arena, cursor, cursor->args[1], 0);
	reg = get_cur_pos_byte(arena, cursor);
	cursor->reg[INDEX(reg)] = arg1 | arg2;
	cursor->f_carry = (cursor->reg[INDEX(reg)] == 0) ? 1 : 0;
}

void	op_xor(t_arena *arena, t_cursor *cursor)
{
	int arg1;
	int arg2;
	int reg;

	cursor->next_op_steps += 2;
	arg1 = get_arg(arena, cursor, cursor->args[0], 0);
	arg2 = get_arg(arena, cursor, cursor->args[1], 0);
	reg = get_cur_pos_byte(arena, cursor);
	cursor->reg[INDEX(reg)] = arg1 ^ arg2;
	cursor->f_carry = (cursor->reg[INDEX(reg)] == 0) ? 1 : 0;
}

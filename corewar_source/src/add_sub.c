#include "corewar.h"

void	op_add(t_arena *arena, t_cursor *cursor)
{
	int reg1;
	int reg2;
	int reg3;

	cursor->cur_pos = get_map_ind(cursor->cur_pos, 2);
	reg1 = get_arg(arena, cursor, cursor->args[0], 0);
	reg2 = get_arg(arena, cursor, cursor->args[1], 0);
	reg3 = get_cur_pos_byte(arena, cursor);
	cursor->reg[INDEX(reg3)] = reg1 + reg2;
	cursor->f_carry = (cursor->reg[INDEX(reg3)] == 0) ? 1 : 0;
}

void	op_sub(t_arena *arena, t_cursor *cursor)
{
	int reg1;
	int reg2;
	int reg3;

	cursor->cur_pos = get_map_ind(cursor->cur_pos, 2);
	reg1 = get_arg(arena, cursor, cursor->args[0], 0);
	reg2 = get_arg(arena, cursor, cursor->args[1], 0);
	reg3 = get_cur_pos_byte(arena, cursor);
	cursor->reg[INDEX(reg3)] = reg1 - reg2;
	cursor->f_carry = (cursor->reg[INDEX(reg3)] == 0) ? 1 : 0;
}

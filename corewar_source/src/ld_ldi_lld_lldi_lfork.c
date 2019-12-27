#include "corewar.h"

void	op_ld(t_arena *arena, t_cursor *cursor)
{
	int arg1;
	int arg2;
	int cursor_pos;

	cursor_pos = cursor->current_position;
	cursor->current_position = get_map_ind(cursor->current_position, 2);
	arg1 = get_arg(arena, cursor, cursor->args[0], 1);
	arg2 = get_arg(arena, cursor, cursor->args[1], 0);
	cursor->reg[arg2] = arg1;
	cursor->carry = (arg1 != 0) ? 1 : 0;
}

void	op_ldi(t_arena *arena, t_cursor *cursor)
{
	int addr1;
	int addr2;
	int reg;

	addr1 = get_arg(arena, cursor, cursor->args[0], 1);
	addr2 = get_arg(arena, cursor, cursor->args[1], 1);
	reg = get_arg(arena, cursor, cursor->args[2], 1);
	cursor->reg[reg] = cursor->current_position + ((addr1 + addr2) % IDX_MOD);
}

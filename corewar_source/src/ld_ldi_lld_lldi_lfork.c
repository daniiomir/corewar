#include "corewar.h"

void	op_ld(t_arena *arena, t_cursor *cursor)
{
	int arg1, arg2;
	int i;

	i = cursor->current_position;
	arg1 = get_arg(arena, cursor, i, 1);
	arg2 = get_arg(arena, cursor, i, 0);
	cursor->reg[INDEX(arg2)] = arg1;
	cursor->carry = (arg1 != 0) ? 1 : 0;
}

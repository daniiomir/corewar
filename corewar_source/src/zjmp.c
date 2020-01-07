#include "corewar.h"

void	op_zjmp(t_arena *arena, t_cursor *cursor)
{
	int addr;

	cursor->cur_pos = get_map_ind(cursor->cur_pos, 2);
	addr = get_arg(arena, cursor, cursor->args[0], 0);
	if (cursor->f_carry)
	{
		cursor->cur_pos = cursor->cur_pos + (addr % IDX_MOD);
	}
}

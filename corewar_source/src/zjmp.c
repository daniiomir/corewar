#include "corewar.h"

void	op_zjmp(t_arena *arena, t_cursor *cursor)
{
	int addr;

	cursor->next_op_steps += 1;
	addr = get_arg(arena, cursor, T_DIR, 1);
	if (cursor->f_carry)
	{
		cursor->cur_pos = get_map_ind(cursor->cur_pos, addr % IDX_MOD);
		cursor->next_op_steps = 0;
	}
}

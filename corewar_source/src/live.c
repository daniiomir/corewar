#include "corewar.h"

void	op_live(t_gstate *gstate, t_cursor *cursor)
{
	int arg;

	cursor->next_op_steps += 1;
	arg = get_arg(gstate->arena, cursor, T_DIR, 0);
}

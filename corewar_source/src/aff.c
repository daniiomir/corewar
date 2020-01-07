#include "corewar.h"

void	op_aff(t_arena *arena, t_cursor *cursor)
{
	int	reg;
	int	value;

	cursor->next_op_steps = get_map_ind(cursor->cur_pos, 2);
	reg = get_arg(arena, cursor, cursor->args[0], 0);
	value = (char)reg;
	if (arena->f_a)
		printf("Aff: %c\n", (char)value);
}
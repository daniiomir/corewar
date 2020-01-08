#include "corewar.h"

void	op_aff(t_gstate *gstate, t_cursor *cursor)
{
	int	reg;
	int	value;

	cursor->next_op_steps += 2;
	reg = get_arg(gstate->arena, cursor, T_DIR, 0);
	value = (char)reg;
	if (gstate->f_a)
		printf("Aff: %c\n", (char)value);
}
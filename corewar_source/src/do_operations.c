#include "corewar.h"

static void	move_error_code(t_cursor *cursor)
{
	cursor->cur_pos += cursor->next_op_steps;
	cursor->cycles_remaining = 0;
}

void move_cursor(t_gstate *gstate, t_cursor *cursor)    // понадобится gstate для визуализации
{
	cursor->cur_pos = get_map_ind(cursor->cur_pos, cursor->next_op_steps);
	cursor->next_op_steps = 0;
	ft_bzero(cursor->args, sizeof(unsigned char) * 3);
}

void do_operation(t_gstate *gstate, t_cursor *cursor)
{
	t_op	curr_op;
	int 	do_op;

	curr_op = op_tab[(int)cursor->current_op];
	do_op = 0;
	if (cursor->current_op >= 0x01 && cursor->current_op <= 0x10)
	{
		cursor->next_op_steps++;
		if (curr_op.arg_code_type)
			if ((do_op = argument_code_type_check(cursor, gstate->arena, curr_op)) != 0)
				move_error_code(cursor);
		if (do_op == 0)
		{
			cursor->next_op_steps = 0;
			op_tab[cursor->current_op].func(gstate, cursor);
			move_cursor(gstate, cursor);
		}
	}
	else
		cursor->cur_pos += 1;
}

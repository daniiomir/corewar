#include "corewar.h"

t_cursor *copy_cursor(t_cursor *to, t_cursor *from)
{
	to->f_carry = from->f_carry;
	to->last_live_cycle = from->last_live_cycle;
	ft_memcpy(to->reg, from->reg, REG_NUMBER);
	return (to);
}

void	op_fork(t_arena *arena, t_cursor *cursor)
{
	t_cursor *cursor_copy;
	t_cursor *tmp;
	int arg;

	cursor->next_op_steps += 1;
	cursor_copy = copy_cursor(init_cursor(0, cursor->reg[0]), cursor);
	arg = get_arg(arena, cursor, T_DIR, 0);
	cursor_copy->cur_pos = get_map_ind(0, arg % IDX_MOD);
	tmp = arena->first_cursor;
	arena->first_cursor = cursor_copy;
	cursor_copy->next = tmp;
}

void	op_lfork(t_arena *arena, t_cursor *cursor)
{
	t_cursor *cursor_copy;
	t_cursor *tmp;
	int arg;

	cursor->next_op_steps += 1;
	cursor_copy = copy_cursor(init_cursor(0, cursor->reg[0]), cursor);
	arg = get_arg(arena, cursor, T_DIR, 0);
	cursor_copy->current_op = get_map_ind(0, arg);
	tmp = arena->first_cursor;
	arena->first_cursor = cursor_copy;
	cursor_copy->next = tmp;
}

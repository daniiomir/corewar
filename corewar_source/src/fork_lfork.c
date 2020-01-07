#include "corewar.h"

void copy_cursor(t_cursor *to, t_cursor *from) {
	to->f_carry = from->f_carry;
	to->last_live_cycle = from->last_live_cycle;
	ft_memcpy(to->reg, from->reg, REG_NUMBER);
}

void	op_fork(t_arena *arena, t_cursor *cursor)
{
	t_cursor *cursor_copy;
	int arg;

	cursor->cur_pos = get_map_ind(cursor->cur_pos, 1);
	cursor_copy = init_cursor(0, cursor->reg[0]);
	copy_cursor(cursor_copy, cursor);
	arg = get_arg(arena, cursor, cursor->args[0], 0);
	cursor_copy->current_op = get_map_ind(0, arg % IDX_MOD);
	//	поместить курсор в начало структуры (как вариант можно сохранить ссылку на первую структуру в арене)
}

void	op_lfork(t_arena *arena, t_cursor *cursor)
{
	t_cursor *cursor_copy;
	int arg;

	cursor->cur_pos = get_map_ind(cursor->cur_pos, 1);
	cursor_copy = init_cursor(0, cursor->reg[0]);
	copy_cursor(cursor_copy, cursor);
	arg = get_arg(arena, cursor, cursor->args[0], 0);
	cursor_copy->current_op = arg;
	//	поместить курсор в начало структуры (как вариант можно сохранить ссылку на первую структуру в арене)
}

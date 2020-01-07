#include "corewar.h"

void write_to_map(t_arena *arena, int what, int where, int size) {
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		arena->map[get_map_ind(where, size - i - 1)] = (what >> j) & 0xFF;
		j += 8;
		i++;
	}
}

void	op_st(t_arena *arena, t_cursor *cursor)
{
	int reg;
	int arg2;
	int addr;

	cursor->next_op_steps += 2;
	reg = get_arg(arena, cursor, cursor->args[0], 0);
	if (cursor->args[1] == T_REG)
	{
		arg2 = get_cur_pos_byte(arena, cursor);
		cursor->reg[INDEX(arg2)] = reg;
	}
	else
	{
		arg2 = get_map_int(arena, cursor->cur_pos + cursor->next_op_steps, T_IND_SIZE);
		addr = cursor->cur_pos + (arg2 % IDX_MOD);
		write_to_map(arena, reg, addr, DIR_SIZE);
		cursor->next_op_steps += IND_SIZE;
	}
}

void	op_sti(t_arena *arena, t_cursor *cursor)
{
	int reg;
	int arg2;
	int arg3;
	int addr;

	cursor->next_op_steps += 2;
	reg = get_arg(arena, cursor, cursor->args[0], 0);
	arg2 = get_arg(arena, cursor, cursor->args[1], 1);
	arg3 = get_arg(arena, cursor, cursor->args[2], 1);
	addr = cursor->cur_pos + ((arg2 + arg3) % IDX_MOD);
	write_to_map(arena, reg, addr, DIR_SIZE);
	cursor->next_op_steps += IND_SIZE;
}

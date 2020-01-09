#include "corewar.h"

static int 	check_one_arg(t_cursor *cursor, t_arena *arena, int arg_order, t_op operation)
{
	int current_pos;
	unsigned char arg;

	current_pos = cursor->cur_pos + cursor->next_op_steps;
	arg = cursor->args[arg_order];
	if (!(arg & operation.arg_types[arg_order]))
		return (0);
	if (arg == REG_CODE)
	{
		cursor->next_op_steps++;
		if (arena->map[current_pos] < 1 || arena->map[current_pos] > 16)
			return (0);
	}
	else if (arg == DIR_CODE)
		cursor->next_op_steps += operation.t_dir_size;
	else if (arg == IND_CODE)
		cursor->next_op_steps += 2;
	else
		return (0);
	return (1);
}

static int		check_args(t_cursor *cursor, t_arena *arena, t_op operation)
{
	int arg_order;
	int nbr_arg;

	arg_order = -1;
	nbr_arg = 0;
	while (++arg_order < operation.nbrarg)
		if (check_one_arg(cursor, arena, arg_order, operation))
			nbr_arg++;
	if (nbr_arg != operation.nbrarg)
		return (0);
	return (1);
}

int	argument_code_type_check(t_cursor *cursor, t_arena *arena, t_op operation)
{
	unsigned char args_type_code;
	unsigned char byte_shift;
	int	i;

	args_type_code = arena->map[get_map_ind(cursor->cur_pos, 1)];
	cursor->next_op_steps += 2;
	i = 0;
	if (!operation.arg_code_type)
		return (0);
	while (i < operation.nbrarg)
	{
		byte_shift = 6u - i * 2;
		cursor->args[i] = (args_type_code >> byte_shift) & 0x03u;
		i++;
	}
	if (!check_args(cursor, arena, operation) || args_type_code & 0x03u)
		return (1);
	return (0);
}

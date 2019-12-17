/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:11:47 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/13 19:11:48 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned char	check_arg_fill(unsigned char arg_code_type, int buff)
{
	unsigned char	check;

	check = 3 << ((buff + 1) * 2);
	if ((arg_code_type & check) == check)
		return (T_IND);
	else if ((arg_code_type & (check - (check / 3))) == (check - (check / 3)))
		return (T_DIR);
	else if ((arg_code_type & (check / 3)) == (check / 3))
		return (T_REG);
	else
		return (0);
}

int 	check_type(unsigned char *args_type, t_cursor *wst, t_arena *arena, t_op operation)
{
	int i;
	int nbrarg;
	int index;

	i = 0;
	nbrarg = 0;
	index = wst->current_position + 2;
	while (i < operation.nbrarg) {
		if (args_type[i] & operation.arg[i])
		{
			if (args_type[i] == REG_CODE)
			{
				if (arena->map[index] < 1 || arena->map[index] > 16)
					return (0);
				index += 1;
			}
			if (args_type[i] == DIR_CODE)
				index += operation.t_dir_size;
			if (args_type[i] == IND_CODE)
				index += 2;
			nbrarg++;
			i++;
		}
	}
	if (nbrarg != operation.nbrarg)
		return (0);
	wst->next_operation_steps = index;
	return (1);
}

static int	argument_code_type_check(t_cursor *wst, t_arena *arena, unsigned char args_type_code, t_op operation)
{
	int	i;
	unsigned char args_type[operation.nbrarg];
	unsigned char byte_shift;

	i = 0;
	if (!args_type_code || (args_type_code & 0x03u))
		return (0);
	while (i < operation.nbrarg)
	{
		if (operation.arg[i])
		{
			byte_shift = 6u - i * 2;
			args_type[i] = ((unsigned char)(args_type_code >> byte_shift) & 0x03u);
		}
		i++;
	}
	if (!check_type(args_type, wst, arena, operation))
		return (1);
	return (0);
}

static void				move_error_code(t_cursor *wst, t_arena *arena)
{
	wst->next_operation_steps = next_operation_steps_calculation(wst, arena->map[wst->current_position + 1]);
	wst->cycles_remaining = 0;
}

void					do_operations(t_cursor *wst, t_arena *arena, t_cursor **cursors)
{
	t_op	curr_op;

	curr_op = op_tab[(int)wst->current_code];
	if (wst->current_code >= 0x01 && wst->current_code <= 0x10)
	{
		if (curr_op.argument_code_type)
			if (!(argument_code_type_check(wst, arena, arena->map[wst->current_position + 1], curr_op)))
				move_error_code(wst, arena);
		exactly_do(wst, cursors, arena);
		wst->next_operation_steps = next_operation_steps_calculation(wst, arena->map[wst->current_position + 1]);
	}
	else
		wst->current_position += 1;
}

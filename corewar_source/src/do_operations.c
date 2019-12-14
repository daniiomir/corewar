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

static int				check_registers(unsigned char check_arg[3])
{
	if (check_arg[0] == T_REG)
		check_arg[0] = 1;
	return (1);
}

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

static int				argument_code_type_check(unsigned char arg_code_type,
		t_op operation)
{
	unsigned char	check_arg[3];
	int 			a;

	if (!arg_code_type)
		return (0);
	if ((arg_code_type & 3) != 0)
		return (0);
	a = 4;
	while (a-- > 1)
		check_arg[2 - (a - 1)] = check_arg_fill(arg_code_type, (a - 1));
	if (!(check_arg[1]) && check_arg[2])
		return (0);
	while (check_arg[a])
		a++;
	if (a != operation.nbrarg)
		return (0);
	a = 0;
	while (operation.arg[a])
	{
		if ((operation.arg[a] & check_arg[a]) == 0)
			return (0);
		a++;
	}
	return (check_registers(check_arg));
}

static void				move_error_code(t_cursor *wst, t_arena *arena)
{
	wst->next_operation_steps = next_operation_steps_calculation(wst, arena->memory[wst->current_position + 1]);
	wst->dont_move = 0;
	wst->cycles_remaining = 0;
}

void					do_operations(t_cursor *wst, t_arena *arena, t_cursor **cursor)
{
	if (wst->current_code >= 0x01 && wst->current_code <= 0x10)
	{
		if (op_tab[(int)wst->current_code].argument_code_type)
			if (!(argument_code_type_check(arena->memory[wst->current_position + 1], op_tab[(int)wst->current_code])))
				move_error_code(wst, arena);
		exactly_do((int)wst->current_code, wst, cursor, arena);
		wst->next_operation_steps = next_operation_steps_calculation(wst, arena->memory[wst->current_position + 1]);
	}
	else
	{
		wst->current_position += 1;
		wst->dont_move = 1;
	}
}

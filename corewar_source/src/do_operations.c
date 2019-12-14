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

static int 	check_registers() // TODO need to check if registers are valid (бля проверить короче валидны ли регистры ; я ебал на английском писать)
{
	return (1);
}

static int	argument_code_type_check_ex(unsigned char arg_code_type, t_op operation, unsigned char check_arg[3])
{
	int 	a;

	if ((arg_code_type & 12) == 12)
		check_arg[2] = T_IND;
	else if ((arg_code_type & 8) == 8)
		check_arg[2] = T_DIR;
	else if ((arg_code_type & 4) == 4)
		check_arg[2] = T_REG;
	else
		check_arg[2] = 0;
	if (!(check_arg[1]) && check_arg[2])
		return (0);
	a = 0;
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
	return (1);
}

static int	argument_code_type_check(unsigned char arg_code_type, t_op operation)
{
	unsigned char	check_arg[3];

	if (!arg_code_type)
		return (0);
	if ((arg_code_type & 3) != 0)
		return (0);
	if ((arg_code_type & 192) == 192)
		check_arg[0] = T_IND;
	else if ((arg_code_type & 128) == 128)
		check_arg[0] = T_DIR;
	else if ((arg_code_type & 64) == 64)
		check_arg[0] = T_REG;
	else
		return (0);
	if ((arg_code_type & 48) == 48)
		check_arg[1] = T_IND;
	else if ((arg_code_type & 32) == 32)
		check_arg[1] = T_DIR;
	else if ((arg_code_type & 16) == 16)
		check_arg[1] = T_REG;
	else
		check_arg[1] = 0;
	return (argument_code_type_check_ex(arg_code_type, operation, check_arg));
}

static void	move_error_code(t_cursor *wst, t_arena *arena)
{
	wst->next_operation_steps = next_operation_steps_calculation(wst, arena->memory[wst->current_position + 1]);
	wst->dont_move = 0;
	wst->cycles_remaining = 0;
}

void		do_operations(t_cursor *wst, t_arena *arena)
{
	if (wst->current_code >= 0x01 && wst->current_code <= 0x10)
	{
		if (op_tab[(int)wst->current_code].argument_code_type)
			if (!(argument_code_type_check(arena->memory[wst->current_position + 1], op_tab[(int)wst->current_code])))
				move_error_code(wst, arena);
		if (!(check_registers()))
			move_error_code(wst, arena);
		exactly_do((int)wst->current_code);
		wst->next_operation_steps = next_operation_steps_calculation(wst, arena->memory[wst->current_position + 1]);
	}
	else
	{
		wst->current_position += 1;
		wst->dont_move = 1;
	}
}
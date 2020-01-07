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

//static unsigned char	check_arg_fill(unsigned char arg_code_type, int buff)
//{
//	unsigned char	check;
//
//	check = 3 << ((buff + 1) * 2);
//	if ((arg_code_type & check) == check)
//		return (T_IND);
//	else if ((arg_code_type & (check - (check / 3))) == (check - (check / 3)))
//		return (T_DIR);
//	else if ((arg_code_type & (check / 3)) == (check / 3))
//		return (T_REG);
//	else
//		return (0);
//}

int 	check_one_arg(t_cursor *wst, t_arena *arena, int arg_order, t_op operation)
{
	int current_pos;
	unsigned char arg;

	current_pos = wst->cur_pos + wst->next_op_steps;
	arg = wst->args[arg_order];
	if (!(arg & operation.arg_types[arg_order]))
		return (0);
	if (arg == REG_CODE)
	{			// МЫ ОСТАНОВИЛИСЬ ЗДЕСЬ
		wst->next_op_steps++;
		if (arena->map[current_pos] < 1 || arena->map[current_pos] > 16)
			return (0);
	}
	else if (arg == DIR_CODE)
		wst->next_op_steps += operation.t_dir_size;
	else if (arg == IND_CODE)
		wst->next_op_steps += 2;
	else
		return (0);
	return (1);
}

int		check_args(t_cursor *wst, t_arena *arena, t_op operation)
{
	int arg_order;
	int nbr_arg;

	arg_order = -1;
	nbr_arg = 0;
	while (++arg_order < operation.nbrarg)
		if (check_one_arg(wst, arena, arg_order, operation))
			nbr_arg++;
	if (nbr_arg != operation.nbrarg)
		return (0);
	return (1);
}

static int	argument_code_type_check(t_cursor *wst, t_arena *arena, t_op operation)
{
	unsigned char args_type_code;
	unsigned char byte_shift;
	int	i;

	args_type_code = arena->map[wst->cur_pos + 1];
	wst->next_op_steps++;
	i = 0;
	while (i < operation.nbrarg)
	{
		byte_shift = 6u - i * 2;
		wst->args[i] = (args_type_code >> byte_shift) & 0x03u;
		i++;
	}
	if (!check_args(wst, arena, operation) || args_type_code & 0x03u)
		return (1);
	return (0);
}

static void	move_error_code(t_cursor *wst)
{
	wst->cur_pos += wst->next_op_steps;
	wst->cycles_remaining = 0;
}

void		do_operation(t_cursor *wst, t_arena *arena)
{
	t_op	curr_op;

	curr_op = op_tab[(int)wst->current_op];
	if (wst->current_op >= 0x01 && wst->current_op <= 0x10)
	{
		wst->next_op_steps++;
		if (curr_op.arg_code_type)
			if (argument_code_type_check(wst, arena, curr_op))
				move_error_code(wst);
		wst->next_op_steps = 0;
		op_tab[wst->current_op].func(arena, wst);
	}
	else
		wst->cur_pos += 1;
}

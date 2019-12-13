/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:29:15 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/11 18:29:17 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	next_operation_argument_code_type_case(t_cursor *cursor,
		int arg_type)
{
	int		num;

	num = 0;
	if ((arg_type & 192) == 192)
		num += T_IND_SIZE;
	else if ((arg_type & 128) == 128)
		num += op_tab[(int)cursor->current_code].t_dir_size;
	else if ((arg_type & 64) == 64)
		num += T_REG_SIZE;
	if ((arg_type & 48) == 48)
		num += T_IND_SIZE;
	else if ((arg_type & 32) == 32)
		num += op_tab[(int)cursor->current_code].t_dir_size;
	else if ((arg_type & 16) == 16)
		num += T_REG_SIZE;
	if ((arg_type & 12) == 12)
		num += T_IND_SIZE;
	else if ((arg_type & 8) == 8)
		num += op_tab[(int)cursor->current_code].t_dir_size;
	else if ((arg_type & 4) == 4)
		num += T_REG_SIZE;
	return (num);
}

int			next_operation_steps_calculation(t_cursor *cursor,
		unsigned char arg_type)
{
	int		num;
	int		a;

	a = 0;
	num = 1;
	num += op_tab[(int)cursor->current_code].argument_code_type;
	if (op_tab[(int)cursor->current_code].argument_code_type)
		num += next_operation_argument_code_type_case(cursor, arg_type);
	else
	{
		while (a < 3)
		{
			if (op_tab[cursor->current_code].arg[a])
			{
				if (op_tab[(int)cursor->current_code].arg[a] == T_DIR)
					num += op_tab[(int)cursor->current_code].t_dir_size;
				if (op_tab[(int)cursor->current_code].arg[a] == T_REG)
					num += T_REG_SIZE;
				if (op_tab[(int)cursor->current_code].arg[a] == T_IND)
					num += T_IND_SIZE;
			}
			a++;
		}
	}
	return (num);
}

void		cursor_operations_exec(t_cursor **cursor, t_arena *arena)
{
	t_cursor	*wst;

	wst = *cursor;
	while (wst)
	{
		if (wst->cycles_remaining == 0 || wst->dont_move)
		{
			if (!wst->dont_move)
				wst->current_position += wst->next_operation_steps;
			wst->current_code = arena->memory[wst->current_position];
			wst->dont_move = 0;
			if (wst->current_code >= 0x01 && wst->current_code <= 0x10)
				wst->cycles_remaining =
						op_tab[(int)wst->current_code].need_cycles;
			else
				wst->cycles_remaining = 0;
		}
		if (wst->cycles_remaining > 0)
			wst->cycles_remaining--;
		if (wst->cycles_remaining == 0)
			do_operations(wst, arena);  // TODO need to parse all operations and pastle them to this funct
		wst = wst->next;
	}
}

void		dead_cursor(t_cursor **cursor, t_cursor **start)
{
	t_cursor	*wst;

	if ((*cursor))
	{
		if ((*cursor)->prev)
		{
			(*cursor)->prev->next = (*cursor)->next;
			wst = (*cursor);
			(*cursor) = (*cursor)->prev;
			free(wst);
		}
		if (!((*cursor)->prev))
		{
			(*start) = (*cursor)->next;
			if (*start)
				(*start)->prev = NULL;
			wst = (*cursor);
			(*cursor) = (*cursor)->next;
			free(wst);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exactly_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:57:20 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/14 17:57:21 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
//todo: нужно сделать запоминание команды до начала циклов и сделать проверку операции после циклов (переменная в структуре?)

void	exactly_do(t_cursor *wst, t_cursor **cursor, t_arena *arena) // TODO need to EXACTLY! do operation with operation num added as argument
{
	t_op op_ptr;

	op_ptr = op_tab[wst->current_code];
//	op_tab[wst->current_code].func(arena, wst);



//	if (arena->checks == 10000000)
//	{
//		wst = NULL;
//		cursor = NULL;
//	}
}

int		get_arg(t_arena *arena, t_cursor *cursor, int current_position, int mod)
{
	int 	value;
	int		addr;
	t_op	*op;

	value = 0;
	addr = 0;
//	op = &op_tab[INDEX(cursor->operation_code)];// переменная, где хранится значение команды, которая сейчас выполняется
	if (cursor->current_code & T_DIR)
		value = byte_shift(cursor->current_code, op->t_dir_size);
	if (cursor->current_code & T_REG)
		value = cursor->reg[INDEX(current_position)];
	if (cursor->current_code & T_IND)
	{
		addr = byte_shift(cursor->current_code, IND_SIZE);
		value = byte_shift(arena->map[current_position + (mod ? (addr % IDX_MOD) : addr)], DIR_SIZE );
	}
	return (value);
}
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

int 	get_value(t_arena *arena, t_cursor *cursor, unsigned char arg, int mod)
{
	int 			value;
	int				addr;
	int				current_position;
	t_op			*op;
	unsigned char	*arr;

	value = 0;
	addr = 0;
	current_position = cursor->current_position;
	op = &op_tab[cursor->current_op];
	if (arg == T_DIR)
	{
		arr = get_new_arr(arena, cursor->next_op_steps, op->t_dir_size);
		value = byte_to_int(&arena->map[cursor->current_position], op->t_dir_size);
		cursor->current_position = get_map_ind(current_position, op->t_dir_size);
	}
	if (arg == T_REG)
	{
		value = cursor->reg[current_position];
		cursor->current_position = get_map_ind(current_position, T_REG_SIZE);
	}
	0b 68 01 00 05
	if (arg == T_IND)
	{
		arr = get_new_arr(arena, cursor->next_op_steps, IND_SIZE);		//	get_new_arr вернет массив из unsigned char-ов
		addr = byte_to_int(arr, IND_SIZE);								//  здесь достается значение аргумента t_ind
		arr = get_new_arr(arena, current_position + (mod ? (addr % IDX_MOD) : addr), DIR_SIZE);	//	здесь кладется в массив значение на карте через addr байт
		value = byte_to_int(arr, DIR_SIZE);
		cursor->current_position = get_map_ind(current_position, T_IND_SIZE);
	}
	return (value);
}

int get_arg(t_arena *arena, t_cursor *cursor, unsigned char arg, int mod)
{
	int		current_position;
	t_op	*op;

	current_position = cursor->current_position;
	op = &op_tab[cursor->current_op];

	return (get_value(arena, cursor, arg, mod));
}
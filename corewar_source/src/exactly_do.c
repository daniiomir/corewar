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
//
//int		get_arg(t_arena *arena, t_cursor *cursor, int current_position, int mod)
//{
//	t_op	*op_ptr;
//	int 	value;
//	int		addr;
//
////	op_ptr = &op_tab[current_position]; //не убавляем на 1, чтобы оказаться в следующей ячейке
//	value = 0;
//	if ()
//}

void	exactly_do(t_cursor *wst, t_cursor **cursor, t_arena *arena) // TODO need to EXACTLY! do operation with operation num added as argument
{
	t_op op_ptr;

	op_ptr = op_tab[wst->current_code];
	op_tab[wst->current_code].func(arena, wst);



	if (arena->checks == 10000000)
	{
		wst = NULL;
		cursor = NULL;
	}
}
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

#include "main_alg.h"

int 				next_operation_steps_calculation(t_cursor *next, unsigned char arg_type)
{
	int 	num;
	int 	a;

	a = 0;
	num = 1;
	num += op_tab[next->current_code].argument_code_type;
	if (op_tab[next->current_code].argument_code_type)
	{
		if ((arg_type & 192) == 192)
			num += T_IND_SIZE;
		else if ((arg_type & 128) == 128)
			num += op_tab[next->current_code].t_dir_size;
		else if ((arg_type & 64) == 64)
			num += T_REG_SIZE;
		if ((arg_type & 48) == 48)
			num += T_IND_SIZE;
		else if ((arg_type & 32) == 32)
			num += op_tab[next->current_code].t_dir_size;
		else if ((arg_type & 16) == 16)
			num += T_REG_SIZE;
		if ((arg_type & 12) == 12)
			num += T_IND_SIZE;
		else if ((arg_type & 8) == 8)
			num += op_tab[next->current_code].t_dir_size;
		else if ((arg_type & 4) == 4)
			num += T_REG_SIZE;
	}
	else
	{
		while (a < 3)
		{
			if (op_tab[next->current_code].arg[a])
			{
				if (op_tab[next->current_code].arg[a] == T_DIR)
					num += op_tab[next->current_code].t_dir_size;
				if (op_tab[next->current_code].arg[a] == T_REG)
					num += T_REG_SIZE;
				if (op_tab[next->current_code].arg[a] == T_IND)
					num += T_IND_SIZE;
			}
			a++;
		}
	}
	return (num);
}

void 				dead_cursor(t_cursor **cursor, t_cursor **start)
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
			wst = (*cursor);
			(*cursor) = (*cursor)->next;
			free(wst);
		}
	}
}
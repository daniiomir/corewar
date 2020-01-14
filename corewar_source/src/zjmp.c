/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:51:05 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 12:51:19 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

void	op_zjmp(t_gstate *gstate, t_cursor *cursor)
{
	int addr;

	cursor->steps += 1;
	addr = get_arg(gstate->arena, cursor, T_DIR, 1);
	if (cursor->f_carry)
		cursor->steps = addr % IDX_MOD;
}

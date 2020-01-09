/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:11:44 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 14:11:45 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_live(t_gstate *gstate, t_cursor *cursor)
{
	int arg;

	cursor->next_op_steps += 1;
	arg = get_arg(gstate->arena, cursor, T_DIR, 0);
}

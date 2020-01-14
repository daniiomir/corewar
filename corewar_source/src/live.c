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

	cursor->steps += 1;
	arg = get_arg(gstate->arena, cursor, T_DIR, 0);
	cursor->last_live_cycle = gstate->arena->all_cycles;
	gstate->arena->lives_nbr++;
	if (arg <= -1 && arg >= gstate->players_num * -1)
	{
		gstate->all_players[INDEX(ft_abs(arg))]->last_live_cycle =
				gstate->arena->all_cycles;
		gstate->all_players[INDEX(ft_abs(arg))]->lives_in_cur_period++;
		gstate->arena->last_live = ft_abs(arg);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:09:20 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 14:09:21 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	fill_arena_and_init_cursors(t_arena *arena, t_gstate *gstate)
{
	int			i;
	int			step;
	int			first_pos;
	t_cursor	*current;
	t_cursor	*first_cursor;

	i = 0;
	step = MEM_SIZE / gstate->players_num;
	first_pos = 0;
	first_cursor = NULL;
	while (i < gstate->players_num)
	{
		ft_memcpy(arena->map + first_pos,
				gstate->all_players[i]->code, gstate->all_players[i]->size);
		current = init_cursor(i + 1, i + 1);
		current->pos = first_pos;
		current->next = first_cursor;
		first_cursor = current;
		first_pos += step;
		gstate->processes_num++;
		i++;
	}
	gstate->first_cursor = first_cursor;
}

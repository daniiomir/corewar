/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:12:27 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/09 17:12:30 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

t_cursor		*fill_arena_and_init_cursors(t_arena *arena, t_gstate *gstate)
{
	int 		step;
	int 		first_pos;
	int 		i;
	t_cursor	*current;
	t_cursor	*first_cursor;

	step = MEM_SIZE / gstate->players_num;
	first_pos = 0;
	i = 0;
	while (i < gstate->players_num)
	{
		ft_memcpy(arena->map + first_pos, gstate->all_players[i]->code, gstate->all_players[i]->size);
		current = init_cursor(i + 1, i + 1);
		current->current_position = first_pos;
		current->next = first_cursor;
		first_cursor = current;
		first_pos += step;
		i++;
	}
	return (first_cursor);
}

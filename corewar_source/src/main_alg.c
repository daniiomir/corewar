/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:27:44 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 13:27:46 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

static void		update_players_state(t_gstate *gstate)
{
	int i;

	i = 0;
	while (i < gstate->players_num)
	{
		gstate->all_players[i]->lives_in_cur_period = 0;
		i++;
	}
}

static void		update_arena_state(t_gstate *gstate)
{
	t_arena *arena;

	arena = gstate->arena;
	arena->checks++;
	if (arena->lives_nbr >= NBR_LIVE || arena->checks >= MAX_CHECKS)
	{
		arena->cycle_to_die -= CYCLE_DELTA;
		arena->checks = 0;
		update_players_state(gstate);
	}
	arena->lives_nbr = 0;
}

static void		check_cursors_is_alive(t_gstate *gstate)
{
	t_arena		*arena;
	t_cursor	*current;

	arena = gstate->arena;
	current = gstate->first_cursor;
	while (current)
	{
		if (arena->all_cycles - current->last_live_cycle >= arena->cycle_to_die)
		{
			if (gstate->f_v)
				gstate->vis->map[current->cur_pos].is_cursor = 0;
			kill_cursor(&current, &gstate->first_cursor);
			gstate->processes_num--;
			continue ;
		}
		current = current->next;
	}
}

void			one_cycle(t_gstate *gstate)
{
	t_arena		*arena;
	static int	prev_check;

	arena = gstate->arena;
	gstate->arena->all_cycles++;
	cursor_operations_exec(gstate);
	if (arena->all_cycles - prev_check == arena->cycle_to_die
		|| arena->cycle_to_die <= 0)
	{
		check_cursors_is_alive(gstate);
		update_arena_state(gstate);
		prev_check = arena->all_cycles;
	}
}


void main_alg(t_gstate *gstate)
{
	init_battle(gstate);
	print_arena(gstate->arena, gstate->first_cursor);
	while (gstate->processes_num)
		one_cycle(gstate);
	end_of_battle(gstate);
	free_all(gstate->arena, gstate->first_cursor, gstate);
}
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

#include "corewar.h"
#include <stdio.h>

static void		update_arena_state(t_arena *arena)
{
	if (arena->lives_nbr >= NBR_LIVE || arena->checks >= MAX_CHECKS)
	{
		arena->cycle_to_die -= CYCLE_DELTA;
		arena->checks = 1;
		arena->lives_nbr = 0;
	}
	else
		arena->checks++;
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
			kill_cursor(&current, gstate->first_cursor);
			gstate->processes_num--;
		}
		if (!current)
			break ;
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
		update_arena_state(arena);
		prev_check = arena->all_cycles;
	}
}

void			main_cycle(t_gstate *gstate)
{
	while (gstate->processes_num)
	{
		one_cycle(gstate);
	}
}

void			init_battle(t_gstate *gstate)
{
	int	a;

	a = 0;
	printf("\e[1;1H\e[2J");
	printf("Introducing contestants...\n");
	while (a < gstate->players_num)
	{
		printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", (a + 1),
				gstate->all_players[a]->size, gstate->all_players[a]->name,
				gstate->all_players[a]->comment);
		a++;
	}
//	sleep(1);
}

void			end_of_battle(void)
{
	printf("\e[1;1H\e[2J");
	printf("pobedil STEPAN!");
}

void			main_alg(t_gstate *gstate)
{
//	init_battle(gstate);					// нужно будет перенести в main
//	print_arena(arena, arena->first_cursor);					// нужно будет перенести в main
	main_cycle(gstate);
//	end_of_battle();					// нужно будет перенести в main
//	free_all(arena, arena->first_cursor, gstate);					// нужно будет перенести в main
}

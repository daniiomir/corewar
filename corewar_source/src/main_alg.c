/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:53:16 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/09 16:53:18 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

static void update_arena_state(t_arena *arena)
{
	if (arena->lives_nbr >= NBR_LIVE || arena->checks >= MAX_CHECKS)
	{
		arena->cycles_to_die -= CYCLE_DELTA;
		arena->checks = 0;
		arena->lives_nbr = 0;
	}
	else
		arena->checks++;
}

static void check_cursor_is_alive(t_arena *arena, t_cursor **cursors)
{
	t_cursor			*current;

	current = (*cursors);
	while (current)
	{
		if (arena->all_cycles - current->last_live_cycle >= arena->cycles_to_die)
			kill_cursor(&current, cursors);
		if (!current)
			continue ;
		current = current->next;
	}
}

void	end_of_battle()
{
	printf("\e[1;1H\e[2J");
	printf("pobedil STEPAN!"); // почти закончен вывод, только чуток дописать
}

void	main_cycle(t_arena *arena, t_cursor **cursors)
{
	static int	prev_check;

    while (*cursors)
    {
		cursor_operations_exec(arena, cursors);
        if (arena->all_cycles - prev_check == arena->cycles_to_die || arena->cycles_to_die <= 0) //событие "проверка"
        {
			check_cursor_is_alive(arena, cursors);
			update_arena_state(arena);
            prev_check = arena->all_cycles;
        }
        arena->all_cycles++;
    }
}

void	init_battle(t_gstate *gstate)
{
	int 		a;

	a = 0;
	printf("\e[1;1H\e[2J");
	printf("Introducing contestants...\n");
	while (a < gstate->players_num)
	{
			   printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			   (a + 1), gstate->all_players[a]->size, gstate->all_players[a]->name,
			   gstate->all_players[a]->comment);
		a++;
	}
//	sleep(1);
}

void main_alg(t_gstate *gstate, t_arena *arena, t_cursor *cursors)
{
//	t_arena		*arena;
//	t_cursor	*cursors;

//	arena = init_arena();
//	cursors = fill_arena_and_init_cursors(arena, gstate);
	init_battle(gstate);
	print_arena(arena, cursors);
	main_cycle(arena, &cursors);
	end_of_battle();
	free_all(arena, cursors, gstate);
}
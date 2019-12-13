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

void	end_of_battle()
{
	printf("\e[1;1H\e[2J");
	printf("pobedil STEPAN!"); // почти закончен вывод, только чуток дописать
}

void	main_cycle(t_arena *arena, t_cursor *cursor)
{
	t_cursor	*wst;

    while (cursor)
    {
    	cursor_operations_exec(&cursor, arena);
        if (arena->all_cycles % arena->cycles_to_die == 0 || arena->cycles_to_die <= 0)
        {
        	wst = cursor;
            while (wst)
            {
                if (arena->all_cycles - wst->last_live_cycle >= arena->cycles_to_die
                || arena->cycles_to_die <= 0)
                    dead_cursor(&wst, &cursor);
                if (!wst)
					continue ;
				wst = wst->next;
            }
            if (arena->recent_live >= NBR_LIVE || arena->checks >= MAX_CHECKS)
			{
				arena->cycles_to_die -= CYCLE_DELTA;
				arena->checks = 0;
				arena->recent_live = 0;
			}
            else
            	arena->checks++;
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
	sleep(1);
}

void	main_alg(t_gstate *gstate)
{
	t_arena		*arena;
	t_cursor	*cursor;

	arena = init_arena();
	fill_champions_code(arena, gstate);
	cursor = fill_cursors(gstate);
	init_battle(gstate);
	print_arena(arena, cursor);
	main_cycle(arena, cursor);
	end_of_battle();
	free_all(arena);
}
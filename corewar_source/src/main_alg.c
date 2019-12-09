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
	printf("pobedil STEPAN!"); // почти закончен вывод, только чуток дописать
}

void	main_cycle()
{
	printf("CHEMPIONY SRAZHAUTSYA DAAAAA"); // почти закончил функцию, надо парочку вещей всего дописать
}

void	init_battle(t_champ *champs)
{
	t_champs	*wst;
	int 		a;

	wst = champs;
	a = 0;
	while (wst)
	{
		printf("Introducing contestants...\n"
			   "* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			   a, 0, wst->name, wst->comment); // где ноль я хз где эта инфа лежит
		wst = wst->next;
	}
}

void	main_alg(t_gstate *gstate, t_champ *champs)
{
	t_arena		*arena;
	t_cursor	*cursor;

	arena = init_arena();
	fill_champions_code(arena, gstate, champs);
	cursor = fill_cursors(arena, gstate);
	init_battle(champs);
	print_arena(arena);
	main_cycle();
	end_of_battle();
	free_all(arena);
}
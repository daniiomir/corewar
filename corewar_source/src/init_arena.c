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

#include "arena.h"
#include "corewar.h"
#include <stdio.h>

void		print_arena(t_arena *arena)
{
	int 	a;

	a = 0;
	printf("\n");
	while (a < MEM_SIZE)
	{
		printf("%02x ", arena->memory[a++]);
		if (a % 64 == 0)
			printf("\n");
	}
}

t_arena		*init_arena()
{
	t_arena		*arena;

	if (!(arena = (t_arena *)malloc(sizeof(t_arena))))
		return (NULL);
	ft_bzero(arena->memory, MEM_SIZE);
	arena->last_live = 0;
	arena->all_cycles = 0;
	arena->recent_live = 0;
	arena->cycles_to_die = CYCLE_TO_DIE;
	arena->checks = 0;
	arena->next_cursor_num = 0;
	return (arena);
}

t_cursor	*init_cursor(int num, int reg)
{
	t_cursor	*cursor;

	if (!(cursor = (t_cursor*)malloc(sizeof(t_cursor))))
		return (NULL);
	cursor->carry = 0;
	cursor->current_code = NULL;
	cursor->current_position = 0;
	cursor->cycles_remaining = 0;
	cursor->last_live_cycle = 0;
	cursor->next = NULL;
	cursor->next_operation_steps = 0;
	cursor->num = num;
	ft_bzero(cursor->reg, 16);
	cursor->reg[0] = -1 * reg;
	return (cursor);
}

void		fill_champions_code(t_arena *arena, t_gstate *gstate, t_champ *champs)
{
//	int 	order;
//	t_champ	*champs; // TODO: зачем, если в аргументах уже есть champs?
//	int 	a;
//	int 	b;
//
//	order = MEM_SIZE / gstate->players_num;
//	while(champs)
//	{
//		a = order;
//		b = 0;
//		while (champs->code[b])
//			arena->memory[a++] = champs->code[b++];
//		champs = champs->next;
//		order += order;
//	}
}

void		fill_cursors(t_arena *arena, t_gstate *gstate)
{
	int 		order;
	t_cursor	*cursor;
	t_cursor	*next;
	t_cursor	*curr;
	int 		a;

	order = MEM_SIZE / gstate->players_num;
	a = 1;
	cursor = init_cursor(a, a);
	a++;
	curr = cursor;
	while (a <= gstate->players_num)
	{
		next = init_cursor(a, a);
		next->current_position = order;
		next->next = curr;
		next->next_operation_steps = 0; // я не знаю пока как это написать
		next->current_code = NULL; // и это тоже, а все остальные параметры вроде как норм заданны
		curr = next;
		order += order;
	}
}
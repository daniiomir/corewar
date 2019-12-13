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

#include "main_alg.h"
#include "corewar.h"
#include <stdio.h>

t_arena		*init_arena()
{
	t_arena		*arena;
	int 		a;

	a = 0;
	if (!(arena = (t_arena *)malloc(sizeof(t_arena))))
		return (NULL);
	while (a < MEM_SIZE)
		arena->memory[a++] = 0x0;
	arena->last_live = 0;
	arena->all_cycles = 0;
	arena->recent_live = 0;
	arena->cycles_to_die = CYCLE_TO_DIE;
	arena->checks = 0;
	arena->next_cursor_num = 0;
	return (arena);
}

void		fill_champions_code(t_arena *arena, t_gstate *gstate)	// TODO: эту функцию, можно упростить и заменить на вторую версию (ниже)
{
	int 	order;
	int 	a;
	int 	b;
	int 	c;
	int 	d;

	order = MEM_SIZE / gstate->players_num;
	c = 0;
	a = 0;
	while(c < gstate->players_num)
	{
		b = 0;
		d = a;
		while (b < gstate->all_players[c]->size)
			arena->memory[a++] = gstate->all_players[c]->code[b++];
		c++;
		a = d;
		a += order;
	}
}
/*
void		fill_champions_code(t_arena *arena, t_gstate *gstate)		// вторая весия
{
	int 	step;
	int 	first_pos;
	int 	i;

	step = MEM_SIZE / gstate->players_num;
	first_pos = 0;
	i = 0;
	while(i < gstate->players_num)
	{
		ft_memcpy(arena->memory + first_pos, gstate->all_players[i]->code, gstate->all_players[i]->size);
		first_pos += step;
		i++;
	}
}
*/

// TODO: а вторую версию уже возможно объеденить с fill_cursors (пример ниже) (но выглядит не очень, поэтому сам решай как поступить)
/*
t_cursor	*fill_champions_code_and_cursors(t_arena *arena, t_gstate *gstate)
{
	int 		step;
	int 		first_pos;
	t_cursor	*next;
	t_cursor	*curr;
	int 		i;

	step = MEM_SIZE / gstate->players_num;
	first_pos = 0;
	curr = NULL;
	i = 0;
	while(i < gstate->players_num)
	{
		ft_memcpy(arena->memory + first_pos, gstate->all_players[i]->code, gstate->all_players[i]->size);
		next = init_cursor(i, i);
		next->current_position = first_pos;
		next->next = curr;
		next->current_code = arena->memory[first_pos];
		next->next_operation_steps = next_operation_steps_calculation(next, arena->memory[first_pos + 1]);
		if (curr)
			curr->prev = next;
		curr = next;
		first_pos += step;
		i++;
	}
	return (curr);
}
*/


static t_cursor		*init_cursor(int id, int reg)
{
	t_cursor	*cursor;
	int 		a;

	a = 0;
	if (!(cursor = (t_cursor *)malloc(sizeof(t_cursor))))
		return (NULL);
	cursor->carry = 0;
	cursor->current_code = 0;
	cursor->current_position = 0;
	cursor->cycles_remaining = 0;
	cursor->last_live_cycle = 0;
	cursor->next = NULL;
	cursor->prev = NULL;
	cursor->next_operation_steps = 0;
	cursor->id = id;
	while (a < 16)
		cursor->reg[a++] = 0;
	cursor->reg[0] = -1 * reg;
	return (cursor);
}

t_cursor			*fill_cursors(t_gstate *gstate, t_arena *arena)
{
	int 		order;
	t_cursor	*next;
	t_cursor	*curr;
	int 		a;
	int 		b;

	order = MEM_SIZE / gstate->players_num;
	b = 0;
	a = 1;
	curr = NULL;
	while (a <= gstate->players_num)
	{
		next = init_cursor(a, a);
		next->current_position = b;
		next->next = curr;
		next->current_code = arena->memory[b];
		next->next_operation_steps = next_operation_steps_calculation(next, arena->memory[b + 1]);
		if (curr)
			curr->prev = next;
		curr = next;
		b += order;
		a++;
	}
	return (curr);
}
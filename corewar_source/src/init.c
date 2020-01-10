/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:07:30 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 14:07:30 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vis.h>

t_gstate	*init_global_state(void)
{
	t_gstate *gstate;

	gstate = (t_gstate *)malloc(sizeof(t_gstate));
	if (gstate == NULL)
		print_error_and_exit("Memory does not allocated", 3);
	gstate->players_num = 0;
	ft_bzero(&gstate->all_players, MAX_PLAYERS * sizeof(t_champ*));
	gstate->f_dump = 0;
	gstate->f_dump_arg = 0;
	gstate->f_v = 0;
	gstate->f_a = 0;
	gstate->processes_num = 0;
	return (gstate);
}

t_champ		*init_champion(int n_arg, int id)
{
	t_champ *player;

	if ((player = (t_champ *)malloc(sizeof(t_champ))) == NULL)
		print_error_and_exit("Memory does not allocated", 3);
	player->f_n_arg = n_arg;
	player->id = id + 1;
	player->name = NULL;
	player->comment = NULL;
	player->size = 0;
	player->code = NULL;
	player->lives_in_cur_period = 0;
	player->last_live_cycle = 0;
	return (player);
}

t_arena		*init_arena()
{
	t_arena		*arena;

	arena = (t_arena *)malloc(sizeof(t_arena));
	if (arena == NULL)
		print_error_and_exit("Memory does not allocated", 3);
	ft_bzero(arena->map, MEM_SIZE);
	arena->last_live = 1;
	arena->all_cycles = 0;
	arena->lives_nbr = 0;
	arena->cycle_to_die = CYCLE_TO_DIE;
	arena->checks = 1;
	arena->next_cursor_num = 0;
	return (arena);
}

t_cursor		*init_cursor(int id, int reg)
{
	t_cursor	*cursor;

	if (!(cursor = (t_cursor *)malloc(sizeof(t_cursor))))
		print_error_and_exit("Memory does not allocated", 3);
	cursor->f_carry = 0;
	cursor->current_op = 0;
	cursor->cur_pos = 0;
	cursor->cycles_remaining = 0;
	cursor->last_live_cycle = 0;
	cursor->next = NULL;
	cursor->next_op_steps = 0;
	cursor->player_id = id;
	ft_bzero(cursor->args, 3);
	ft_bzero(cursor->reg, sizeof(int) * 16);
	cursor->reg[0] = -1 * reg;
	return (cursor);
}

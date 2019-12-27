#include "../includes/corewar.h"

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
	return (player);
}

t_arena		*init_arena()
{
	t_arena		*arena;

	if (!(arena = (t_arena *)malloc(sizeof(t_arena))))
		return (NULL);
	ft_bzero(arena->map, MEM_SIZE);
	arena->last_live = 0;
	arena->all_cycles = 0;
	arena->lives_nbr = 0;
	arena->cycles_to_die = CYCLE_TO_DIE;
	arena->checks = 0;
	arena->next_cursor_num = 0;
	return (arena);
}

t_cursor		*init_cursor(int id, int reg)
{
	t_cursor	*cursor;

	if (!(cursor = (t_cursor *)malloc(sizeof(t_cursor))))
		return (NULL);
	cursor->carry = 0;
	cursor->current_op = 0;
	cursor->current_position = 0;
	cursor->cycles_remaining = 0;
	cursor->last_live_cycle = 0;
	cursor->next = NULL;
	cursor->next_op_steps = 0;
	cursor->id = id;
	ft_bzero(cursor->args, 3);
	ft_bzero(cursor->reg, 16);
	cursor->reg[0] = -1 * reg;
	return (cursor);
}

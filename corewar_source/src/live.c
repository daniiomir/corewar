#include "corewar.h"

void	op_live(t_gstate *gstate, t_cursor *cursor)
{
	int arg;

	cursor->next_op_steps += 1;
	arg = get_arg(gstate->arena, cursor, T_DIR, 0);
	cursor->last_live_cycle = gstate->arena->all_cycles;
	gstate->arena->lives_nbr++;
	if (arg <= -1 && arg >= gstate->players_num * -1)
	{
		gstate->all_players[ft_abs(arg)]->last_live_cycle = gstate->arena->all_cycles;
		gstate->all_players[ft_abs(arg)]->lives_in_cur_period++;
		gstate->arena->last_live = ft_abs(arg);
	}
}

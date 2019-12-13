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

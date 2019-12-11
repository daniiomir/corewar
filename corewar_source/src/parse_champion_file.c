#include "corewar.h"

void	parse_champion_file(t_gstate *gstate, int *argc, char ***argv)
{
	int	champion_order;

	champion_order = 0;
	if (ft_strequ(**argv, "-n"))
		champion_order = parse_flag_n(argc, argv);
	if (is_champion_filename(**argv))
		parse_champion(champion_order, **argv);
}


/*
int i = 0;
		int g = 0;

		char *all_champs = {champ1, 0, champ3, 0};
		char queue[4] = {champ2, 0, champ4, 0};

		while (i < gstate->players_num) {		// i = 1; players_num = 4
			if (all_champs[g] == 0) {
				g++;
				continue ;
			}

			if (queue[i] != 0) {
				i++;
				continue ;
			}
			queue[i] = all_champs[g];
		}*/

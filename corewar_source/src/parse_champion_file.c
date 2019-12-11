#include "corewar.h"

void	parse_champion_file(t_gstate *gstate, int *argc, char ***argv)
{
	int	champion_order;

	champion_order = -1;
	if (ft_strequ(**argv, "-n"))
		champion_order = parse_flag_n(argc, argv);

}

#include "../includes/corewar.h"

static void    champs_with_n(t_gstate *gstate, t_champ **result)
{
	int i;
	int n_arg;

	i = 0;
	while (i < gstate->players_num)
	{
		n_arg = gstate->all_players[i]->f_n_arg;
		if (n_arg && n_arg <= gstate->players_num)
		{
			if (result[n_arg - 1])
				gstate->all_players[i]->f_n_arg = 0;
			else
			{
				result[n_arg - 1] = gstate->all_players[i];
				result[n_arg - 1]->id = n_arg;
			}
		}
		else
			gstate->all_players[i]->f_n_arg = 0;
		i++;
	}
}

static void    remaining_champs(t_gstate *gstate, t_champ **result)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < gstate->players_num)
	{
		if (result[i])
		{
			i++;
			continue;
		}
		if (gstate->all_players[j]->f_n_arg == 0)
		{
			result[i] = gstate->all_players[j];
			result[i]->id = i + 1;
			i++;
			j++;
		}
		else
			j++;
	}
}

void	order_of_champs(t_gstate *gstate)
{
	t_champ	*result[gstate->players_num];

	ft_bzero(&result, gstate->players_num * sizeof(t_champ*));
	champs_with_n(gstate, &(*result));
	remaining_champs(gstate, &(*result));
	ft_memcpy(gstate->all_players, result, gstate->players_num * sizeof(t_champ*));
}
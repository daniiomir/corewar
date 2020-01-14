/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:01:51 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 15:01:52 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			print_arena_and_exit(t_arena *arena, int format)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.4p : ", i);
		j = 0;
		while (j < format)
		{
			ft_printf("%.2x ", arena->map[i + j]);
			j++;
		}
		ft_printf("\n");
		i += format;
	}
	exit(0);
}

void			end_of_battle(t_gstate *gstate)
{
	t_champ *winner;

	winner = gstate->all_players[INDEX(ft_abs(gstate->arena->last_live))];
	ft_printf("Contestant %d, \"%s\", has won !\n", winner->id,
			winner->name);
}

void			init_battle(t_gstate *gstate)
{
	int	a;

	a = 0;
	ft_printf("Introducing contestants...\n");
	while (a < gstate->players_num)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				(a + 1),
				gstate->all_players[a]->size, gstate->all_players[a]->name,
				gstate->all_players[a]->comment);
		a++;
	}
}

void			print_usage(void)
{
	ft_printf("Usage: ./corewar [-v][-d <num> ");
	ft_printf("| -n <num> ] <champion1.cor> <...>\n");
	ft_printf("    -n    N   : Set number of the next player\n");
	ft_printf("    -d    N   : Dumps memory after N cycles then exits" \
		" (32 format)\n");
	ft_printf("    -dump N   : Dumps memory after N cycles then exits" \
		" (64 format)\n");
	ft_printf("    -a        : Prints output from \"aff\" (Default is" \
		" to hide it)\n");
	ft_printf("    -v        : Ncurses output mode (visualisation)\n");
	exit(1);
}

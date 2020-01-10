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
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", (a + 1),
			   gstate->all_players[a]->size, gstate->all_players[a]->name,
			   gstate->all_players[a]->comment);
		a++;
	}
}

void	print_usage(void)
{
	ft_printf("Usage: ./corewar [-v][-d <num> ");
	ft_printf("| -n <num> ] <champion1.cor> <...>\n");
	exit(1);
}

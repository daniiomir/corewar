/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:06:50 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 14:06:51 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void free_players(t_gstate *gstate)
{
	int		i;
	t_champ *player;

	i = 0;
	while (i < gstate->players_num)
	{
		player = gstate->all_players[i];
		free(player->name);
		free(player->comment);
		free(player->code);
		free(player);
		i++;
	}
}

void free_all(t_gstate *gstate)
{
	if (gstate)
	{
		if (gstate->arena)
			free(gstate->arena);
		free_players(gstate);
		if (gstate->f_v)
			free(gstate->vis);
		free(gstate);
	}
}

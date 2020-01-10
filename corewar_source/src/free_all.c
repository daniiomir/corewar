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

void		free_arena(t_arena *arena)
{
	if (arena)
	{
		free(arena);
	}
}

void		free_all(t_arena *arena, t_cursor *cursor, t_gstate *gstate)
{
	int 	a;

	a = 0;
	if (arena)
		free_arena(arena);
	while (cursor)
	{
		free(cursor);
		cursor = cursor->next;
	}
	if (gstate)
	{
		if (gstate->all_players)
		{
			while (gstate->all_players[a])
			{
				if (gstate->all_players[a])
				{
					if (gstate->all_players[a]->code)
						free(gstate->all_players[a]->code);
					if (gstate->all_players[a]->name)
						free(gstate->all_players[a]->name);
					if (gstate->all_players[a]->comment)
						free(gstate->all_players[a]->comment);
					free(gstate->all_players[a]);
				}
				gstate->all_players[a] = NULL;
				a++;
			}
		}
		free(gstate);
	}
}

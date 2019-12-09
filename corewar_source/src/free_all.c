/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:26:42 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/09 18:26:43 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "corewar.h"

void		free_arena(t_arena *arena)
{
	if (arena)
	{
		free(arena);
	}
}

void		free_all(t_arena *arena)
{
	free_arena(arena);
}
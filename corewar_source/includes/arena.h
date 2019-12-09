/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:55:15 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/09 16:55:16 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

#include "../../asm_source/includes/op.h"

/*
** __________________________ Structure Definition _____________________________
**
**  f_*         - flag
**
**	players_num	- number of players.
**  f_dump      - flag dump (stops execution on a specific loop).
**  f_dump_arg  - dump flag argument.
**  f_v         - flag v (visualisation).
*/

typedef struct		s_gstate
{
	int     players_num;
	char    f_dump:2;
	int     f_dump_arg;
	char    f_v:2;
}					t_gstate;


typedef struct	s_arena
{
	unsigned char 	arena[MEM_SIZE];
}				t_arena;

void 	init_arena();

#endif
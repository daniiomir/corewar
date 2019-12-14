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

#include "../includes/corewar.h"

/*
** _______________________________ Structure Definition _______________________________
**
**	memory	      - arena of memory, array of bytes.
**  last_live     - last player to say that he is alive.
**  all_cycles    - number of cycles that have passed since the beginning of the game.
**  recent_live   - number of live operations made by start of the last cycles_to_die.
**  cycles_to_die - duration before the next check.
**  checks        - current number of checks performed.
**
*/
typedef struct		s_arena
{
	unsigned char 	memory[MEM_SIZE]; // TODO: что насчёт того, чтобы назвать его map?
	int 			last_live;
	int 			all_cycles;
	int 			recent_live;
	int 			cycles_to_die;
	int 			checks;
	int 			next_cursor_num;
}					t_arena;

/*
** _______________________________ Structure Definition _______________________________
**
**	num	                 - unique cursor number.
**  carry                - a flag that some operations may change.
**  current_code         - code of the operation in which the cursor are.
**  last_live_cycle      - last cycle in which the last operation "live" was completed.
**  cycles_remaining     - number of cycles needed to do the remaining operation.
**  current_position     - current cursor position.
**  next_operation_steps - amount of bytes needed to skip to be on the next operation.
**  reg                  - registers.
**
*/
typedef struct		s_cursor
{
	int 			num;
	int 			carry;
	unsigned char	*current_code;
	int 			last_live_cycle;
	int 			cycles_remaining;
	int 			current_position;
	int 			next_operation_steps;
	int 			reg[REG_NUMBER];
	struct s_cursor *next;
}					t_cursor;

t_arena				*init_arena();
void				fill_champions_code(t_arena *arena, t_gstate *dunno, t_champ *champs);
void				print_arena(t_arena *arena);
void				free_all(t_arena *arena);
void				fill_cursors(t_arena *arena, t_gstate *gstate);

#endif
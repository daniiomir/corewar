/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:56:31 by swarner           #+#    #+#             */
/*   Updated: 2019/12/09 18:24:59 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_champ
{
	int f_n_arg; /* переменная, которая указывает, был ли флаг -n или нет */
	int id; /* уникальный идентификационный номер */
	char *name;
	char *comment;
	int	size; /* размер исполняемого кода */
	unsigned char *code; /* исполныемый код */
}					t_champ;

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
	t_champ	*all_players[MAX_PLAYERS];
	char    f_dump:2;
	int     f_dump_arg;
	char    f_v:2;
}					t_gstate;

/*
** _______________________________ Structure Definition _______________________________
**
**	memory	      - arena of memory, array of bytes.
**  last_live     - last player to say that he is alive.
**  all_cycles    - number of cycles that have passed since the beginning of the game.
**  recent_live   - number of live operations made by start of the last cycles_to_die.
**  cycles_to_die - duration before the next check.
**  checks        - current number of checks performed.
*/

typedef struct		s_arena
{
	unsigned char 	memory[MEM_SIZE];
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
*/

typedef struct		s_cursor
{
	int 			num;
	int 			carry;
	unsigned char	current_code;
	int 			last_live_cycle;
	int 			cycles_remaining;
	int 			current_position;
	int 			next_operation_steps;
	int 			reg[REG_NUMBER];
	struct s_cursor *next;
	struct s_cursor	*prev;
}					t_cursor;

typedef struct	s_op
{
	char *op_name;
	int nbrarg;
	char arg[3];
	int op_code;
}				t_op;

# include "arguments_parsing.h"
# include "file_parsing.h"
# include "arena.h"

#endif

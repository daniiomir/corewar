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

#define T_REG_SIZE 1
#define T_IND_SIZE 2

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
**	memory	        - arena of memory, array of bytes.
**  last_live       - last player to say that he is alive.
**  all_cycles      - number of cycles that have passed since the beginning of the game.
**  recent_live     - number of live operations made by start of the last cycles_to_die.
**  cycles_to_die   - duration before the next check.
**  checks          - current number of checks performed.
**	next_cursor_num - number that will be given to the next created cursor
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
**	dont_move            - flag that says that cursor don't need to move
*/

typedef struct		s_cursor
{
	int 			id;
	int 			carry;
	unsigned char	current_code;
	int 			last_live_cycle;
	int 			cycles_remaining;
	int 			current_position;
	int 			next_operation_steps;
	int 			reg[REG_NUMBER];
	int 			dont_move;
	struct s_cursor *next;
	struct s_cursor	*prev;
}					t_cursor;

/*
** _______________________________ Structure Definition _______________________________
**
**	op	                 - unique cursor number.
**  carry                - a flag that some operations may change.
**  current_code         - code of the operation in which the cursor are.
**  last_live_cycle      - last cycle in which the last operation "live" was completed.
**  cycles_remaining     - number of cycles needed to do the remaining operation.
**  current_position     - current cursor position.
**  next_operation_steps - amount of bytes needed to skip to be on the next operation.
**  reg                  - registers.
*/

typedef struct	s_op
{
	int				op_code;
	char			*op_name;
	int				nbrarg;
	unsigned char	arg[3]; // TODO: unsigned char
	int				need_cycles;
	char			*description;
	int				argument_code_type;
	int				change_carry;
	int 			t_dir_size;
}				t_op;

t_op			op_tab[17];

# include "arguments_parsing.h"
# include "file_parsing.h"
# include "main_alg.h"

#endif

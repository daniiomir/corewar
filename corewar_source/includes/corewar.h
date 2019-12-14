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
# include "macroses.h"
# include "op.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

#define T_REG_SIZE 1
#define T_IND_SIZE 2

/*
** _____________________ Champion Structure Definition _____________________
**
**	id			- unique identifier.
**  name      	- champion name.
**  comment		- champion comment.
**  size        - size of executable code in bytes.
**  code        - executable code.
*/

typedef struct		s_champ
{
	int				id;
	int 			f_n_arg;
	char			*name;
	char			*comment;
	int				size;
	unsigned char	*code;
}					t_champ;

/*
** _____________________ Global State Structure Definition _____________________
**
**  f_*         - flag
**
**	players_num	- number of players.
**	all_players	- array of all players in game.
**  f_dump      - flag dump (stops execution on a specific loop).
**  f_dump_arg  - dump flag argument.
**  f_v         - flag v (visualisation).
*/

typedef struct	s_gstate
{
	int			players_num;
	t_champ		*all_players[MAX_PLAYERS];
	char		f_dump:2;
	int			f_dump_arg;
	char		f_v:2;
}				t_gstate;

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

/*
** ___________________________ General Functions _______________________________
*/

void			print_error_and_exit(char *errstr, int errno);
void			print_usage();
unsigned int	byte_shift(unsigned char *buff, int byte, int sign);

/*
** ________________________ Structure Initialization ___________________________
*/

t_gstate		*init_global_state(void);
t_champ         *init_champion(int n_arg, int id);
t_arena			*init_arena();

/*
** ____________________________ Arguments Parsing _______________________________
*/

void			parse_arguments(t_gstate *gstate, int argc, char **argv);
void			parse_flag_dump(t_gstate *gstate, int *argc, char ***argv);
void			parse_flag_v(t_gstate *gstate, int *argc, char ***argv);
int				parse_flag_n(int *argc, char ***argv);

/*
** _________________________ Champion File Parsing _____________________________
*/

t_champ         *parse_champion_file(int n_arg, int id, char *filename);
unsigned char   *get_exec_code(int fd, int len);
int             get_exec_code_size(int fd);
char			*get_name_and_comment(int fd, int len);
unsigned int    miss_nulls(int fd);
void            check_header(int fd);

/*
** _________________________ Players Order _____________________________
*/

void	        order_of_champs(t_gstate *gstate);

/*
** _________________________ Arena initiation __________________________________
*/

void			fill_champions_code(t_arena *arena, t_gstate *gstate);
t_cursor		*fill_cursors(t_gstate *gstate);

/*
** _________________________ Main algorythm __________________________________
*/

void			main_alg(t_gstate *gstate);
void			cursor_operations_exec(t_cursor **cursor, t_arena *arena);

/*
** _________________________ Graphic ______________________________
*/

void			print_arena(t_arena *arena, t_cursor *cursor);

/*
** _________________________ Memory erase ______________________________
*/

void			free_all(t_arena *arena, t_cursor *cursor, t_gstate *gstate);

/*
** _________________________ Cursor operations ______________________________
*/

void 			dead_cursor(t_cursor **cursor, t_cursor **start);
int 			next_operation_steps_calculation(t_cursor *next, unsigned char arg_type);
void			do_operations(t_cursor *wst, t_arena *arena);
void			exactly_do(int num);

/*
** ______________________________ Error Number _________________________________
**
**	0  - no error.
**	3  - memory does not allocated.
**
**	Arguments validation
**	40 - champion filename is invalid.
**	41 - invalid argument with flag 'n'.
**	42 - after the -n flag should be the name of the champion file.
**	43 - champion id cannot be less than 1.
**	44 - invalid dump flag.
**	45 - dump flag argument cannot be negative number.
**	46 - players amount less than 1 or more than MAX_PLAYERS.
**
**	Champion file validation
**	50 - cannot open file.
**	51 - cannot read file.
**	52 - wrong magic header.
**	53 - wrong null symbol.
**	54 - name or comment is invalid
**	55 - wrong size of execution code.
**	56 - execution code is too big
**	57 - wrong size of execution code
**
**  6  - error in get_next_line.
**  7  - exit from -v flag.
*/

#endif

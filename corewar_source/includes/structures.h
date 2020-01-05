#ifndef COREWAR_SOURCE_STRUCTURES_H
# define COREWAR_SOURCE_STRUCTURES_H

# include "op.h"

/*
** _________________________________ LEGEND ____________________________________
**
**  f_*         - flag
*/

/*
** _____________________ Champion Structure Definition _________________________
**
**	id			- unique identifier.
**	f_n_arg		- if the flag n exists, shows the value of its argument.
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
** ___________________ Global State Structure Definition _______________________
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
** ______________________ Arena Structure Definition ___________________________
**
**	map	        - arena of map, array of bytes.
**  last_live       - last player to say that he is alive.
**  all_cycles      - number of cycles that have passed since the beginning of the game.
**  lives_nbr     	- number of live operations made by start of the last cycles_to_die.
**  cycles_to_die   - duration before the next check.
**  checks          - current number of checks performed.
**	next_cursor_num - number that will be given to the next created cursor
*/

typedef struct		s_arena
{
    unsigned char 	map[MEM_SIZE];
    int 			last_live;
    int 			all_cycles;
    int 			lives_nbr;
    int 			cycles_to_die;
    int 			checks;
    int 			next_cursor_num;
}					t_arena;

/*
** ______________________ Cursor Structure Definition __________________________
**
**	num	                 - unique cursor number.
**  carry                - a flag that some operations may change.
**  current_op         - code of the operation in which the cursor are.
**  last_live_cycle      - last cycle in which the last operation "live" was completed.
**  cycles_remaining     - number of cycles needed to do the remaining operation.
**  current_position     - current cursor position.
**  next_op_steps - amount of bytes needed to skip to be on the next operation.
**  reg                  - registers.
*/

typedef struct		s_cursor
{
    int 			id;
    int 			carry;
    unsigned char	current_op;
    int 			last_live_cycle;
    int 			cycles_remaining;
    int 			current_position;
    int 			next_op_steps;
    int 			reg[REG_NUMBER];
    unsigned char	args[3];
    struct s_cursor *next;
}					t_cursor;

/*
** _____________________ Operation Structure Definition ________________________
**
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
    void			(*func)(t_arena *, t_cursor *);
}				t_op;

#endif

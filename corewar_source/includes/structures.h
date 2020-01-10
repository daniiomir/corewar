#ifndef COREWAR_SOURCE_STRUCTURES_H
# define COREWAR_SOURCE_STRUCTURES_H

/*
** ________________________________ LEGEND _____________________________________
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
    int 			last_live_cycle;
    int 			lives_in_cur_period;
}					t_champ;

/*
** ______________________ Cursor Structure Definition __________________________
**
**	player_id					- unique identifier.
**  f_carry				- flag that some operations may change.
**  current_op			- operation code on which the cursor stands
**  last_live_cycle		- the loop on which the "live" operation was performed.
**  cycles_remaining	- number of cycles before operation execution.
**  cur_pos				- cursor position on map.
**  next_op_steps		- number of bytes before next operation.
**  reg					- registers.
**  args				- types of arguments operation takes.
**  next				- pointer to next cursor.
*/

typedef struct		s_cursor
{
	int 			player_id;
	int 			f_carry;
	unsigned char	current_op;
	int 			last_live_cycle;
	int 			cycles_remaining;
	int 			cur_pos;
	int 			next_op_steps;
	int 			reg[REG_NUMBER];
	unsigned char	args[3];
	struct s_cursor *next;
}					t_cursor;

/*
** ______________________ Arena Structure Definition ___________________________
**
**	map				- arena.
**  last_live       - the last player who said he was alive.
**  all_cycles      - number of cycles that have passed since beginning of game.
**  lives_nbr     	- number of live ops made by start of last cycle_to_die.
**  cycle_to_die	- cycle on which the check will occur.
**  checks          - number of checks performed.
**	next_cursor_num - number that will be given to the next created cursor
*/

typedef struct		s_arena
{
	unsigned char 	map[MEM_SIZE];
	int 			last_live;
	int 			all_cycles;
	int 			lives_nbr;
	int 			cycle_to_die;
//	int 			cycles_to_check;		// todo: поменять название на более понятное. Переменная уменьшается до того момента, когда нужно произвести check
	int 			checks;
	int 			next_cursor_num;
}					t_arena;

/*
** ___________________ Global State Structure Definition _______________________
**
**	players_num		- number of players.
**	all_players		- array of all players in game.
**  f_dump			- flag dump (stops execution on a specific loop).
**  f_dump_arg		- dump flag argument.
**  f_v				- flag v (visualisation).
**  f_a				- flag a (aff). Displays register value.
**	processes_num	- number of active cursors.
**  first_cursor	- pointer to the first cursor.
*/

typedef struct	s_gstate
{
    int				players_num;
    t_champ			*all_players[MAX_PLAYERS];
    char			f_dump:2;
    int				f_dump_arg;
    char			f_v:2;
    char			f_a:2;
    int 			processes_num;
	t_cursor		*first_cursor;
	struct s_vis	*vis;
	t_arena			*arena;
}				t_gstate;

/*
** _____________________ Operation Structure Definition ________________________
**
**	op_code			- operation code.
**	op_name			- operation name.
**	description		- operation description.
**	nbrarg			- number of arguments the operation accepts.
**	arg_types		- types of arguments the operation accepts.
**	need_cycles		- number of cycles to be executed.
**	arg_code_type	- arguments code type.
**	f_change_carry	- does the operation change the "carry" flag.
**	t_dir_size		- size of t_dir argument.
**	func			- function that performs the operation.
*/

typedef struct	s_op
{
	int				op_code;
	char			*op_name;
	int				nbrarg;
	unsigned char	arg_types[3];
	int				need_cycles;
	char			*description;
	int				arg_code_type;
	int				f_change_carry;
	int 			t_dir_size;
	void			(*func)(t_gstate *, t_cursor *);
}				t_op;

#endif

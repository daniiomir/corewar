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

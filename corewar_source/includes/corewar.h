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

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "op.h"
# include "structures.h"
# include "macroses.h"

t_op			op_tab[17];

/*
** ___________________________ General Functions _______________________________
*/

void			print_error_and_exit(char *errstr, int errno);
void			print_usage();
int				byte_to_int(unsigned char *code, int byte_len);
int				get_map_ind(int current_position, int shift);

/*
** ________________________ Structure Initialization ___________________________
*/

t_gstate		*init_global_state(void);
t_champ         *init_champion(int n_arg, int id);
t_arena			*init_arena();
t_cursor		*init_cursor(int id, int reg);

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

t_cursor		*fill_arena_and_init_cursors(t_arena *arena, t_gstate *gstate);

/*
** _________________________ Main algorythm __________________________________
*/

void			main_alg(t_gstate *gstate);
void			cursor_operations_exec(t_arena *arena, t_cursor **cursors);

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

void 			kill_cursor(t_cursor **search_cursor, t_cursor **first_cursor);
void 			do_operation(t_cursor *wst, t_arena *arena);

/*
** ______________________________ Operations ___________________________________
*/
int get_arg(t_arena *arena, t_cursor *cursor, unsigned char arg, int mod);
void			op_ld(t_arena *arena, t_cursor *cursor);

/*
** ______________________________ Error Number _________________________________
**
**	0  - no error.
**	3  - map does not allocated.
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

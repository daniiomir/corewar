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
# include "file_parsing.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

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


void        print_usage();
void        print_error_and_exit(char *errstr, int errno);
t_gstate    *init_global_state();
void        parse_arguments(t_gstate *gstate, int argc, char **argv);
void        parse_flag_dump(t_gstate *gstate, int *argc, char ***argv);
void        parse_flag_v(t_gstate *gstate, int *argc, char ***argv);
int			parse_flag_n(int *argc, char ***argv);
int         is_champion_filename(char *filename);
void        parse_champion_file(t_gstate *gstate, int *argc, char ***argv);

#endif

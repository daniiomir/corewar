/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:56:31 by swarner           #+#    #+#             */
/*   Updated: 2019/11/13 15:56:33 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
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
    char    f_dump:1;
    char    f_dump_arg;
    char    f_v:1;
}					t_gstate;


void        print_usage();
void        print_error_and_exit(char *errstr, int errno);
t_gstate    *init_global_state();
void        parse_arguments(t_gstate *gstate, int argc, char **argv);
void        parse_flag_dump(t_gstate *gstate, int *argc, char ***argv);
void        parse_flag_v(t_gstate *gstate, int *argc, char ***argv);
int         is_champion_filename(char *filename);

#endif

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

# include "arguments_parsing.h"
# include "file_parsing.h"

/*
** ______________________________ Error Number _________________________________
**
**	0  - no error.
**	3  - memory does not allocated.
**
**	Arguments validation
**	40 - champion filename is invalid.
**	41 - invalid argument with flag 'n'.
**	42 - champion id cannot be less than 1.
**	43 - invalid dump flag.
**	44 - dump flag argument cannot be negative number.
**	45 - players amount less than 1 or more than MAX_PLAYERS.
**
**	Champion file validation
**	50 - cannot open file.
**	51 - cannot read file.
**	52 - wrong magic header.
**	53 - wrong null symbol.
**	54 - name is invalid.
**	55 - comment is invalid.
**	56 - wrong size of execution code.
**	57 - execution code is too big
**	58 - wrong size of execution code
**
**  6  - error in get_next_line.
**  7  - exit from -v flag.
*/


#endif

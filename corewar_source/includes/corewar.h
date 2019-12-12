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

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define CONCAT_STR_WITH_NBR(str, nbr) str STR(nbr)
#define CONCAT_STR_WITH_STR(str1, str2) str1 str2

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

# include "arguments_parsing.h"
# include "file_parsing.h"

#endif

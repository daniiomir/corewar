/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:56:47 by swarner           #+#    #+#             */
/*   Updated: 2019/11/13 15:56:49 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include "libft.h"
# include "op.h"

typedef struct	s_code
{
	char			*operation;
	char			*arg1;
	int				arg1_type;
	char			*arg2;
	int				arg2_type;
	char			*arg3;
	int				arg3_type;
	char			*label_name;
	int				size;
	int				line;
	struct s_code 	*next;
	struct s_code 	*prev;
}				t_code;

typedef struct	s_pseudo_asm
{
	char			*champion_name;
	char			*comment;
	struct s_code	*code;
	char			*final_code;
}				t_pasm;

int				open_file(char *file);
void			parse_file(int fd, t_pasm *pasm);
void			line_parse(t_pasm *pasm, char *line, int line_number, char **label);

t_pasm			*init_pasm(void);
t_code			*create_code_line(void);
void			add_code_line(t_pasm *pasm, t_code *code_line);


void			free_pasm(t_pasm *pasm);
void			free_code_lines(t_code *code_lines);

int 			position_of_comm(char *line, char comm, char alt_comm);
char			*check_comm(char *line);
char 			*label_check(t_pasm *pasm, char *line, int line_number);
int				check_for_arg_type(char *arg);
int				check_for_op_name(char *op);

int				get_champion_name_and_comment(t_pasm *pasm,
					char *line, int line_number);
void			args_to_code_line(t_pasm *pasm, t_code *code_line,
					char *line, int i);
int				op_to_code_line(t_pasm *pasm, t_code *code_line, char *line);
void			label_to_code_line(t_code *code_line, char **label);
void			arg_one(t_pasm *pasm, t_code *code_line, char *arg1);
void			arg_two(t_pasm *pasm, t_code *code_line, char *arg2);
void			arg_three(t_pasm *pasm, t_code *code_line, char *arg3);

void			simple_error(char *error_text);
void			error_exit(t_pasm *pasm, char *error_text);
void			error_exit_line(t_pasm *pasm, char *error_text, int line_number);

int 			ft_strchr_i(const char *s, int c);

#endif

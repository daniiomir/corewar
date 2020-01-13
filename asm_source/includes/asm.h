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

typedef struct	s_op
{
	char			*op_name;
	int				nbrarg;
	char			arg[3];
	int				op_code;
}				t_op;

typedef struct	s_hex_code
{
	char	*magic_header;
	char	*champion_name;
	char	*null_octet;
	char	*exec_size;
	char	*champion_comment;
	char	*null_octet2;
}				t_hcode;

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
	char			*hex;
	struct s_code	*next;
	struct s_code	*prev;
}				t_code;

typedef struct	s_pseudo_asm
{
	char				*champion_name;
	char				*comment;
	struct s_code		*code;
	struct s_hex_code	*hex_code;
	char				*final_code;
}				t_pasm;

t_op			g_op_tab[17];

int				open_file(char *file);
void			parse_file(int fd, t_pasm *pasm);
void			parse_file_helper(char **line, int *line_number,
	char **check_line);
void			line_parse(t_pasm *pasm, char *line,
	int line_number, char **label);

t_pasm			*init_pasm(void);
t_code			*create_code_line(void);
t_hcode			*create_hex_struct(void);
void			add_code_line(t_pasm *pasm, t_code *code_line);

void			free_pasm(t_pasm *pasm);
void			free_hex_struct(t_hcode *hex_code);
void			free_code_lines(t_code *code_lines);

int				position_of_comm(char *line, char comm, char alt_comm);
char			*check_comm(char *line);
int				check_legal_chars(const char *check, const char *legal_chars);
int				check_for_cmd_string(char *line);
int				validate_cmd_string(char *cmd_string);
int				label_operations(t_pasm *pasm, char **label,
	char **line, int *line_number);
char			*label_check(t_pasm *pasm, char *line, int line_number);
int				check_is_label(char *arg);
int				check_for_arg_type(char *arg);
int				check_for_op_name(char *op);
int				check_dir_size(t_code *code_line);
int				check_for_code_arg_type(t_code *code_line);
void			args_count_check(t_pasm *pasm, t_code *code_line);

void			init_switch_label(t_code *ptr, char **label,
	int *offset, int arg);
int				switch_label(t_pasm *pasm, t_code *ptr, int arg);
int				switch_label_go_back(t_code *ptr, char *label);
void			switch_labels_to_adress(t_pasm *pasm, t_code *code);
void			switch_labels_to_adress_helper(t_pasm *pasm,
	t_code *ptr, int nb_arg);

int				get_champion_name_and_comment(t_pasm *pasm,
					char *line, int line_number);
int				get_champion_name_and_comment_helper(char *line);
void			args_to_code_line(t_pasm *pasm, t_code *code_line,
					char *line, int i);
char			*args_to_code_line_helper(char *args, int *start);
int				op_to_code_line(t_pasm *pasm, t_code *code_line, char *line);
void			label_to_code_line(t_code *code_line, char **label);
void			size_to_code_line(t_code *code_line);
void			arg_one(t_pasm *pasm, t_code *code_line, char *arg1);
void			arg_two(t_pasm *pasm, t_code *code_line, char *arg2);
void			arg_three(t_pasm *pasm, t_code *code_line, char *arg3);

char			*new_filename(char *name);
void			write_hex_to_file(t_pasm *pasm, char *file_name);
void			write_hex_to_pasm(t_pasm *pasm);
void			write_in_hex(int fd, char *hex_string);
void			write_all_to_file(int fd, t_pasm *pasm);
unsigned char	hex_part(char chr);
void			hex_part2(char chr, unsigned char *bytecode);

char			*get_nulls(int len);
void			get_null_octets(t_pasm *pasm);
void			get_magic_header(t_pasm *pasm);
void			get_hex_champ_name(t_pasm *pasm);
void			get_hex_champ_comment(t_pasm *pasm);
void			add_nulls_to_comment(char **hex_champ_comm, int len);
void			get_exec_size(t_pasm *pasm);

void			code_to_hex(t_pasm *pasm);
char			*code_get_hex_op(char *op_code);
char			*code_get_hex_addcode(t_code *code_line);
void			code_get_hex_addcode2(t_code *code_line,
	unsigned char *addcode);
char			*code_get_hex_arg(t_pasm *pasm, t_code *code_line,
	char *argument, int arg_type);
char			*code_get_hex_arg_positive(t_pasm *pasm, t_code *code_line,
	char *arg, int arg_type);
char			*code_get_hex_arg_negative(t_code *code_line,
	char *argument, int arg_type);

void			simple_error(char *error_text);
void			error_exit(t_pasm *pasm, char *error_text);
void			error_exit_line(t_pasm *pasm, t_code *code_line,
	char *error_text, int line_number);

int				is_blanc(char check);
int				ft_strchr_i(const char *s, int c);
unsigned char	setbit(const unsigned char value, const int position);
int				len_of_cmd_names(t_pasm *pasm, char *line, int value);
char			*get_new_line_after_label(char **line);
int				check_for_op_after_label(char *line, int label_char_pos);
void			check_for_error_and_comm(int ret, char **line);

#endif

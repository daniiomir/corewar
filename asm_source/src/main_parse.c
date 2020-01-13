/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:29:30 by swarner           #+#    #+#             */
/*   Updated: 2019/12/04 17:29:33 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			label_to_code_line(t_code *code_line, char **label)
{
	char	*for_struct;

	if (*label)
	{
		for_struct = ft_strdup(*label);
		code_line->label_name = for_struct;
		free(*label);
		*label = NULL;
	}
}

int				op_to_code_line(t_pasm *pasm, t_code *code_line, char *line)
{
	int		i;
	char	*op;

	i = 0;
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		i++;
	op = ft_strsub(line, 0, i);
	if (!check_for_op_name(op))
		error_exit_line(pasm, code_line,
			"wrong operation name.", code_line->line);
	code_line->operation = op;
	return (i);
}

static void		name_and_comment_to_pasm(t_pasm *pasm, char *line,
	int i, int value)
{
	int		len;
	char	*text;

	text = ft_strsub(line, i + 1, len_of_cmd_names(pasm, line, value));
	len = (int)ft_strlen(text);
	if (value == 1)
	{
		if (len > PROG_NAME_LENGTH)
			error_exit_line(pasm, NULL,
				"length of champion name bigger than 128 symbols.", 1);
		pasm->champion_name = text;
	}
	else if (value == 2)
	{
		if (len > COMMENT_LENGTH)
			error_exit_line(pasm, NULL,
				"length of comment bigger than 2048 symbols.", 2);
		pasm->comment = text;
	}
}

int				get_champion_name_and_comment(t_pasm *pasm,
	char *line, int line_number)
{
	int		i;
	char	*raw_cmd_string;
	char	*cmd_string;

	if (check_for_cmd_string(line))
	{
		i = get_champion_name_and_comment_helper(line);
		raw_cmd_string = ft_strsub(line, 0, i);
		cmd_string = ft_strtrim(raw_cmd_string);
		free(raw_cmd_string);
		if (validate_cmd_string(cmd_string) == 1)
			name_and_comment_to_pasm(pasm, line, i, 1);
		else if (validate_cmd_string(cmd_string) == 2)
			name_and_comment_to_pasm(pasm, line, i, 2);
		else
		{
			free(cmd_string);
			error_exit_line(pasm, NULL,
				"wrong cmd command (.name/.comment).", line_number);
		}
		free(cmd_string);
		return (1);
	}
	return (0);
}

void			size_to_code_line(t_code *code_line)
{
	int		size;

	size = 0;
	if (code_line->operation)
		size += 1;
	size += check_for_code_arg_type(code_line);
	if (code_line->arg1_type == IND_CODE)
		size += 2;
	else if (code_line->arg1_type == REG_CODE)
		size += 1;
	else if (code_line->arg1_type == DIR_CODE)
		size += check_dir_size(code_line);
	if (code_line->arg2_type == IND_CODE)
		size += 2;
	else if (code_line->arg2_type == REG_CODE)
		size += 1;
	else if (code_line->arg2_type == DIR_CODE)
		size += check_dir_size(code_line);
	if (code_line->arg3_type == IND_CODE)
		size += 2;
	else if (code_line->arg3_type == REG_CODE)
		size += 1;
	else if (code_line->arg3_type == DIR_CODE)
		size += check_dir_size(code_line);
	code_line->size = size;
}

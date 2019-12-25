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

void	label_to_code_line(t_code *code_line, char **label)
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

int		op_to_code_line(t_pasm *pasm, t_code *code_line, char *line)
{
	int		i;
	char	*op;

	i = 0;
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		i++;
	op = ft_strsub(line, 0, i);
	if (!check_for_op_name(op))
		error_exit_line(pasm, code_line,"wrong operation name.", code_line->line);
	code_line->operation = op;
	return (i);
}

static void	name_and_comment_to_pasm(t_pasm *pasm, char *line,
	int i, int value)
{
	int		len;
	char 	*text;

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

void		arg_one(t_pasm *pasm, t_code *code_line, char *arg1)
{
	int		arg_type;
	char 	*buffer;
	char 	*first_arg;

	buffer = ft_strtrim(arg1);
	arg_type = check_for_arg_type(buffer);
	if (!arg_type)
		error_exit_line(pasm,code_line, "wrong first argument.",
			code_line->line);
	if (arg_type == DIR_CODE && buffer[1] == LABEL_CHAR)
		first_arg = ft_strsub(buffer, 2, ft_strlen(buffer));	
	else if (arg_type == REG_CODE || arg_type == DIR_CODE || buffer[0] == LABEL_CHAR)
		first_arg = ft_strsub(buffer, 1, ft_strlen(buffer));
	else
		first_arg = ft_strdup(buffer);
	code_line->arg1 = first_arg;
	code_line->arg1_type = arg_type;
	free(buffer);
}

void		arg_two(t_pasm *pasm, t_code *code_line, char *arg2)
{
	int		arg_type;
	char 	*buffer;
	char 	*second_arg;

	buffer = ft_strtrim(arg2);
	arg_type = check_for_arg_type(buffer);
	if (!arg_type)
		error_exit_line(pasm, code_line, "wrong second argument.",
			code_line->line);
	if (arg_type == DIR_CODE && buffer[1] == LABEL_CHAR)
		second_arg = ft_strsub(buffer, 2, ft_strlen(buffer));	
	else if (arg_type == REG_CODE || arg_type == DIR_CODE || buffer[0] == LABEL_CHAR)
		second_arg = ft_strsub(buffer, 1, ft_strlen(buffer));
	else
		second_arg = ft_strdup(buffer);
	code_line->arg2 = second_arg;
	code_line->arg2_type = arg_type;
	free(buffer);
}

void		arg_three(t_pasm *pasm, t_code *code_line, char *arg3)
{
	int		arg_type;
	char 	*buffer;
	char 	*third_arg;

	buffer = ft_strtrim(arg3);
	arg_type = check_for_arg_type(buffer);
	if (!arg_type)
		error_exit_line(pasm, code_line, "wrong third argument.",
			code_line->line);
	if (arg_type == DIR_CODE && buffer[1] == LABEL_CHAR)
		third_arg = ft_strsub(buffer, 2, ft_strlen(buffer));	
	else if (arg_type == REG_CODE || arg_type == DIR_CODE || buffer[0] == LABEL_CHAR)
		third_arg = ft_strsub(buffer, 1, ft_strlen(buffer));
	else
		third_arg = ft_strdup(buffer);
	code_line->arg3 = third_arg;
	code_line->arg3_type = arg_type;
	free(buffer);
}

char		*args_to_code_line_helper(char *args, int *start)
{
	int 	i;
	int 	j;
	char 	*tmp;

	i = *start;
	j = *start;
	while (args[i] == ' ')
	    i++;
	while (args[i] != '\0' && args[i] != ' ' && args[i] != SEPARATOR_CHAR)
		i++;
	tmp = ft_strsub(args, j, i - j);
	*start += i - *start + 1;
	return (tmp);
}

void		args_to_code_line(t_pasm *pasm, t_code *code_line,
	char *line, int i)
{
	int 	j;
	char 	*tmp;
	char 	*args;

	j = 0;
	tmp = ft_strsub(line, i, ft_strlen(line));
	args = ft_strtrim(tmp);
	free(tmp);
	tmp = args_to_code_line_helper(args, &j);
	arg_one(pasm, code_line, tmp);
	free(tmp);
	if (args[j - 1] != '\0')
	{
		tmp = args_to_code_line_helper(args, &j);
		arg_two(pasm, code_line, tmp);
		free(tmp);
		if (args[j - 1] != '\0')
		{
			tmp = args_to_code_line_helper(args, &j);
			arg_three(pasm, code_line, tmp);
			free(tmp);
		}
	}
	free(args);
}

static int	validate_cmd_string(char *cmd_string)
{
	if (ft_strequ(cmd_string, NAME_CMD_STRING))
		return (1);
	if (ft_strequ(cmd_string, COMMENT_CMD_STRING))
		return (2);
	return (0);
}

int		get_champion_name_and_comment(t_pasm *pasm,
	char *line, int line_number)
{
	int		i;
	char 	*raw_cmd_string;
	char 	*cmd_string;

	if (line_number == 1 || line_number == 2)
	{
		i = 0;
		while (line[i] != '"' && line[i] != '\0')
			i++;
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
			error_exit_line(pasm, NULL, "wrong cmd command (.name/.comment).", line_number);
		}
		free(cmd_string);
		return (1);
	}
	return (0);
}

void	size_to_code_line(t_code *code_line)
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

void	args_count_check(t_pasm *pasm, t_code *code_line)
{
	int		i;
	int		count;
	int		line;

	i = 0;
	count = 0;
	line = code_line->line; 
	if (code_line->arg1)
		count++;
	if (code_line->arg2)
		count++;
	if (code_line->arg3)
		count++;
	while (op_tab[i].op_name)
	{
		if (ft_strequ(code_line->operation, op_tab[i].op_name))
		{
			if (op_tab[i].nbrarg != count)
				error_exit_line(pasm, code_line, "wrong arguments.", line);
			return ;
		}
		i++;
	}
}

void	line_parse(t_pasm *pasm, char *line,
	int line_number, char **label)
{
	int		i;
	char 	*normalised_line;
	t_code	*code_line;

	if (get_champion_name_and_comment(pasm, line, line_number))
		return ;
	code_line = create_code_line();
	normalised_line = ft_strtrim(line);
	code_line->line = line_number;
	i = op_to_code_line(pasm, code_line, normalised_line);
	args_to_code_line(pasm, code_line, normalised_line, i);
	label_to_code_line(code_line, label);
	args_count_check(pasm, code_line);
	size_to_code_line(code_line);
	add_code_line(pasm, code_line);
	free(normalised_line);
}

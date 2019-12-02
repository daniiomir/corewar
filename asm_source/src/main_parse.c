#include "asm.h"

void	label_to_code_line(t_code *code_line, char **label)
{
	char	*for_struct;

	if (*label)
	{
		for_struct = ft_strdup(*label);
		code_line->label_name = for_struct;
		free(label);
		*label = NULL;
	}
}

int		check_for_op_name(char *op)
{
	int		i;

	i = 0;
	while (op_tab[i].op_name)
	{
		if (ft_strequ(op, op_tab[i].op_name))
			return (1);
		i++;
	}
	return (0);
}

int		op_to_code_line(t_pasm *pasm, t_code *code_line, char *line)
{
	int		i;
	char	*op;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	op = ft_strsub(line, 0, i);
	if (!check_for_op_name(op))
		error_exit_line(pasm, "wrong operation name.", code_line->line);
	code_line->operation = op;
	return (i);
}

void	add_code_line(t_pasm *pasm, t_code *code_line)
{
	t_code	*prev;
	t_code	*code_ptr;

	if (!pasm->code)
		pasm->code = code_line;
	else
	{
		code_ptr = pasm->code;
		while (code_ptr->next)
		{
			prev = code_ptr;
			code_ptr = code_ptr->next;
		}
		code_ptr = code_line;
		prev->next = code_line;
		code_ptr->prev = prev;
	}
}

static void	name_and_comment_to_pasm(t_pasm *pasm, char *line,
	int i, int value)
{
	int		len;
	char 	*text;

	text = ft_strsub(line, i, ft_strlen(line) - 1);
	len = (int)ft_strlen(text);
	if (value == 1)
	{
		if (len > PROG_NAME_LENGTH)
			error_exit_line(pasm,
				"length of champion name bigger than 128 symbols.", 1);
		pasm->champion_name = text;
	}
	else if (value == 2)
		if (len > COMMENT_LENGTH)
			error_exit_line(pasm,
				"length of comment bigger than 2048 symbols.", 2);
		pasm->comment = text;
}

int			check_for_arg_type(char *arg)
{
	if (arg[0] == 'r')
		return (REG_CODE);
	else if (arg[0] == DIRECT_CHAR)
		return (DIR_CODE);
	else if (ft_isdigit(arg[0])
		|| (arg[0] == LABEL_CHAR && ft_isalpha(arg[1]))
		|| (arg[0] == '-' && ft_isdigit(arg[1])))
		return (IND_CODE);
	return (0);
}

void		arg_one(t_pasm *pasm, t_code *code_line, char *arg1)
{
	int		arg_type;
	char 	*buffer;
	char 	*first_arg;

	buffer = ft_strtrim(arg1);
	arg_type = check_for_arg_type(buffer);
	if (!arg_type)
		error_exit_line(pasm, "wrong first argument.",
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
		error_exit_line(pasm, "wrong second argument.",
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
		error_exit_line(pasm, "wrong first argument.",
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

void		args_to_code_line(t_pasm *pasm, t_code *code_line,
	char *line, int i)
{
	char 	*args;
	char 	**splitted_args;

	args = ft_strsub(line, i, ft_strlen(line));
	splitted_args = ft_strsplit(args, SEPARATOR_CHAR);
	if (splitted_args[3])
		error_exit_line(pasm, "too much arguments.",
			code_line->line);
	if (splitted_args[0])
		arg_one(pasm, code_line, splitted_args[0]);
	if (splitted_args[1])
		arg_two(pasm, code_line, splitted_args[1]);
	if (splitted_args[2])
		arg_three(pasm, code_line, splitted_args[2]);
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
			error_exit_line(pasm, "wrong cmd command (.name/.comment).", line_number);
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
		size += 2;
	if (code_line->arg1_type == IND_CODE)
		size += 2;
	else if (code_line->arg1_type == REG_CODE
		|| code_line->arg1_type == DIR_CODE)
		size += 1;
	if (code_line->arg2_type == IND_CODE)
		size += 2;
	else if (code_line->arg2_type == REG_CODE
		|| code_line->arg2_type == DIR_CODE)
		size += 1;
	if (code_line->arg3_type == IND_CODE)
		size += 2;
	else if (code_line->arg3_type == REG_CODE
		|| code_line->arg3_type == DIR_CODE)
		size += 1;
	code_line->size = size;
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
	args_to_code_line(code_line, normalised_line, i);
	label_to_code_line(code_line, label);
	size_to_code_line(code_line);
	add_code_line(pasm, code_line);
	free(normalised_line);
}

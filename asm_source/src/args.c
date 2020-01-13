/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:58:17 by swarner           #+#    #+#             */
/*   Updated: 2020/01/13 17:58:18 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			arg_one(t_pasm *pasm, t_code *code_line, char *arg1)
{
	int		arg_type;
	char	*buffer;
	char	*first_arg;

	buffer = ft_strtrim(arg1);
	arg_type = check_for_arg_type(buffer);
	if (!arg_type)
		error_exit_line(pasm, code_line, "wrong first argument.",
			code_line->line);
	if (arg_type == DIR_CODE && buffer[1] == LABEL_CHAR)
		first_arg = ft_strsub(buffer, 2, ft_strlen(buffer));
	else if (arg_type == REG_CODE || arg_type == DIR_CODE
		|| buffer[0] == LABEL_CHAR)
		first_arg = ft_strsub(buffer, 1, ft_strlen(buffer));
	else
		first_arg = ft_strdup(buffer);
	code_line->arg1 = first_arg;
	code_line->arg1_type = arg_type;
	free(buffer);
}

void			arg_two(t_pasm *pasm, t_code *code_line, char *arg2)
{
	int		arg_type;
	char	*buffer;
	char	*second_arg;

	buffer = ft_strtrim(arg2);
	arg_type = check_for_arg_type(buffer);
	if (!arg_type)
		error_exit_line(pasm, code_line, "wrong second argument.",
			code_line->line);
	if (arg_type == DIR_CODE && buffer[1] == LABEL_CHAR)
		second_arg = ft_strsub(buffer, 2, ft_strlen(buffer));
	else if (arg_type == REG_CODE || arg_type == DIR_CODE
		|| buffer[0] == LABEL_CHAR)
		second_arg = ft_strsub(buffer, 1, ft_strlen(buffer));
	else
		second_arg = ft_strdup(buffer);
	code_line->arg2 = second_arg;
	code_line->arg2_type = arg_type;
	free(buffer);
}

void			arg_three(t_pasm *pasm, t_code *code_line, char *arg3)
{
	int		arg_type;
	char	*buffer;
	char	*third_arg;

	buffer = ft_strtrim(arg3);
	arg_type = check_for_arg_type(buffer);
	if (!arg_type)
		error_exit_line(pasm, code_line, "wrong third argument.",
			code_line->line);
	if (arg_type == DIR_CODE && buffer[1] == LABEL_CHAR)
		third_arg = ft_strsub(buffer, 2, ft_strlen(buffer));
	else if (arg_type == REG_CODE || arg_type == DIR_CODE
		|| buffer[0] == LABEL_CHAR)
		third_arg = ft_strsub(buffer, 1, ft_strlen(buffer));
	else
		third_arg = ft_strdup(buffer);
	code_line->arg3 = third_arg;
	code_line->arg3_type = arg_type;
	free(buffer);
}

void			args_to_code_line(t_pasm *pasm, t_code *code_line,
	char *line, int i)
{
	int		j;
	char	*tmp;
	char	*args;

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

void			args_count_check(t_pasm *pasm, t_code *code_line)
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
	while (g_op_tab[i].op_name)
	{
		if (ft_strequ(code_line->operation, g_op_tab[i].op_name))
		{
			if (g_op_tab[i].nbrarg != count)
				error_exit_line(pasm, code_line, "wrong arguments.", line);
			return ;
		}
		i++;
	}
}

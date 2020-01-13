/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:53:44 by swarner           #+#    #+#             */
/*   Updated: 2020/01/13 17:53:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				validate_cmd_string(char *cmd_string)
{
	if (ft_strequ(cmd_string, NAME_CMD_STRING))
		return (1);
	if (ft_strequ(cmd_string, COMMENT_CMD_STRING))
		return (2);
	return (0);
}

int				check_for_cmd_string(char *line)
{
	int		i;
	char	*cmd_str;

	if (ft_strlen(line) > 5 && line[0] != '\0'
	&& line[0] != '\n' && line[0] != '\t')
	{
		if (line[0] == '.')
		{
			i = 1;
			while (ft_isalpha(line[i]))
				i++;
			cmd_str = ft_strsub(line, 0, i);
			if (validate_cmd_string(cmd_str))
			{
				free(cmd_str);
				return (1);
			}
			free(cmd_str);
		}
	}
	return (0);
}

int				get_champion_name_and_comment_helper(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '"' && line[i] != '\0')
		i++;
	return (i);
}

char			*args_to_code_line_helper(char *args, int *start)
{
	int		i;
	int		j;
	char	*tmp;

	i = *start;
	j = *start;
	if (args[j] == SEPARATOR_CHAR)
	{
		j++;
		i++;
	}
	while (args[i] == ' ')
		i++;
	while (args[i] != '\0' && args[i] != ' ' && args[i] != SEPARATOR_CHAR)
		i++;
	tmp = ft_strsub(args, j, i - j);
	*start += i - *start + 1;
	return (tmp);
}

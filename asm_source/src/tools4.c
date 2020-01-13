/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:45:38 by swarner           #+#    #+#             */
/*   Updated: 2020/01/13 17:45:40 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*new_filename(char *prev_name)
{
	char	*name;

	name = ft_strsub(prev_name, 0, ft_strlen(prev_name) - 2);
	name = ft_strjoin_free(name, ".cor");
	return (name);
}

char	*get_new_line_after_label(char **line)
{
	int		end_label;
	char	*new_line;

	end_label = ft_strchr_i(*line, LABEL_CHAR);
	new_line = ft_strsub(*line, end_label + 1, ft_strlen(*line));
	free(*line);
	return (new_line);
}

int		len_of_cmd_names(t_pasm *pasm, char *line, int value)
{
	int		first_pos;
	int		len;

	first_pos = ft_strchr_i(line, '"') + 1;
	len = 0;
	while (line[first_pos] != '"')
	{
		len++;
		first_pos++;
		if (line[first_pos] == '\0')
			error_exit_line(pasm, NULL, "no second quote mark.", value);
	}
	return (len);
}

t_pasm	*init_pasm(void)
{
	t_pasm	*pasm;

	pasm = (t_pasm *)malloc(sizeof(t_pasm));
	pasm->champion_name = NULL;
	pasm->comment = NULL;
	pasm->code = NULL;
	pasm->hex_code = create_hex_struct();
	pasm->final_code = NULL;
	return (pasm);
}

void	free_pasm(t_pasm *pasm)
{
	if (pasm)
	{
		if (pasm->champion_name)
			free(pasm->champion_name);
		if (pasm->comment)
			free(pasm->comment);
		if (pasm->code)
			free_code_lines(pasm->code);
		if (pasm->hex_code)
			free_hex_struct(pasm->hex_code);
		if (pasm->final_code)
			free(pasm->final_code);
		free(pasm);
	}
}

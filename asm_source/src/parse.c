/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:34:46 by swarner           #+#    #+#             */
/*   Updated: 2019/12/04 17:29:50 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*label_check(t_pasm *pasm, char *line, int line_number)
{
	int		label_char_pos;
	char	*label;

	if (line_number == 1 || line_number == 2)
		return (NULL);
	if ((label_char_pos = ft_strchr_i(line, LABEL_CHAR)) == -1)
		return (NULL);
	if (!ft_isalpha(line[label_char_pos - 1])
		&& (line[0] == ' ' || line[0] == '\t'))
		return (NULL);
	label = ft_strsub(line, 0, label_char_pos);
	if (ft_strchr_i(label, '%') > 0 || ft_strchr_i(label, ' ') > 0
	|| ft_strchr_i(label, '\t') > 0)
	{
		free(label);
		return (NULL);
	}
	if (!check_legal_chars(label, LABEL_CHARS))
		error_exit_line(pasm, NULL, "not ASCII characters in label",
			line_number);
	return (label);
}

int		open_file(char *file)
{
	int		fd;
	int		len;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		simple_error("invalid file name.");
	len = ft_strlen(file);
	if (file[len - 1] != 's' && file[len - 2] != '.')
	{
		close(fd);
		simple_error("wrong extension of file (not .s file).");
	}
	return (fd);
}

int		label_operations(t_pasm *pasm, char **label,
	char **line, int *line_number)
{
	char	*new_label;
	char	*check_line;

	if (*line_number > 2 && ft_strlen(*line) && !is_blanc((*line)[0]))
	{
		new_label = label_check(pasm, *line, *line_number);
		if (!new_label || (*line)[0] == '.')
		{
			free(new_label);
			return (1);
		}
		*label = new_label;
		if (check_for_op_after_label(*line, ft_strchr_i(*line, LABEL_CHAR)))
		{
			*line = get_new_line_after_label(line);
			return (1);
		}
		else
		{
			check_line = NULL;
			parse_file_helper(line, line_number, &check_line);
			return (0);
		}
	}
	return (1);
}

void	line_parse(t_pasm *pasm, char *line,
	int line_number, char **label)
{
	int		i;
	char	*normalised_line;
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

void	parse_file(int fd, t_pasm *pasm)
{
	int		ret;
	int		line_number;
	char	*line;
	char	*label;
	char	*check_line;

	line_number = 1;
	label = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		check_for_error_and_comm(ret, &line);
		if (!label_operations(pasm, &label, &line, &line_number))
			continue ;
		check_line = ft_strtrim(line);
		if (ft_strlen(check_line) == 0)
		{
			parse_file_helper(&line, &line_number, &check_line);
			continue ;
		}
		line_parse(pasm, check_line, line_number, &label);
		parse_file_helper(&line, &line_number, &check_line);
	}
}

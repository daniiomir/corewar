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

int		check_for_op_after_label(char *line, int label_char_pos)
{
	// int		i;
	// char 	**check;

//	check = ft_strsplit(line, ' ');
//	if (check[1])
//	{
//		i = 0;
//		while (check[i])
//			free(check[i++]);
//		free(check);
//		return (1);
//	}
//	free(check[0]);
//	free(check);
	if (line[label_char_pos + 1])
		return (1);
	return (0);
}

char 	*label_check(t_pasm *pasm, char *line, int line_number)
{
	int		label_char_pos;
	char 	*label;
	
	if (line_number == 1 || line_number == 2)
		return (NULL);
	// if (!check_legal_chars(line, LABEL_CHARS))
	// 	error_exit_line(pasm, "not ASCII characters in line",
	// 		line_number);
	if ((label_char_pos = ft_strchr_i(line, LABEL_CHAR)) == -1)
		return (NULL);
	if (!ft_isalpha(line[label_char_pos - 1]) && (line[0] == ' ' || line[0] == '\t'))
		return (NULL);
	label = ft_strsub(line, 0, label_char_pos);
	if (!check_legal_chars(label, LABEL_CHARS))
		error_exit_line(pasm, NULL, "not ASCII characters in label",
			line_number);
	return (label);
}

int		open_file(char *file)
{
	int		fd;
	int 	len;

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

void	parse_file(int fd, t_pasm *pasm)
{
	int		ret;
	int 	line_number;
	char	*line;
	char 	*label;
	char 	*check_line;

	line_number = 1;
	label = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < 0)
			simple_error("corrupted file.");
		line = check_comm(line);
		if (!label && line_number > 2 && ft_strlen(line) && line[0] != '\t' && line[0] != ' ')
		{
			label = label_check(pasm, line, line_number);
			if (check_for_op_after_label(line, ft_strchr_i(line, LABEL_CHAR)))
				line = get_new_line_after_label(&line);
			else
			{
				free(line);
                line_number++;
				continue ;
			}
		}
		check_line = ft_strtrim(line);
		if (ft_strlen(check_line) == 0)
		{
			free(check_line);
			free(line);
			line_number++;
			continue ;
		}
		line_parse(pasm, line, line_number, &label);
		free(line);
		free(check_line);
		line_number++;
	}
}

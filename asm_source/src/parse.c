/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:34:46 by swarner           #+#    #+#             */
/*   Updated: 2019/11/15 16:34:47 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_legal_chars(const char *check, const char *legal_chars)
{
	int		i;
	int		j;
	int		len;
	int		count;

	i = 0;
	count = 0;
	len = (int)ft_strlen(check);
	while (check[i])
	{
		j = 0;
		while (legal_chars[j])
		{
			if (check[i] == legal_chars[j])
			{
				count++;
				break ;
			}
			j++;
		}
		i++;
	}
	if (count != len)
		return (0);
	return (1);
}

int 	ft_strchr_i(const char *s, int c)
{
	int 	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int 	position_of_comm(char *line, char comm, char alt_comm)
{
	int 	i;
	int 	j;

	i = ft_strchr_i(line, comm);
	j = ft_strchr_i(line, alt_comm);
	if (i == -1)
		return(j);
	else if (j == -1)
		return (i);
	else
	{
		if (i < j)
			return (i);
		else if (j < i)
			return (j);
	}
	return (-1);
}

char	*check_comm(char *line)
{
	int 	position;
	char 	*new_line;

	if (ft_strchr(line, COMMENT_CHAR)
		|| ft_strchr(line, ALT_COMMENT_CHAR))
	{
		position = position_of_comm(line, COMMENT_CHAR,
			ALT_COMMENT_CHAR);
		new_line = ft_strsub(line, 0, position);
		free(line);
		return (new_line);
	}
	return (line);
}

void	check_for_op_after_label(t_pasm *pasm, char *line,
	int line_number, int label_char_pos)
{
	int		i;
	char 	**check;

	check = ft_strsplit(line, ' ');
	if (check[1])
	{
		i = 0;
		while (check[i])
			free(check[i++]);
		free(check);
		error_exit_line(pasm,
			"line after label has operation or characters", line_number);
	}
	free(check[0]);
	free(check);
	if (line[label_char_pos + 1])
	{
		if (ft_isalnum(line[label_char_pos + 1]))
			error_exit_line(pasm,
				"line after label has operation or characters", line_number);
	}
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
	if (!ft_isalpha(line[label_char_pos - 1]))
		return (NULL);
	check_for_op_after_label(pasm, line, line_number, label_char_pos);
	label = ft_strsub(line, 0, label_char_pos);
	if (!check_legal_chars(label, LABEL_CHARS))
		error_exit_line(pasm, "not ASCII characters in label",
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

	line_number = 1;
	label = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < 0)
			simple_error("corrupted file.");
		line = check_comm(line);
		if ((label = label_check(pasm, line, line_number))
			|| !line)
		{
			free(line);
			line_number++;
			continue ;
		}
		line_parse(pasm, line, line_number, &label);
		free(line);
		line_number++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:40:01 by swarner           #+#    #+#             */
/*   Updated: 2020/01/13 17:40:04 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned char	setbit(const unsigned char value, const int position)
{
	return (value | (1 << position));
}

int				check_for_op_after_label(char *line, int label_char_pos)
{
	if (line[label_char_pos + 1])
		return (1);
	return (0);
}

void			parse_file_helper(char **line,
	int *line_number, char **check_line)
{
	if (*check_line)
		free(*check_line);
	free(*line);
	*line = NULL;
	*line_number += 1;
}

int				is_blanc(char check)
{
	if (check == ' ' || check == '\t')
		return (1);
	return (0);
}

void			check_for_error_and_comm(int ret, char **line)
{
	if (ret < 0)
		simple_error("corrupted file.");
	*line = check_comm(*line);
}

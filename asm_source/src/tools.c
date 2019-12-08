/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:46:03 by swarner           #+#    #+#             */
/*   Updated: 2019/12/07 15:46:05 by swarner          ###   ########.fr       */
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

int		check_is_label(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (ft_isalpha(arg[i]))
			return (1);
		i++;
	}
	return (0);
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

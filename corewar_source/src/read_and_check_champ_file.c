/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_champ.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:04:45 by rrika             #+#    #+#             */
/*   Updated: 2019/12/10 14:04:49 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void			check_header(int fd)
{
	int				size;
	int				sign;
	unsigned int	magic_header;
	unsigned char	buff[4];

	size = read(fd, &buff, 4);
	if (size < 0)
		print_error_and_exit("Cannot read file", 51);
	if (size < 4)
		print_error_and_exit("Wrong magic header", 52);
	sign = (buff[0] >> 7) & 0x1;		//	TODO: переменстить это в byte_shift
	magic_header = byte_shift(buff, 4, sign);
	if (sign)
		magic_header = ~(magic_header);
	if (magic_header != COREWAR_EXEC_MAGIC)
		print_error_and_exit("Wrong magic header", 52);
}

char			*get_name_and_comment(int fd, int len)
{
	int		size;
	char	*buff;

	if (!(buff = ft_strnew(len)))
		print_error_and_exit("Memory does not allocated", 3);
	if ((size = read(fd, buff, len)) < 0)
		print_error_and_exit("Cannot read file", 51);
	if (size < len)
		print_error_and_exit("Name or comment is invalid", 54);
	return (buff);
}

unsigned int	miss_nulls(int fd)
{
	int				size;
	int				null_symbol;
	unsigned char	buff[4];

	if ((size = read(fd, &buff, 4)) < 0)
		print_error_and_exit("Cannot read file", 51);
	if (size < 4)
		print_error_and_exit("Wrong null symbol", 52);
	null_symbol = byte_shift(buff, 4, 0);
	if (null_symbol != 0)
		print_error_and_exit("Wrong null symbol", 52);
	return (null_symbol);
}

int				get_exec_code_size(int fd)
{
	int				exec_code_size;
	int				size;
	unsigned char	buff[4];

	if ((size = read(fd, &buff, 4)) < 0)
		print_error_and_exit("Cannot read file", 51);
	if (size < 4)
		print_error_and_exit("Wrong size of execution code", 55);
	exec_code_size = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | (buff[3]);
	if (exec_code_size > CHAMP_MAX_SIZE || exec_code_size < 0)
		print_error_and_exit("Execution code is too big", 56);
	return (exec_code_size);
}

unsigned char	*get_exec_code(int fd, int len)
{
	int				size;
	unsigned char	one_more;
	unsigned char	*buff;

	if (!(buff = malloc(len)))
		print_error_and_exit("Memory does not allocated", 3);
	if ((size = read(fd, buff, len)) < 0)
		print_error_and_exit("Cannot read file", 51);
	if (size < len || read(fd, &one_more, 1) != 0)
		print_error_and_exit("Wrong size of execution code", 57);
	return (buff);
}

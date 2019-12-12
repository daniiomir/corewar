/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:04:53 by rrika             #+#    #+#             */
/*   Updated: 2019/12/10 14:04:53 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		size_of_code(int fd)
{
	int exec_code_size;
	int size;
	unsigned char buff[5];

	if ((size = read(fd, &buff, 4)) < 0)
		print_error_and_exit("Cannot read file", 51);
	if (size < 4)
		print_error_and_exit("Wrong size of execution code", 56);
	exec_code_size = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | (buff[3]);
	if (exec_code_size > CHAMP_MAX_SIZE || exec_code_size < 0)
		print_error_and_exit("Execution code is too big", 57);
	return (exec_code_size);
}

unsigned char	*add_code(int fd, int len)
{
	int size;
	unsigned char one_more;
	unsigned char *buff;

	if (!(buff = malloc(len)))
		print_error_and_exit("Memory does not allocated", 3);
	if ((size = read(fd, buff, len)) < 0)
		print_error_and_exit("Cannot read file", 51);
	if (size < len || read(fd, &one_more, 1) != 0)
		print_error_and_exit("Wrong size of execution code", 58);
	return (buff);
}

/*
#include <stdbool.h>
static int32_t	bytecode_to_int32(const uint8_t *bytecode, size_t size)
{
	int32_t	result;
	bool	sign;
	int		i;

	result = 0;
	sign = (bool)(bytecode[0] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((bytecode[size - 1] ^ 0xFF) << (i++ * 8));
		else
			result += bytecode[size - 1] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}
*/

void	parse_champion(int champ_num, char *filename)
{
	int fd;
	t_champ *player;

	player = init_champion(champ_num);
	if ((fd = open(filename, O_RDONLY)) <= 0)
		print_error_and_exit(ft_strjoin("Cannot open file ", filename), 50);		// поменять на конкат
	check_header(fd);
	player->name = check_name(fd);
	miss_nulls(fd);
	player->size = size_of_code(fd);
	player->comment = check_comment(fd);
	miss_nulls(fd);
	player->code = add_code(fd, player->size);
	close(fd);
}

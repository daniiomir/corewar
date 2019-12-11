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

void	error(char *str)
{
	ft_putendl(str);
	exit(1);
}

int		size_of_code(int fd)
{
	int i;
	int size;
	unsigned char buff[5];

	if ((size = read(fd, &buff, 4)) < 0)
		error("error in reading file");
	if (size < 4)
		error("wrong size of code");
	i = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | (buff[3]);
	return (i);
}

unsigned char	*add_code(int fd, int len)
{
	int size;
	unsigned char one_more;
	unsigned char *buff;

	if (!(buff = malloc(len)))
		error("error in malloc");
	if ((size = read(fd, buff, len)) < 0)
		error("error in reading file");
	if (size < len || read(fd, &one_more, 1) != 0)
		error("wrong code");
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

void	print_all(t_champ *player)
{
	printf("ID = %d\n", player->id);
	printf("NAME = %s\n", player->name);
	printf("COMMENT = %s\n", player->comment);
	printf("SIZE = %d\n", player->size);
	printf("CODE = %d\n", bytecode_to_int32(player->code, player->size));
}
*/

t_champ	*parse_champion(int champ_num, char *filename)
{
	int fd;
	t_champ *player;

	player = init_champion(champ_num);
	if ((fd = open(filename, O_RDONLY)) <= 0)
		error("error in opening file");
	check_header(fd);
	player->name = check_name(fd);
	if (miss_nulls(fd) != 0)
		error("no null");
	if ((player->size = size_of_code(fd)) > CHAMP_MAX_SIZE || player->size < 0)
		error("code is too big");
	player->comment = check_comment(fd);
	if (miss_nulls(fd) != 0)
		error("no null");
	player->code = add_code(fd, player->size);
	/* print_all(player); */
	close(fd);
	return (player);
}

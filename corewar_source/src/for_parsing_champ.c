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

t_champ	*init_champion(int n_arg, int id)
{
	t_champ *player;

	if ((player = (t_champ *)malloc(sizeof(t_champ))) == NULL)
		print_error_and_exit("Memory does not allocated", 3);
	player->f_n_arg = n_arg;
	player->id = id + 1;
	player->name = NULL;
	player->comment = NULL;
	player->size = 0;
	player->code = NULL;
	return (player);
}

unsigned int    byte_shift(unsigned char *buff, int byte, int sign)
{
    unsigned int i;
    int j;

    i = 0;
    j = 0;
    while (byte > 0)
    {
        if (sign)
            i += ((buff[--byte] ^ 0xff) << (j++ * 8));
        else
            i += (buff[--byte] << (j++ * 8));
    }
    return (i);
/*    if (sign)
        i = ((buff[0] ^ 0xff) << 24) | ((buff[1] ^ 0xff) << 16) | ((buff[2] ^ 0xff) << 8) | (buff[3] ^ 0xff);
    else
        i = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | (buff[3]);*/
}

unsigned int		miss_nulls(int fd)
{
	int	size;
	int null_symbol;
	unsigned char buff[4];

	if ((size = read(fd, &buff, 4)) < 0)
		print_error_and_exit("Cannot read file", 51);
	if (size < 4)
		print_error_and_exit("Wrong null symbol", 52);
	null_symbol = byte_shift(buff, 4, 0);
	if (null_symbol != 0)
		print_error_and_exit("Wrong null symbol", 52);
	return (null_symbol);
}

void	check_header(int fd)
{
	int size;
	int sign;
	unsigned int magic_header;
	unsigned char buff[4];

	size = read(fd, &buff, 4);
	if (size < 0)
		print_error_and_exit("Cannot read file", 51);
	if (size < 4)
		print_error_and_exit("Wrong magic header", 52);
	sign = (buff[0] >> 7) & 0x1;
	magic_header = byte_shift(buff, 4, sign);
	if (sign)
		magic_header = ~(magic_header);
	if (magic_header != COREWAR_EXEC_MAGIC)
		print_error_and_exit("Wrong magic header", 52);
}

char	*check_name(int fd)
{
	int size;
	char *buff;

	if (!(buff = ft_strnew(PROG_NAME_LENGTH)))
		print_error_and_exit("Memory does not allocated", 3);
	if ((size = read(fd, buff, PROG_NAME_LENGTH)) < 0)
		print_error_and_exit("Cannot read file", 51);
	if (size < PROG_NAME_LENGTH)
		print_error_and_exit("Name is invalid", 54);
	return (buff);
}

char	*check_comment(int fd)
{
	int	size;
	char *buff;

	if (!(buff = ft_strnew(COMMENT_LENGTH)))
		print_error_and_exit("Memory does not allocated", 3);
	if ((size = read(fd, buff, COMMENT_LENGTH)) < 0)
		print_error_and_exit("Cannot read file", 51);
	if (size < COMMENT_LENGTH)
		print_error_and_exit("Comment is invalid", 55);
	return (buff);
}

// TODO: сделать функцию на нахождение отрицательных чисел х2
// доделать функцию
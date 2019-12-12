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

	if (!(player = (t_champ *)malloc(sizeof(t_champ))))
		error("error with malloc");
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
	unsigned int i;
	unsigned char buff[4];

	if ((size = read(fd, &buff, 4)) < 0)
		error("error in reading file");
	if (size < 4)
		error("wrong size");
	i = byte_shift(buff, 4, 0);
	/* i = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | (buff[3]); */
	return (i);
}

void	check_header(int fd)
{
	int size;
	int sign;
	unsigned int i;
	unsigned char buff[4];

	size = read(fd, &buff, 4);
	if (size < 0)
		error("error in reading file");
	if (size < 4)
		error("wrong magic header");
	sign = (buff[0] >> 7) & 0x1;
    i = byte_shift(buff, 4, sign);
	if (sign)
		i = ~(i);
	if (i != COREWAR_EXEC_MAGIC)
		error("wrong magic header");
}

char	*check_name(int fd)
{
	int size;
	char *buff;

	if (!(buff = ft_strnew(PROG_NAME_LENGTH)))
		error("error in malloc");
	if ((size = read(fd, buff, PROG_NAME_LENGTH)) < 0)
		error("error in reading file");
	if (size < PROG_NAME_LENGTH)
		error("bad name");
	return (buff);
}

char	*check_comment(int fd)
{
	int	size;
	char *buff;

	if (!(buff = ft_strnew(COMMENT_LENGTH)))
		error("error in malloc");
	if ((size = read(fd, buff, COMMENT_LENGTH)) < 0)
		error("error in reading file");
	if (size < COMMENT_LENGTH)
		error("wrong comment");
	return (buff);
}

// сделать функцию на нахождение отрицательных чисел х2
// доделать функцию
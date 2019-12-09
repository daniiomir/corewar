/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:44:25 by swarner           #+#    #+#             */
/*   Updated: 2019/12/09 17:00:27 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	error(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	exit(1);
}

t_champ	*init(int id)
{
	t_champ *player;

	if (!(player = (t_champ *)malloc(sizeof(t_champ))))
		error("error with malloc");
	player->id = id;
	player->name = NULL;
	player->comment = NULL;
	player->size = 0;
	player->code = NULL;
	return (player);
}

void	check_header(int fd)
{
	unsigned int i;
	unsigned char buff[5];

	if ((read(fd, buff, 4) < 0))
		error("error in reading file");
	i = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | (buff[3]);
	if (i != COREWAR_EXEC_MAGIC)
		error("wrong magic header");
}

int		miss_nulls(int fd)
{
	int	size;
	int i;
	unsigned char buff[5];

	if ((size = read(fd, &buff, 4) < 0))
		error("error in reading file");
	if (size < 4)
		error("wrong size");
	i = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | (buff[3]);
	return (i);
}

char	*check_name(int fd)
{
	int size;
	char *buff;

	if (!(buff = malloc(PROG_NAME_LENGTH + 1)))
		error("error in malloc");
	if ((size = read(fd, &buff, PROG_NAME_LENGTH) < 0))
		error("error in reading file");
	if (size < PROG_NAME_LENGTH)
		error("bad name");
	return (buff);
}

char	*check_comment(int fd)
{
	int	size;
	char *buff;

	if (!(buff = malloc(COMMENT_LENGTH + 1)))
		error("error in malloc");
	if ((size = read(fd, &buff, COMMENT_LENGTH) < 0))
		error("error in reading file");
	if (size < COMMENT_LENGTH)
		error("wrong comment");
	return (buff);
}

int	size_of_code(int fd)
{
	int i;
	int size;
	unsigned char buff[5];

	if ((size = read(fd, &buff, 4) < 0))
		error("error in reading file");
	if (size < 4)
		error("wrong size of code");
	i = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | (buff[3]);
	return (i);
}

unsigned char	*check_code(int fd, int len)
{
	int size;
	unsigned char *buff;

	if (!(buff = malloc(len + 1)))
		error("error in malloc");
	if ((size = read(fd, &buff, len) < 0))
		error("error in reading file");
	if (size < len)
		error("wrong code");
	return (buff);
}

int     main(int argc, char **argv)
{
	int fd;
	int id;
	t_champ *player;

	id = 1;
	player = init(id);
	if ((fd = open(argv[1], O_RDONLY) < 0))
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
	player->code = check_code(fd, player->size);

	/* printf("%x ", buff[0]);
	printf("%x ", buff[1]);
	printf("%x ", buff[2]);
	printf("%x \n", buff[3]);
	i = (unsigned int)*(buff+2); */
//	printf("%x \n", i);
//	i = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | (buff[3]);
//	printf("%x ", i);

//
//	printf("hello - %d", i == 0xea83f3);
	/* while ((ret = read(fd, buff, 1000)))
	{
		i = 0;
		while (i < ret) {
			printf("%x ", buff[i]);
			i++;
		}
		// write(1, buff, 1000);
	} */
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:44:25 by swarner           #+#    #+#             */
/*   Updated: 2019/12/06 19:15:54 by rrika            ###   ########.fr       */
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

t_champ	*init(int id)
{
	t_champ *player;

	if (!(player = (t_champ *)ft_memalloc(sizeof(t_champ))))
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

	if ((read(fd, buff, 4) < 0)
	    error("error in reading file");
	i = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | (buff[3]);
	if (i != COREWAR_EXEC_MAGIC)
		error("wrong magic header");
}

char	*miss_nulls(int fd)
{
    int	size;
    unsigned char buff[5];

    if ((read(fd, buff, 4) < 0)
        error("error in reading file");
    return ((char*)buff);
}

char	*check_name(int fd)
{
	int size;
	unsigned char buff[PROG_NAME_LENGTH + 1];

	if ((size = read(fd, buff, PROG_NAME_LENGTH) < 0)
        error("error in reading file");
	if (size < PROG_NAME_LENGTH)
	    error("bad name");
	return ((char*)buff);

}

unsigned char *size_of_code(int fd)
{
    int size;
    unsigned char buff[5];

    if ((read(fd, buff, 4) < 0)
        error("error in reading file");
    if (size < 4)
        error("wrong size of code");
    return (buff);
}

int     main(int argc, char **argv)
{
	int fd;
	int id;
	unsigned char buff[1000];
	t_champ *player;

	id = 1;
	player = init(id);
	if ((fd = open(argv[1], O_RDONLY) < 0)
	    error("error in opening file");
	check_header(fd);
	player->name = check_name(fd);
	miss_nulls(fd);
	if ((player->size = size_of_code(fd)) > CHAMP_MAX_SIZE)
	    error("code is too big");


	
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

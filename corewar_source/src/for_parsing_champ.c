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

t_champ	*init_champion(int id)
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

int		miss_nulls(int fd)
{
	int	size;
	int i;
	unsigned char buff[5];

	if ((size = read(fd, &buff, 4)) < 0)
		error("error in reading file");
	if (size < 4)
		error("wrong size");
	i = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | (buff[3]);
	return (i);
}

void	check_header(int fd)
{
	int size;
	unsigned int i;
	unsigned char buff[4];

	size = read(fd, &buff, 4);
	if (size < 0)
		error("error in reading file");
	if (size < 4)
		error("wrong magic header");
	i = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | (buff[3]);
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

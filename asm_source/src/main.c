/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:44:25 by swarner           #+#    #+#             */
/*   Updated: 2019/11/13 15:44:27 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		open_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_putendl("Error: invalid file name.");
	return (fd);
}

int		main(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
	{
		fd = open_file(argv[1]);
		close(fd);
	}
	else if (argc > 2)
		ft_putendl("Error: too much files.");
	else
		ft_putendl("Error: no file.");
}

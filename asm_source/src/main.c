/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:44:25 by swarner           #+#    #+#             */
/*   Updated: 2019/12/04 17:29:19 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_pasm	*pasm;

	if (argc == 2)
	{
		fd = open_file(argv[1]);
		pasm = init_pasm();
		parse_file(fd, pasm);
		write_hex_to_file(pasm, argv[1]);
		free_pasm(pasm);
		close(fd);
	}
	else if (argc > 2)
		ft_putendl("Error: too much files.");
	else
		ft_putendl("Error: no file.");
}

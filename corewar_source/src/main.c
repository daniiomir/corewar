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

#include "corewar.h"

int		main(int argc, char **argv)
{
    t_gstate *gstate;

    gstate = init_global_state();
	parse_arguments(gstate, argc - 1, argv + 1);
}

void print_error_and_exit(char *errstr, int errno) {
    printf("%s\n", errstr);
    exit(errno);
}

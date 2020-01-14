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
#include "corewar_vis.h"

int	main(int argc, char **argv)
{
	t_gstate	*gstate;

	gstate = init_global_state();
	parse_arguments(gstate, argc - 1, argv + 1);
	order_of_champs(gstate);
	gstate->arena = init_arena(gstate);
	fill_arena_and_init_cursors(gstate->arena, gstate);
	if (gstate->f_v)
		visualisation(gstate, gstate->arena);
	else
		main_alg(gstate);
	free_all(gstate);
}

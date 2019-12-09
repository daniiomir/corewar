/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:12:27 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/09 17:12:30 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "corewar.h"
#include <stdio.h>

t_arena 	*new_arena()
{
	t_arena		*new;

	if (!(new = (t_arena *)malloc(sizeof(t_arena))))
		return(NULL);
	return (new);
}

void 	init_arena()
{
	t_arena		*new;
	int 		a;

	a = 0;
	new = new_arena();
	//while (a < MEM_SIZE)
		//new->arena[a++] = 0x0; //asdasdd
	a = 0;
	printf("\n");
	while (a < MEM_SIZE)
	{
		printf("%02x ", new->arena[a++]);
		if (a % 64 == 0)
			printf("\n");
	}
}
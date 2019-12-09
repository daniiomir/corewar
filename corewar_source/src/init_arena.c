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

t_arena 	*new_arena()
{
	t_arena		*new;

	if (!(new = (t_arena *)malloc(sizeof(t_arena))))
		return(NULL);
}

void 	init_arena()
{
	t_arena		*new;

	new = new_arena();
}
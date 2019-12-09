/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:55:15 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/09 16:55:16 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

#include "../../asm_source/includes/op.h"

typedef struct	s_arena
{
	int 	arena[MEM_SIZE];
}				t_arena;
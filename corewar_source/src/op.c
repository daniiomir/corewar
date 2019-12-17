/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2013/11/06 14:44:35 by zaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_op    op_tab[17] =
{
		{0, 0, 0, {0}, 0, 0, 0, 0, 0},
//		{1, "live", 1, {T_DIR}, 10, "alive", 0, 0, 4, &live},
		{1, "live", 1, {T_DIR}, 10, "alive", 0, 0, 4},
		{2, "ld", 2, {T_DIR | T_IND, T_REG}, 5, "load", 1, 1, 4},
		{3, "st", 2, {T_REG, T_IND | T_REG}, 5, "store", 1, 0, 4},
		{4, "add", 3, {T_REG, T_REG, T_REG}, 10, "addition", 1, 1, 4},
		{5, "sub", 3, {T_REG, T_REG, T_REG}, 10, "soustraction", 1, 1, 4},
		{6, "and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
   																			6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 1, 4},
		{7, "or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
   																			6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 1, 4},
		{8, "xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
   																			6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 1, 4},
		{9, "zjmp", 1, {T_DIR}, 20, "jump if zero", 0, 0, 2},
		{10,"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
   																	25, "load index", 1, 0, 2},
		{11, "sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
   																	25, "store index", 1, 0, 2},
		{12, "fork", 1, {T_DIR}, 800, "fork", 0, 0, 2},
		{13, "lld", 2, {T_DIR | T_IND, T_REG}, 10, "long load", 1, 1, 4},
		{14, "lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 50, "long load index", 1, 1, 2},
		{15, "lfork", 1, {T_DIR}, 1000, "long fork", 0, 0, 2},
		{16, "aff", 1, {T_REG}, 2, "aff", 1, 0, 4}
};
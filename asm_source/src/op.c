/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2019/12/04 17:29:43 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2},
	{"st", 2, {T_REG, T_IND | T_REG}, 3},
	{"add", 3, {T_REG, T_REG, T_REG}, 4},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8},
	{"zjmp", 1, {T_DIR}, 9},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11},
	{"fork", 1, {T_DIR}, 12},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14},
	{"lfork", 1, {T_DIR}, 15},
	{"aff", 1, {T_REG}, 16},
	{NULL, 0, {0}, 0}
};

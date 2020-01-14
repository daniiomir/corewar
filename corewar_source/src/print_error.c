/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:23:03 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 13:23:04 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	print_error_and_exit(char *errstr, int errno)
{
	ft_printf("Error: %s\n", errstr);
	exit(errno);
}

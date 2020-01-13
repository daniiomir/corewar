/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:43:10 by swarner           #+#    #+#             */
/*   Updated: 2020/01/13 17:43:12 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_magic_header(t_pasm *pasm)
{
	char	*magic_header;

	magic_header = ft_strlower(ft_itoa_base(COREWAR_EXEC_MAGIC, 16));
	magic_header = ft_strjoin_free_all(get_nulls(2), magic_header);
	pasm->hex_code->magic_header = magic_header;
}

void	get_null_octets(t_pasm *pasm)
{
	char	*null_octet;
	char	*null_octet2;

	null_octet = get_nulls(8);
	null_octet2 = ft_strdup(null_octet);
	pasm->hex_code->null_octet = null_octet;
	pasm->hex_code->null_octet2 = null_octet2;
}

void	add_nulls_to_comment(char **hex_champ_comm, int len)
{
	int		null_len;

	if (len < 2048 * 2)
	{
		null_len = 2048 * 2 - len;
		*hex_champ_comm = ft_strjoin_free_all(*hex_champ_comm,
			get_nulls(null_len));
	}
}

void	code_get_hex_addcode2(t_code *code_line, unsigned char *addcode)
{
	if (code_line->arg3_type == REG_CODE)
		*addcode = setbit(*addcode, 2);
	else if (code_line->arg3_type == DIR_CODE)
		*addcode = setbit(*addcode, 3);
	else if (code_line->arg3_type == IND_CODE)
	{
		*addcode = setbit(*addcode, 2);
		*addcode = setbit(*addcode, 3);
	}
}

char	*code_get_hex_addcode(t_code *code_line)
{
	unsigned char	addcode;

	if (!check_for_code_arg_type(code_line))
		return (ft_strnew(0));
	addcode = 0;
	if (code_line->arg1_type == REG_CODE)
		addcode = setbit(addcode, 6);
	else if (code_line->arg1_type == DIR_CODE)
		addcode = setbit(addcode, 7);
	else if (code_line->arg1_type == IND_CODE)
	{
		addcode = setbit(addcode, 6);
		addcode = setbit(addcode, 7);
	}
	if (code_line->arg2_type == REG_CODE)
		addcode = setbit(addcode, 4);
	else if (code_line->arg2_type == DIR_CODE)
		addcode = setbit(addcode, 5);
	else if (code_line->arg2_type == IND_CODE)
	{
		addcode = setbit(addcode, 4);
		addcode = setbit(addcode, 5);
	}
	code_get_hex_addcode2(code_line, &addcode);
	return (ft_strlower(ft_itoa_base((int)addcode, 16)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_struct_to_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:31:34 by swarner           #+#    #+#             */
/*   Updated: 2019/12/07 15:31:37 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define CHAR00	0b00000000

#define CHAR01	0b00000001
#define CHAR02	0b00000010
#define CHAR03	0b00000011
#define CHAR04	0b00000100
#define CHAR05	0b00000101
#define CHAR06	0b00000110
#define CHAR07	0b00000111
#define CHAR08	0b00001000
#define CHAR09	0b00001001
#define CHAR0A	0b00001010
#define CHAR0B	0b00001011
#define CHAR0C	0b00001100
#define CHAR0D	0b00001101
#define CHAR0E	0b00001110
#define CHAR0F	0b00001111

void			hex_part2(char chr, unsigned char *bytecode)
{
	if (chr == '8')
		*bytecode = CHAR08;
	else if (chr == '9')
		*bytecode = CHAR09;
	else if (chr == 'a')
		*bytecode = CHAR0A;
	else if (chr == 'b')
		*bytecode = CHAR0B;
	else if (chr == 'c')
		*bytecode = CHAR0C;
	else if (chr == 'd')
		*bytecode = CHAR0D;
	else if (chr == 'e')
		*bytecode = CHAR0E;
	else if (chr == 'f')
		*bytecode = CHAR0F;
}

unsigned char	hex_part(char chr)
{
	unsigned char bytecode;

	bytecode = 0;
	if (chr == '0')
		bytecode = CHAR00;
	else if (chr == '1')
		bytecode = CHAR01;
	else if (chr == '2')
		bytecode = CHAR02;
	else if (chr == '3')
		bytecode = CHAR03;
	else if (chr == '4')
		bytecode = CHAR04;
	else if (chr == '5')
		bytecode = CHAR05;
	else if (chr == '6')
		bytecode = CHAR06;
	else if (chr == '7')
		bytecode = CHAR07;
	else
		hex_part2(chr, &bytecode);
	return (bytecode);
}

void			write_in_hex(int fd, char *hex_string)
{
	size_t			i;
	size_t			len;
	unsigned char	*bytecode;

	len = ft_strlen(hex_string) / 2;
	bytecode = (unsigned char *)malloc(sizeof(unsigned char) * len);
	ft_strset((char *)bytecode, len, 0);
	i = 0;
	while (i < len)
	{
		bytecode[i] = hex_part(hex_string[i * 2]) << 4;
		bytecode[i] |= hex_part(hex_string[i * 2 + 1]);
		i++;
	}
	write(fd, bytecode, len);
	free(bytecode);
}

void			write_all_to_file(int fd, t_pasm *pasm)
{
	t_code	*tmp;

	tmp = pasm->code;
	write_in_hex(fd, pasm->hex_code->magic_header);
	write_in_hex(fd, pasm->hex_code->champion_name);
	write_in_hex(fd, pasm->hex_code->null_octet);
	write_in_hex(fd, pasm->hex_code->exec_size);
	write_in_hex(fd, pasm->hex_code->champion_comment);
	write_in_hex(fd, pasm->hex_code->null_octet2);
	while (tmp)
	{
		write_in_hex(fd, tmp->hex);
		tmp = tmp->next;
	}
}

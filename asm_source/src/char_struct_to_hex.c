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

/*
#define CHAR10	0b00010000
#define CHAR20	0b00100000
#define CHAR30	0b00110000
#define CHAR40	0b01000000
#define CHAR50	0b01010000
#define CHAR60	0b01100000
#define CHAR70	0b01110000
#define CHAR80	0b10000000
#define CHAR90	0b10010000
#define CHARA0	0b10100000
#define CHARB0	0b10110000
#define CHARC0	0b11000000
#define CHARD0	0b11010000
#define CHARE0	0b11100000
#define CHARF0	0b11110000
        

        Char *str = "010000000f";
        int len = ft_strlen(str) / 2; //10/2 = 5
        unsingned char *byte_code[len]; //5 элементов
        int i = 0;
        while (i < len)
        {
            while (перебираем 15 символов для первой буквы байта)
            {
                if(str[i*2]=='символ0-f')
                    byte_code[i]|= код_первой_буквы;
            }
            while (перебираем 15 символов для второй буквы байта)
            {
                if(str[i*2+1]=='символ0-f')
                  byte_code[i]|= код_второй_буквы;
            }
            i++;
        }


void	write_in_hex_part1(char *s, unsigned char **bytecode, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (s[i * 2] == '0')
			(*bytecode)[i] |= CHAR00;
		else if (s[i * 2 + 1] == '1')
			(*bytecode)[i] |= CHAR01;
		else if (s[i * 2 + 1] == '2')
			(*bytecode)[i] |= CHAR02;
		else if (s[i * 2 + 1] == '3')
			(*bytecode)[i] |= CHAR03;
		else if (s[i * 2 + 1] == '4')
			(*bytecode)[i] |= CHAR04;
		else if (s[i * 2 + 1] == '5')
			(*bytecode)[i] |= CHAR05;
		else if (s[i * 2 + 1] == '6')
			(*bytecode)[i] |= CHAR06;
		else if (s[i * 2 + 1] == '7')
			(*bytecode)[i] |= CHAR07;
		else if (s[i * 2 + 1] == '8')
			(*bytecode)[i] |= CHAR08;
		else if (s[i * 2 + 1] == '9')
			(*bytecode)[i] |= CHAR09;
		else if (s[i * 2 + 1] == 'a')
			(*bytecode)[i] |= CHAR0A;
		else if (s[i * 2 + 1] == 'b')
			(*bytecode)[i] |= CHAR0B;
		else if (s[i * 2 + 1] == 'c')
			(*bytecode)[i] |= CHAR0C;
		else if (s[i * 2 + 1] == 'd')
			(*bytecode)[i] |= CHAR0D;
		else if (s[i * 2 + 1] == 'e')
			(*bytecode)[i] |= CHAR0E;
		else if (s[i * 2 + 1] == 'f')
			(*bytecode)[i] |= CHAR0F;
		i++;
	}
}

void	write_in_hex_part2(char *s, unsigned char **bytecode, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (s[i * 2 + 1] == '0')
			(*bytecode)[i] |= CHAR00;
		else if (s[i * 2] == '1')
			(*bytecode)[i] |= CHAR10;
		else if (s[i * 2] == '2')
			(*bytecode)[i] |= CHAR20;
		else if (s[i * 2] == '3')
			(*bytecode)[i] |= CHAR30;
		else if (s[i * 2] == '4')
			(*bytecode)[i] |= CHAR40;
		else if (s[i * 2] == '5')
			(*bytecode)[i] |= CHAR50;
		else if (s[i * 2] == '6')
			(*bytecode)[i] |= CHAR60;
		else if (s[i * 2] == '7')
			(*bytecode)[i] |= CHAR70;
		else if (s[i * 2] == '8')
			(*bytecode)[i] |= CHAR80;
		else if (s[i * 2] == '9')
			(*bytecode)[i] |= CHAR90;
		else if (s[i * 2] == 'a')
			(*bytecode)[i] |= CHARA0;
		else if (s[i * 2] == 'b')
			(*bytecode)[i] |= CHARB0;
		else if (s[i * 2] == 'c')
			(*bytecode)[i] |= CHARC0;
		else if (s[i * 2] == 'd')
			(*bytecode)[i] |= CHARD0;
		else if (s[i * 2] == 'e')
			(*bytecode)[i] |= CHARE0;
		else if (s[i * 2] == 'f')
			(*bytecode)[i] |= CHARF0;
		i++;
	}
}
*/
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
    else if (chr == '8')
        bytecode = CHAR08;
    else if (chr == '9')
        bytecode = CHAR09;
    else if (chr == 'a')
        bytecode = CHAR0A;
    else if (chr == 'b')
        bytecode = CHAR0B;
    else if (chr == 'c')
        bytecode = CHAR0C;
    else if (chr == 'd')
        bytecode = CHAR0D;
    else if (chr == 'e')
        bytecode = CHAR0E;
    else if (chr == 'f')
        bytecode = CHAR0F;
    return (bytecode);
}

void	write_in_hex(int fd, char *hex_string)
{
	size_t			len;
	unsigned char	*bytecode;

	len = ft_strlen(hex_string) / 2;
	bytecode = (unsigned char *)malloc(sizeof(unsigned char) * len);
	ft_strset((char *)bytecode, len, 0);
    size_t	i;

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


void	write_all_to_file(int fd, t_pasm *pasm)
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

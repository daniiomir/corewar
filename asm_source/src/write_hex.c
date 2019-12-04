/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:30:14 by swarner           #+#    #+#             */
/*   Updated: 2019/12/04 17:30:16 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_nulls(int len)
{
	int		i;
	char	*nulls;

	i = 0;
	nulls = ft_strnew(len);
	while (nulls[i])
		nulls[i] = '0';
	return (nulls);
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

void	get_magic_header(t_pasm *pasm)
{
	char	*magic_header;

	magic_header = ft_strlower(ft_itoa_base(COREWAR_EXEC_MAGIC, 16));
	magic_header = ft_strjoin_free2(get_nulls(2), magic_header);
	pasm->hex_code->magic_header = magic_header;
}

void	get_exec_size(t_pasm *pasm)
{
	int		code_size;
	t_code 	*temp;
	char	*hex_code_size;
	int		len;

	code_size = 0;
	temp = pasm->code;
	while (temp)
	{
		code_size += temp->size;
		temp = temp->next;
	}
	hex_code_size = ft_itoa_base(code_size, 16);
	len = (int)ft_strlen(hex_code_size);
	if (len < 4 * 2)
		hex_code_size = ft_strjoin_free_all(get_nulls(8 - len), hex_code_size);
	pasm->hex_code->exec_size = hex_code_size;
}

void	get_hex_champ_comment(t_pasm *pasm)
{
	int		i;
	int		len;
	int		null_len;
	char	*hex_champ_comm;

	i = 0;
	hex_champ_comm = ft_strnew(0);
	while (pasm->comment[i])
	{
		hex_champ_comm = ft_strjoin_free(hex_champ_comm,
			ft_strlower(ft_itoa_base(pasm->comment[i], 16)));
		i++;
	}
	len = (int)ft_strlen(hex_champ_comm);
	if (len < 128 * 2)
	{
		null_len = 128 * 2 - len;
		hex_champ_comm = ft_strjoin_free_all(hex_champ_comm, get_nulls(null_len));
	}
	pasm->hex_code->champion_comment = hex_champ_comm;
}

void	get_hex_champ_name(t_pasm *pasm)
{
	int		i;
	int		len;
	int		null_len;
	char	*hex_champ_name;

	i = 0;
	hex_champ_name = ft_strnew(0);
	while (pasm->champion_name[i])
	{
		hex_champ_name = ft_strjoin_free(hex_champ_name,
			ft_strlower(ft_itoa_base(pasm->champion_name[i], 16)));
		i++;
	}
	len = (int)ft_strlen(hex_champ_name);
	if (len < 128 * 2)
	{
		null_len = 128 * 2 - len;
		hex_champ_name = ft_strjoin_free_all(hex_champ_name, get_nulls(null_len));
	}
	pasm->hex_code->champion_name = hex_champ_name;
}

void	write_all_to_final_code(t_pasm *pasm)
{
	char	*buffer;

	buffer = ft_strjoin(pasm->magic_header, pasm->champion_name);
	buffer = ft_strjoin_free(buffer, pasm->null_octet);
	buffer = ft_strjoin_free(buffer, pasm->exec_size);
	buffer = ft_strjoin_free(buffer, pasm->champion_comment);
	buffer = ft_strjoin_free(buffer, pasm->null_octet2);
	buffer = ft_strjoin_free(buffer, pasm->exec_code);
	pasm->final_code = buffer;
}

void	write_hex_to_pasm(t_pasm *pasm)
{
	get_magic_header(pasm);
	get_hex_champ_name(pasm);
	get_null_octets(pasm);
	get_exec_size(pasm);
	get_hex_champ_comment(pasm);
	get_hex_exec_code(pasm);
	write_all_to_final_code(pasm);
}

char	*new_filename(char *name)
{
	char	*name;

	name = ft_strsub(name, 0, ft_strlen(name) - 2);
	name = ft_strjoin_free(name, ".cor");
	return (name);
}

void	write_hex_to_file(t_pasm *pasm, char *file_name)
{
	int		fd;
	char	*new_name;

	new_name = new_filename(file_name);
	fd = open(new_name, O_CREAT);
	write_hex_to_pasm(pasm);
	write(fd, pasm->final_code, ft_strlen(pasm->final_code));
	close(fd);
	free(new_name);
}

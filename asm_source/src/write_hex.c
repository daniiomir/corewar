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

void	get_exec_size(t_pasm *pasm)
{
	int		code_size;
	t_code	*temp;
	char	*hex_code_size;
	int		len;

	code_size = 0;
	temp = pasm->code;
	while (temp)
	{
		code_size += temp->size;
		temp = temp->next;
	}
	hex_code_size = ft_strlower(ft_itoa_base(code_size, 16));
	len = (int)ft_strlen(hex_code_size);
	if (len < 8)
		hex_code_size = ft_strjoin_free_all(get_nulls(8 - len), hex_code_size);
	else
		error_exit(pasm, "size of assembler code is too big in bytes.");
	pasm->hex_code->exec_size = hex_code_size;
}

void	get_hex_champ_comment(t_pasm *pasm)
{
	int		i;
	int		len;
	char	*hex_champ_comm;

	i = 0;
	hex_champ_comm = ft_strnew(0);
	if (pasm->comment)
	{
		while (pasm->comment[i])
		{
			hex_champ_comm = ft_strjoin_free_all(hex_champ_comm,
				ft_strlower(ft_itoa_base(pasm->comment[i], 16)));
			i++;
		}
		len = (int)ft_strlen(hex_champ_comm);
	}
	else
		len = 0;
	add_nulls_to_comment(&hex_champ_comm, len);
	pasm->hex_code->champion_comment = hex_champ_comm;
}

void	get_hex_champ_name(t_pasm *pasm)
{
	int		i;
	int		len;
	int		null_len;
	char	*hex_champ_name;

	i = 0;
	if (!pasm->champion_name)
		error_exit(pasm, "no champion name.");
	hex_champ_name = ft_strnew(0);
	while (pasm->champion_name[i])
	{
		hex_champ_name = ft_strjoin_free_all(hex_champ_name,
			ft_strlower(ft_itoa_base(pasm->champion_name[i], 16)));
		i++;
	}
	len = (int)ft_strlen(hex_champ_name);
	if (len < 128 * 2)
	{
		null_len = 128 * 2 - len;
		hex_champ_name = ft_strjoin_free_all(hex_champ_name,
			get_nulls(null_len));
	}
	pasm->hex_code->champion_name = hex_champ_name;
}

void	write_hex_to_pasm(t_pasm *pasm)
{
	get_magic_header(pasm);
	get_hex_champ_name(pasm);
	get_null_octets(pasm);
	get_exec_size(pasm);
	get_hex_champ_comment(pasm);
	switch_labels_to_adress(pasm, pasm->code);
	code_to_hex(pasm);
}

void	write_hex_to_file(t_pasm *pasm, char *file_name)
{
	int		fd;
	char	*new_name;

	new_name = new_filename(file_name);
	fd = open(new_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		error_exit(pasm, "can't create file!");
	write_hex_to_pasm(pasm);
	write_all_to_file(fd, pasm);
	close(fd);
	ft_putendl("Translation of your champion finished!");
	ft_putstr("Bytecode of champion has written in ");
	ft_putendl(new_name);
	free(new_name);
}

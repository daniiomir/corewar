/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:17:33 by rrika             #+#    #+#             */
/*   Updated: 2019/12/09 18:23:43 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_PARSING_H
# define FILE_PARSING_H

unsigned char   *add_code(int fd, int len);
int             size_of_code(int fd);
char            *check_comment(int fd);
char            *check_name(int fd);
int             miss_nulls(int fd);
void            check_header(int fd);
t_champ         *init_champion(int id);
void            error(char *str);
void			parse_champion(int champ_num, char *filename);

#endif

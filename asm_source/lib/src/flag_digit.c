/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_digit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:35:11 by cnikia            #+#    #+#             */
/*   Updated: 2019/08/31 13:21:51 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	utoa_base(uintmax_t num, char flag, int base, t_pf **pf)
{
	int					a;
	unsigned long long	n;

	a = (num == 0) ? 1 : 0;
	n = num;
	while (n && ++a)
		n /= base;
	if (((*pf)->arg = (char *)malloc(sizeof(char) * (a + 1))))
	{
		(*pf)->malloc = 1;
		((*pf)->arg)[a] = '\0';
		if (num == 0)
			((*pf)->arg)[0] = '0';
		while (num)
		{
			if (num % base < 10)
				((*pf)->arg)[--a] = num % base + '0';
			else
				((*pf)->arg)[--a] = num % base + flag - 33;
			num /= base;
		}
	}
}

static void	get_arg(va_list ap, intmax_t *num, t_pf **pf)
{
	int	d;

	d = ((*pf)->type == 'd') ? 1 : 0;
	if ((*pf)->mode == 0)
		*num = (d) ? va_arg(ap, int) : va_arg(ap, unsigned int);
	if ((*pf)->mode == 'l')
		*num = (d) ? va_arg(ap, long) : va_arg(ap, unsigned long);
	if ((*pf)->mode == 'k')
		*num = (d) ? va_arg(ap, long long) : va_arg(ap, unsigned long long);
	if ((*pf)->mode == 'h')
		*num = (d) ? (short)va_arg(ap, int) : (unsigned short)va_arg(ap, int);
	if ((*pf)->mode == 'g')
		*num = (d) ? (signed char)va_arg(ap, int) :
		(unsigned char)va_arg(ap, int);
	if ((*pf)->mode == 'm')
		*num = (d) ? va_arg(ap, intmax_t) : va_arg(ap, uintmax_t);
	if ((*pf)->mode == 'z')
		*num = va_arg(ap, size_t);
}

static void	get_sign(t_pf **pf, intmax_t *num)
{
	if ((*pf)->type == 'd' && (*pf)->mode == 0)
		(*num) = (int)(*num);
	if ((*pf)->type == 'd' && (*num) < 0)
	{
		(*pf)->sign = '-';
		(*num) *= -1;
	}
	else
		(*pf)->sign = '+';
}

void		flag_digit(va_list ap, t_pf **pf)
{
	intmax_t		num;
	int				base;
	char			flag;

	flag = ((*pf)->type == 'X') ? 'X' : 'x';
	if ((*pf)->type == 'i')
		(*pf)->type = 'd';
	if ((*pf)->type == 'U')
		(*pf)->mode = 'l';
	if ((*pf)->type == 'x' || (*pf)->type == 'X' || (*pf)->type == 'p')
		base = 16;
	else if ((*pf)->type == 'o')
		base = 8;
	else
		base = 10;
	if ((*pf)->type == 'p')
		(*pf)->mode = 'l';
	if ((*pf)->type == 'p')
		(*pf)->flag = (*pf)->flag | 8;
	get_arg(ap, &num, pf);
	get_sign(pf, &num);
	utoa_base(num, flag, base, pf);
}

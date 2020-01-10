/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:39:36 by cnikia            #+#    #+#             */
/*   Updated: 2019/08/31 13:22:03 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			mode_main_check(t_pf **pf, int *a, const char *str,
va_list ap)
{
	while (str[(*a)] && ft_strchr(" #'*+,-.:;0123456789lhjz_L", str[(*a)]))
	{
		if (ft_strchr("-+ #0", str[(*a)]))
			add_flag(pf, &str[(*a)]);
		else if ((str[(*a)] >= '0' && str[(*a)] <= '9') || str[(*a)] == '*')
			add_wide(ap, pf, &str[(*a)], a);
		else if (str[(*a)] == '.')
		{
			(*a)++;
			if (!(add_prec(ap, pf, &str[(*a)], a)))
				continue ;
		}
		else if (ft_strchr("hlLjz", str[(*a)]) && (*pf)->mode < str[(*a)])
			add_mode(pf, &str[(*a)], a);
		(*a)++;
	}
}

static int			type_main_check(t_pf **pf, int *a,
const char *str, va_list ap)
{
	if (str[(*a)])
		(*pf)->type = str[(*a)];
	if (str[(*a)] && ft_strchr("%cspdiouUxXf", str[(*a)]))
	{
		if (ft_strchr("cs", str[(*a)]))
			flag_str(ap, pf);
		if (ft_strchr("pdiouUxX", str[(*a)]))
			flag_digit(ap, pf);
		if (str[(*a)] == 'f')
			flag_double(ap, pf);
		if (str[(*a)] == '%')
			flag_percent(pf);
		(*a)++;
	}
	else
		return (0);
	return (1);
}

static int			flag_case(int *a, const char *str, va_list ap)
{
	t_pf	*pf;
	int		b;

	if (str[(*a) + 1])
		(*a)++;
	else
	{
		(*a)++;
		return (0);
	}
	pf = pf_new();
	mode_main_check(&pf, a, str, ap);
	if (!(type_main_check(&pf, a, str, ap)))
	{
		free(pf);
		return (0);
	}
	(pf->type == 'c' || pf->type == 's') ?
	final_print_c(&pf) : final_print(&pf);
	if (pf->malloc == 1)
		free(pf->arg);
	b = pf->b;
	free(pf);
	return (b);
}

static int			read_string(const char *str, va_list ap)
{
	int		a;
	int		count;

	a = 0;
	count = 0;
	while (str[a])
	{
		if (str[a] == '%')
			count += flag_case(&a, str, ap);
		if (str[a] != '%' && str[a])
		{
			ft_putchar(str[a]);
			count++;
			a++;
		}
	}
	return (count);
}

int					ft_printf(const char *format, ...)
{
	va_list ap;
	int		a;

	a = 0;
	va_start(ap, format);
	a = read_string(format, ap);
	va_end(ap);
	return (a);
}

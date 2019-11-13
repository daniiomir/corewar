/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:45:38 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			is_space(char a)
{
	if (a == '\v' || a == '\n' || a == '\t' || a == '\a'
		|| a == '\b' || a == '\f' || a == '\r' || a == ' ')
		return (1);
	return (0);
}

static ssize_t		leak_check(size_t count,
	long long int sign, long long int answer)
{
	if (count >= 19)
		return (sign == -1 ? 0 : -1);
	return (sign * answer);
}

ssize_t				ft_atoi(const char *str)
{
	long long int		answer;
	long long int		sign;
	size_t				i;
	size_t				count;

	i = 0;
	sign = 1;
	answer = 0;
	count = 0;
	while (is_space(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		answer = (answer * 10) + (str[i++] - '0');
		count++;
	}
	return (leak_check(count, sign, answer));
}

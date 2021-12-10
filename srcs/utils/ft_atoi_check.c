/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:05:34 by apitoise          #+#    #+#             */
/*   Updated: 2021/05/18 13:30:09 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

long long	ft_atoi_check(const char *str)
{
	long long	res;
	int				neg;
	int				pos;

	pos = 0;
	while (str[pos] == '\t' || str[pos] == '\n' || str[pos] == '\v'
			|| str[pos] == '\f' || str[pos] == '\r' || str[pos] == ' ')
		pos++;
	neg = 1;
	if (str[pos] == '+' || str[pos] == '-')
	{
		if (str[pos] == '-')
			neg++;
		pos++;
	}
	res = 0;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		res = res * 10;
		res = res + str[pos] - 48;
		pos++;
	}
	if (neg % 2 == 0)
		return (-res);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:52:41 by apitoise          #+#    #+#             */
/*   Updated: 2021/05/18 16:32:11 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

static int	check_doublon(int arg_nb, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < arg_nb)
	{
		j = i + 1;
		while (j < arg_nb)
		{
			if (args[i] == args[j])
			{
				ft_error();
				return (1);
			}
			else
				j++;
		}
		i++;
	}
	return (0);
}

static int	is_digit_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_arg(int arg_nb, char **args, t_stack *a)
{
	int			i;
	long long	nbr;

	i = 1;
	while (i < arg_nb)
	{
		if (!is_digit_str(args[i]))
		{
			nbr = ft_atoi_check(args[i]);
			if (nbr > 2147483647 || nbr < -2147483648)
				return (ft_error());
			a->len++;
		}
		else
			return (ft_error());
		i++;
	}
	if (check_doublon(arg_nb, args))
		return (ft_error());
	return (0);
}

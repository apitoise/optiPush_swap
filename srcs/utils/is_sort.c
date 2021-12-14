/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:41:26 by apitoise          #+#    #+#             */
/*   Updated: 2021/12/14 12:25:14 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

int	is_sort(t_stack *a, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (a->elem[i - 1].nb < a->elem[i].nb)
			i++;
		else
			return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:28:52 by apitoise          #+#    #+#             */
/*   Updated: 2021/05/28 14:07:06 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

void	do_swap(t_stack* stack)
{
	int	copy;

	if (stack->name == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
	copy = stack->elem[0].nb;
	stack->elem[0].nb = stack->elem[1].nb;
	stack->elem[1].nb = copy;
}

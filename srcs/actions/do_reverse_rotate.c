/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:01:07 by apitoise          #+#    #+#             */
/*   Updated: 2021/05/28 14:06:53 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

void	do_reverse_rotate(t_stack *stack)
{
	int	copy;
	int	i;

	if (stack->name == 'a')
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
	i = stack->len - 1;
	copy = stack->elem[i].nb;
	while (i > 0)
	{
		stack->elem[i].nb = stack->elem[i - 1].nb;
		i--;
	}
	stack->elem[0].nb = copy;
}

void	double_reverse_rotate(t_stack *a, t_stack *b)
{
	int	copy;
	int	i;

	ft_putstr_fd("rrr\n", 1);
	i = a->len - 1;
	copy = a->elem[i].nb;
	while (i > 0)
	{
		a->elem[i].nb = a->elem[i - 1].nb;
		i--;
	}
	a->elem[0].nb = copy;
	i = b->len - 1;
	copy = b->elem[i].nb;
	while (i > 0)
	{
		b->elem[i].nb = b->elem[i - 1].nb;
		i--;
	}
	b->elem[0].nb = copy;
}

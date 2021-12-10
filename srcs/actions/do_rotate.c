/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:11:37 by apitoise          #+#    #+#             */
/*   Updated: 2021/05/28 14:06:39 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

void	do_rotate(t_stack *stack)
{
	int	copy;
	int	i;

	stack->action++;
	if (stack->name == 'a')
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
	copy = stack->elem[0].nb;
	i = 0;
	while (i < stack->len - 1)
	{
		stack->elem[i].nb = stack->elem[i + 1].nb;
		i++;
	}
	stack->elem[i].nb = copy;
}

void	double_rotate(t_stack *a, t_stack *b)
{
	int	copy;
	int	i;

	ft_putstr_fd("rr\n", 1);
	copy = a->elem[0].nb;
	i = 0;
	while (i < a->len - 1)
	{
		a->elem[i].nb = a->elem[i + 1].nb;
		i++;
	}
	a->elem[i].nb = copy;
	copy = b->elem[0].nb;
	i = 0;
	while (i < b->len - 1)
	{
		b->elem[i].nb = b->elem[i + 1].nb;
		i++;
	}
	b->elem[i].nb = copy;
}

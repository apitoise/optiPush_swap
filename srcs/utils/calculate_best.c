/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_best.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:18:44 by apitoise          #+#    #+#             */
/*   Updated: 2021/12/09 19:18:44 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

static int	get_min(int min, int rr, int rrr, int* stack_best)
{
	int	best;

	if ((min < rr && min < rrr) || (min == rr && min < rrr))
		best = min;
	else if ((rr < min && rr < rrr) || (rr == rrr && rr < min))
		best = rr;
	else if (rrr < min && rrr < rr)
		best = rrr;
	else
		best = min;
	if (best == min)
		(*stack_best) = MIN;
	else if (best == rr)
		(*stack_best) = RR;
	else if (best == rrr)
		(*stack_best) = RRR;
	return (best);
}

void		calculate_best(t_stack* stack)
{
	int	rr;
	int	rrr;
	int	min;
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->elem[i].rot_min[0] + stack->elem[i].rot_min[3]
		< stack->elem[i].rot_min[1] + stack->elem[i].rot_min[2])
			min = stack->elem[i].rot_min[0] + stack->elem[i].rot_min[3];
		else
			min = stack->elem[i].rot_min[1] + stack->elem[i].rot_min[2];
		rr = stack->elem[i].rot_min[0] + stack->elem[i].rot_min[2];
		rrr = stack->elem[i].rot_min[1] + stack->elem[i].rot_min[3];
		stack->elem[i].best_nb = get_min(min, rr, rrr, &stack->elem[i].best);
		i++;
	}
}

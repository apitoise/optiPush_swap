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

static int	get_min(int min, int rr, int rrr, int* a_best)
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
		(*a_best) = MIN;
	else if (best == rr)
		(*a_best) = RR;
	else if (best == rrr)
		(*a_best) = RRR;
	return (best);
}

void	calculate_best(t_stack* a)
{
	int	rr;
	int	rrr;
	int	min;
	int	i;

	i = 0;
	while (i < a->len)
	{
		if (a->elem[i].rot_min[0] + a->elem[i].rot_min[3]
		< a->elem[i].rot_min[1] + a->elem[i].rot_min[2])
			min = a->elem[i].rot_min[0] + a->elem[i].rot_min[3];
		else
			min = a->elem[i].rot_min[1] + a->elem[i].rot_min[2];
		rr = a->elem[i].rot_min[0] + a->elem[i].rot_min[2];
		rrr = a->elem[i].rot_min[1] + a->elem[i].rot_min[3];
		a->elem[i].best_nb = get_min(min, rr, rrr, &a->elem[i].best);
		i++;
	}
}

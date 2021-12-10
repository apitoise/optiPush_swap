
/*                                                        :::      ::::::::   */
/*   first_part_best.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:42:59 by apitoise          #+#    #+#             */
/*   Updated: 2021/12/10 11:42:59 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

static void	do_min(int* rot_min, t_stack* a, t_stack* b)
{
	if (rot_min[0] + rot_min[3] < rot_min[1] + rot_min[2])
	{
		while (rot_min[0]--)
			do_rotate(a);
		while (rot_min[3]--)
			do_reverse_rotate(b);
	}
	else
	{
		while (rot_min[1]--)
			do_reverse_rotate(a);
		while (rot_min[2]--)
			do_rotate(b);
	}
}

static void	do_rr(int* rot_min, t_stack* a, t_stack* b)
{
	int	nb_double;
	
	if (rot_min[0] < rot_min[2])
	{
		nb_double = rot_min[0];
		while (rot_min[0]--)
			double_rotate(a, b);
		while (rot_min[2]-- - nb_double)
			do_rotate(b);
	}
	else
	{
		nb_double = rot_min[2];
		while (rot_min[2]--)
			double_rotate(a, b);
		while (rot_min[0]-- - nb_double)
			do_rotate(a);
	}
}

static void	do_rrr(int* rot_min, t_stack* a, t_stack* b)
{
	int	nb_double;
	
	if (rot_min[1] < rot_min[3])
	{
		nb_double = rot_min[1];
		while (rot_min[1]--)
			double_reverse_rotate(a, b);
		while (rot_min[3]-- - nb_double)
			do_reverse_rotate(b);
	}
	else
	{
		nb_double = rot_min[3];
		while (rot_min[3]--)
			double_reverse_rotate(a, b);
		while (rot_min[1]-- - nb_double)
			do_reverse_rotate(a);
	}
}

void		exec_best(t_stack* a, t_stack* b, int id)
{
	if (a->elem[id].best == MIN)
		return (do_min(a->elem[id].rot_min, a, b));
	else if (a->elem[id].best == RR)
		return (do_rr(a->elem[id].rot_min, a, b));
	else
		return (do_rrr(a->elem[id].rot_min, a, b));
}

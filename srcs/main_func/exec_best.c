/* ************************************************************************** */
/*                                                                            */
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

static void	do_min(int *rot_min, t_stack *src, t_stack *dst)
{
	if (rot_min[0] + rot_min[3] < rot_min[1] + rot_min[2])
	{
		while (rot_min[0]--)
		{
			if (src->name == 'a')
				do_rotate(src);
			else
				do_rotate(dst);
		}
		while (rot_min[3]--)
		{
			if (src->name == 'a')
				do_reverse_rotate(dst);
			else
				do_reverse_rotate(src);
		}
	}
	else
		min_bis(rot_min, src, dst);
}

static void	do_rr(int *rot_min, t_stack *src, t_stack *dst)
{
	int	nb_double;

	if (rot_min[0] < rot_min[2])
	{
		nb_double = rot_min[0];
		while (rot_min[0]--)
			double_rotate(src, dst);
		while (rot_min[2]-- - nb_double)
		{
			if (src->name == 'a')
				do_rotate(dst);
			else
				do_rotate(src);
		}
	}
	else
		rr_bis(rot_min, src, dst);
}

static void	do_rrr(int *rot_min, t_stack *src, t_stack *dst)
{
	int	nb_double;

	if (rot_min[1] < rot_min[3])
	{
		nb_double = rot_min[1];
		while (rot_min[1]--)
			double_reverse_rotate(src, dst);
		while (rot_min[3]-- - nb_double)
		{
			if (src->name == 'a')
				do_reverse_rotate(dst);
			else
				do_reverse_rotate(src);
		}
	}
	else
		rrr_bis(rot_min, src, dst);
}

void	exec_best(t_stack *src, t_stack *dst, int id)
{
	if (src->elem[id].best == MIN)
		return (do_min(src->elem[id].rot_min, src, dst));
	else if (src->elem[id].best == RR)
		return (do_rr(src->elem[id].rot_min, src, dst));
	else
		return (do_rrr(src->elem[id].rot_min, src, dst));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_best_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:26:54 by apitoise          #+#    #+#             */
/*   Updated: 2021/12/10 17:26:54 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

void	min_bis(int *rot_min, t_stack *src, t_stack *dst)
{
	while (rot_min[1]--)
	{
		if (src->name == 'a')
			do_reverse_rotate(src);
		else
			do_reverse_rotate(dst);
	}
	while (rot_min[2]--)
	{
		if (src->name == 'a')
			do_rotate(dst);
		else
			do_rotate(src);
	}	
}

void	rr_bis(int *rot_min, t_stack *src, t_stack *dst)
{
	int	nb_double;

	nb_double = rot_min[2];
	while (rot_min[2]--)
		double_rotate(src, dst);
	while (rot_min[0]-- - nb_double)
	{
		if (src->name == 'a')
			do_rotate(src);
		else
			do_rotate(dst);
	}
}

void	rrr_bis(int *rot_min, t_stack *src, t_stack *dst)
{
	int	nb_double;

	nb_double = rot_min[3];
	while (rot_min[3]--)
		double_reverse_rotate(src, dst);
	while (rot_min[1]-- - nb_double)
	{
		if (src->name == 'a')
			do_reverse_rotate(src);
		else
			do_reverse_rotate(dst);
	}
}

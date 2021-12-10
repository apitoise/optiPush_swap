/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_rot_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:24:59 by apitoise          #+#    #+#             */
/*   Updated: 2021/12/09 17:24:59 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

static int	find_closer(int nb, t_stack* stack)
{
	int	id;
	
	if (stack->name == 'b')
	{
		id = closer_min(stack, nb);
		if (nb > stack->elem[id].nb)
			return (id);
		else
			return (id_max(stack));
	}
	else
	{
		id = closer_max(stack, nb);
		if (nb < stack->elem[id].nb)
			return (id);
		else
			return (id_min(stack));
	}
}

void		new_rot_min(t_stack* a, t_stack* b)
{
	int	i;
	int	closer;

	i = 0;
	while (i < b->len)
	{
		b->elem[i].rot_min[ROTATE_B] = i;
		b->elem[i].rot_min[R_ROTATE_B] = b->len - i;
		i++;
	}
	i = 0;
	while (i < a->len)
	{
		closer = find_closer(a->elem[i].nb, b);
		a->elem[i].rot_min[ROTATE_A] = i;
		a->elem[i].rot_min[R_ROTATE_A] = a->len - i;
		a->elem[i].rot_min[ROTATE_B] = b->elem[closer].rot_min[ROTATE_B];
		a->elem[i].rot_min[R_ROTATE_B] = b->elem[closer].rot_min[R_ROTATE_B];
		i++;
	}
	i = 0;
	while (i < b->len)
	{
		closer = find_closer(b->elem[i].nb, a);
		b->elem[i].rot_min[ROTATE_A] = a->elem[closer].rot_min[ROTATE_A];
		b->elem[i].rot_min[R_ROTATE_A] = a->elem[closer].rot_min[R_ROTATE_A];
		i++;
	}
	calculate_best(a);
	calculate_best(b);
}

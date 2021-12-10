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

static int	id_min(t_stack *stack, int nb)
{
	int	i;
	int	id;
	int	min;

	i = 0;
	min = stack->elem[0].nb;
	id = 0;
	while (i < stack->len)
	{
		if (stack->elem[i].nb < min)
		{
			min = stack->elem[i].nb;
			id = i;
		}
		i++;
	}
	i = 0;
	while (i < stack->len)
	{
		if (stack->elem[i].nb > min && stack->elem[i].nb < nb)
		{
			min = stack->elem[i].nb;
			id = i;
		}
		i++;
	}
	return (id);
}

static int	id_max(t_stack* stack)
{
	int	i;
	int	max;
	int	id;

	i = 0;
	max = stack->elem[0].nb;
	id = 0;
	while (i < stack->len)
	{
		if (max < stack->elem[i].nb)
		{
			max = stack->elem[i].nb;
			id = i;
		}
		i++;
	}
	return (id);
}

int		find_closer(int nb, t_stack* b)
{
	int	id;

	id = id_min(b, nb);
	if (nb > b->elem[id].nb)
		return (id);
	else
		return (id_max(b));
}

void	new_rot_min(t_stack* a, t_stack* b)
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
	calculate_best(a);
}

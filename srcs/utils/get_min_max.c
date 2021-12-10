/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:33:11 by apitoise          #+#    #+#             */
/*   Updated: 2021/12/10 12:33:11 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

int	id_max(t_stack* stack)
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

int	id_min(t_stack* stack)
{
	int	i;
	int	min;
	int	id;

	i = 0;
	min = stack->elem[0].nb;
	id = 0;
	while (i < stack->len)
	{
		if (min > stack->elem[i].nb)
		{
			min = stack->elem[i].nb;
			id = i;
		}
		i++;
	}
	return (id);
}

int	closer_min(t_stack *stack, int nb)
{
	int	i;
	int	id;
	int	min;

	i = 0;
	min = stack->elem[id_min(stack)].nb;
	id = id_min(stack);
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

int	closer_max(t_stack* stack, int nb)
{
	int	i;
	int	id;
	int	max;

	i = 0;
	max = stack->elem[id_max(stack)].nb;
	id = id_max(stack);
	i = 0;
	while (i < stack->len)
	{
		if (stack->elem[i].nb < max && stack->elem[i].nb > nb)
		{
			max = stack->elem[i].nb;
			id = i;
		}
		i++;
	}
	return (id);
}

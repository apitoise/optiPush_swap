/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:14:45 by apitoise          #+#    #+#             */
/*   Updated: 2021/12/09 17:14:45 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

static void	print_piles(t_stack* a, t_stack* b, int len)
{
	printf("\n");
	for(int i = 0; i < len; i++) {
		printf("[%d] {%d, %d, %d, %d} best: %d best_nbr: %d | [%d]\n", a->elem[i].nb, a->elem[i].rot_min[0], a->elem[i].rot_min[1], a->elem[i].rot_min[2], a->elem[i].rot_min[3], a->elem[i].best, a->elem[i].best_nb, b->elem[i].nb);}
}
/*`
static void	exec_best(t_stack* a, t_stack* b, int id)
{
	int	less;

	if (a->elem[id].best == MIN)
	{
		if (a->elem[id].rot_min[0] + a->elem[id].rot_min[3]
			< a->elem[id].rot_min[1] + a->elem[id].rot_min[2])
		{
			while (a->elem[id].rot_min[0]--)
				do_rotate(a);
			while (a->elem[id].rot_min[3]--)
				do_reverse_rotate(b);
		}
		else
		{
			while (a->elem[id].rot_min[1]--)
				do_reverse_rotate(a);
			while (a->elem[id].rot_min[2]--)
				do_rotate(b);
		}
	}
	else if (a->elem[id].best == RR)
	{
		if (a->elem[id].rot_min[0] < a->elem[id].rot_min[2])
		{
			less = a->elem[id].rot_min[0];
			while (a->elem[id].rot_min[0]--)
				double_rotate(a, b);
			while (a->elem[id].rot_min[2]-- - less)
				do_rotate(b);
		}
		else
		{
			less = a->elem[id].rot_min[2];
			while (a->elem[id].rot_min[2]--)
				double_rotate(a, b);
			while (a->elem[id].rot_min[0]-- - less)
				do_rotate(a);
		}
	}
	else
	{
		if (a->elem[id].rot_min[1] < a->elem[id].rot_min[3])
		{
			less = a->elem[id].rot_min[1];
			while (a->elem[id].rot_min[1]--)
				double_reverse_rotate(a, b);
			while (a->elem[id].rot_min[3]-- - less)
				do_reverse_rotate(b);
		}
		else
		{
			less = a->elem[id].rot_min[3];
			while (a->elem[id].rot_min[3]--)
				double_reverse_rotate(a, b);
			while (a->elem[id].rot_min[1]-- - less)
				do_reverse_rotate(a);
		}
	}
}
*/
static void	find_best(t_stack* a, t_stack* b)
{
	int	i;
	int	opt;
	int	id;

	i = 0;
	opt = a->elem[0].best_nb;
	id = 0;
	while (i < a->len)
	{
		if (a->elem[i].best_nb < opt)
		{
			opt = a->elem[i].best_nb;
			id = i;
		}
		i++;
	}
	return (exec_best(a, b, id));
}

void	do_algo(t_stack* a, t_stack* b)
{
	do_push(a, b);
	do_push(a, b);
	new_rot_min(a, b);
	while (a->len > 2)
	{
		find_best(a, b);
		do_push(a, b);
		new_rot_min(a, b);
	}
	print_piles(a, b, b->len);
}

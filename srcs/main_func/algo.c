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

/*static void	print_piles(t_stack* a, t_stack* b, int len)
{
	printf("\n");
	for(int i = 0; i < len; i++) {
		printf("[%d] {%d, %d, %d, %d} best: %d best_nbr: %d | [%d] {%d, %d, %d, %d} best: %d best_nbr: %d\n", a->elem[i].nb, a->elem[i].rot_min[0], a->elem[i].rot_min[1], a->elem[i].rot_min[2], a->elem[i].rot_min[3], a->elem[i].best, a->elem[i].best_nb, b->elem[i].nb, b->elem[i].rot_min[0], b->elem[i].rot_min[1], b->elem[i].rot_min[2], b->elem[i].rot_min[3], b->elem[i].best, b->elem[i].best_nb);}
}
*/
static void	put_min_on_top(t_stack* stack)
{
	int	opt;

	if (stack->elem[id_min(stack)].rot_min[0]
	< stack->elem[id_min(stack)].rot_min[1])
	{
		opt = stack->elem[id_min(stack)].rot_min[0];
		while (opt--)
			do_rotate(stack);
	}
	else
	{
		opt = stack->elem[id_min(stack)].rot_min[1];
		while (opt--)
			do_reverse_rotate(stack);
	}
}

static void	find_best(t_stack* src, t_stack* dst)
{
	int	i;
	int	opt;
	int	id;

	i = 0;
	opt = src->elem[0].best_nb;
	id = 0;
	while (i < src->len)
	{
		if (src->elem[i].best_nb < opt)
		{
			opt = src->elem[i].best_nb;
			id = i;
		}
		i++;
	}
	return (exec_best(src, dst, id));
}

void	do_algo(t_stack* a, t_stack* b)
{
	int	len;

	len = a->len;
	do_push(a, b);
	do_push(a, b);
	new_rot_min(a, b);
	while (a->len > 2)
	{
		find_best(a, b);
		do_push(a, b);
		new_rot_min(a, b);
	}
	while (a->len < len)
	{
		find_best(b, a);
		do_push(b, a);
		new_rot_min(a, b);
	}
	put_min_on_top(a);
//	print_piles(a, b, len);
}

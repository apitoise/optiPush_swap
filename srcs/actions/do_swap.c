/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:28:52 by apitoise          #+#    #+#             */
/*   Updated: 2021/05/28 14:07:06 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

void	do_swap(t_pile *pile, char c)
{
	int	copy;

	pile->actions++;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
	copy = pile->nbr[0];
	pile->nbr[0] = pile->nbr[1];
	pile->nbr[1] = copy;
	int i = 0;
	while (i < pile->len)
	{
		printf("[%d]", pile->nbr[i]);
		i++;
	}
	printf("\n");
}

void	double_swap(t_pile *a, t_pile *b)
{
	int	copy;

	ft_putstr_fd("ss     ", 1);
	copy = a->nbr[0];
	a->nbr[0] = a->nbr[1];
	a->nbr[1] = copy;
	copy = b->nbr[0];
	b->nbr[0] = b->nbr[1];
	b->nbr[1] = copy;
	int i = 0;
	while (i < a->len)
	{
		printf("[%d]", a->nbr[i]);
		i++;
	}
	printf(" || ");
	i = 0;
	while (i < b->len)
	{
		printf("[%d]", b->nbr[i]);
		i++;
	}
	printf("\n");

}

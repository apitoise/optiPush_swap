/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:21:59 by apitoise          #+#    #+#             */
/*   Updated: 2021/05/28 14:02:12 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

void	do_push(t_stack* src, t_stack* dst)
{
	int	i;
	
	if (src->name == 'a')
		ft_putstr_fd("pb\n", 1);
	else
		ft_putstr_fd("pa\n", 1);
	if (dst->len)
	{
		i = dst->len - 1;
		while (i >= 0)
		{
			dst->elem[i + 1].nb = dst->elem[i].nb;
			i--;
		}
	}
	dst->elem[0].nb = src->elem[0].nb;
	src->len--;
	dst->len++;
	i = 0;
	while (i < src->len)
	{
		src->elem[i].nb = src->elem[i + 1].nb;
		i++;
	}
}

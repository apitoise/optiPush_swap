/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:16:46 by apitoise          #+#    #+#             */
/*   Updated: 2021/05/19 15:34:07 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

int	clean_exit(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
//	free(a->elem);
//	free(b->elem);
	exit(EXIT_SUCCESS);
	return (0);
}

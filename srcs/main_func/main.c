/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:08:51 by apitoise          #+#    #+#             */
/*   Updated: 2021/12/09 16:08:51 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../libft/libft.h"

static int	init_stack(t_stack *a, t_stack *b, char **args)
{
	int	i;

	a->elem = (t_elem *)malloc(sizeof(t_elem) * a->len);
	if (!a->elem)
		return (0);
	b->elem = (t_elem *)malloc(sizeof(t_elem) * a->len);
	if (!b->elem)
		return (0);
	i = 0;
	while (i < a->len)
	{
		a->elem[i].nb = ft_atoi(args[i + 1]);
		a->elem[i].rot_min[ROTATE_A] = i;
		a->elem[i].rot_min[R_ROTATE_A] = a->len - i;
		a->elem[i].rot_min[ROTATE_B] = 0;
		a->elem[i].rot_min[R_ROTATE_B] = 0;
		i++;
	}
	return (1);
}

static void	push_swap(t_stack *a, t_stack *b)
{
	if (a->len == 1)
		return ;
	else if (a->len == 2)
		two_args(a);
	else if (a->len == 3)
		three_args(a);
	else
		do_algo(a, b);
}

static char	**one_param(int *ac, char **av, int *i)
{
	char	*tmp;

	av[0] = ft_strjoin(av[0], " ");
	tmp = ft_strjoin(av[0], av[1]);
	free(av[0]);
	av = ft_split(tmp, ' ');
	free(tmp);
	(*ac) = 1;
	(*i) = 1;
	while (av[(*i)++])
		(*ac)++;
	return (av);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		i;

	if (ac == 2)
		av = one_param(&ac, av, &i);
	a.len = 0;
	b.len = 0;
	a.name = 'a';
	b.name = 'b';
	if (ac == 1)
		return (0);
	if (check_arg(ac, av, &a))
		return (0);
	if (!(init_stack(&a, &b, av)))
		return (0);
	push_swap(&a, &b);
	if (!i)
	{
		i = -1;
		while (av[++i])
			free(av[i]);
		free(av);
	}
	return (clean_exit(&a, &b));
}

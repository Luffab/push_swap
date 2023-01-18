/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:04:58 by luffab            #+#    #+#             */
/*   Updated: 2021/10/16 17:22:14 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_choose_tri(t_pushswap *p)
{
	ft_simplify_int(p);
	if (p->a_size == 4)
		ft_tri_4_nb(p);
	else if (p->a_size == 3)
		ft_tri_3_nb(p);
	else if (p->a_size == 2)
		ft_tri_2_nb(p);
	else if (p->a_size == 5)
		ft_tri_5_nb(p);
	else
		ft_radix_sort(p);
}

int	ft_verify_pile(t_pushswap *p, int ac, char **split, char **av)
{
	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		p->a_size = ft_count_arg(split);
		ft_putnumber(split, p, 1);
		if (!ft_verify_num_split(split))
		{
			ft_free_split(split);
			return (0);
		}
		ft_free_split(split);
	}
	else
	{
		p->a_size = ac - 1;
		ft_putnumber(av, p, 0);
		if (!ft_verify_num_av(av))
			return (0);
	}
	return (1);
}

int	ft_verify_long(long *tab, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (tab[i] > 2147483647 || tab[i] < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

void	ft_free(t_pushswap *p)
{
	if (p->pile_a)
		free(p->pile_a);
	if (p->pile_b)
		free(p->pile_b);
	if (p->temp_pile_a)
		free(p->temp_pile_a);
	if (p->temp)
		free(p->temp);
	if (p->check_pile)
		free(p->check_pile);
	free(p);
}

int	main(int ac, char **av)
{
	t_pushswap	*p;
	char		**split;

	p = malloc(sizeof(t_pushswap));
	split = NULL;
	ft_init(p);
	if (ac == 1)
	{
		ft_free(p);
		return (0);
	}
	else
	{
		if (!ft_if_main(p, ac, split, av))
			return (0);
		ft_choose_tri(p);
		free(p->pile_a);
		free(p->pile_b);
		free(p);
	}
	return (0);
}

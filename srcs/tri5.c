/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:37:52 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/16 18:06:10 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tri_5_nb2(t_pushswap *p)
{
	ft_push_a_in_temp(p);
	ft_tri_3_nb(p);
	if (p->pile_b[0] < p->pile_b[1])
	{
		ft_putstr_fd("sb\n", 1);
		ft_sb(p);
	}
	ft_pa(p);
	ft_putstr_fd("pa\n", 1);
	p->nb_in_pb--;
	ft_pa(p);
	ft_putstr_fd("pa\n", 1);
	ft_ra(p);
	ft_putstr_fd("ra\n", 1);
}

void	ft_if_condition_5(t_pushswap *p, int j)
{
	if (p->pile_a[j] == 0 || p->pile_a[j] == 4)
	{
		p->nb_in_pb++;
		ft_pb(p, j);
		ft_putstr_fd("pb\n", 1);
		ft_ra(p);
	}
	else if (p->nb_in_pb != 1)
	{
		while (p->pile_a[0] == -1)
			ft_ra(p);
		ft_ra(p);
		ft_putstr_fd("ra\n", 1);
	}
}

void	ft_tri_5_nb(t_pushswap *p)
{
	int	i;
	int	j;

	i = -1;
	p->nb_in_pb = -1;
	while (++i < p->a_size)
	{
		j = 0;
		ft_push_a_in_temp(p);
		while (p->pile_a[j] == -1)
			j++;
		ft_if_condition_5(p, j);
	}
	ft_tri_5_nb2(p);
}

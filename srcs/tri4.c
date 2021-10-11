/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:24:21 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/11 14:29:27 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_pushswap *p)
{
	int	temp;

	temp = p->pile_b[0];
	p->pile_b[0] = p->pile_b[1];
	p->pile_b[1] = temp;
}

void	ft_tri_4_nb2(t_pushswap *p)
{
	int	i;

	i = 2;
	ft_push_a_in_temp(p);
	if (p->pile_a[i] > p->pile_a[i + 1])
	{
		ft_putstr_fd("sa\n", 1);
		ft_sa(p, i);
	}
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

void	ft_if_condition_4(t_pushswap *p, int j)
{
	if (p->pile_a[j] == 0 || p->pile_a[j] == 3)
	{
		p->nb_in_pb++;
		ft_pb(p, j);
		ft_putstr_fd("pb\n", 1);
		ft_ra(p);
	}
	else
	{
		while (p->pile_a[0] == -1)
			ft_ra(p);
		ft_ra(p);
		ft_putstr_fd("ra\n", 1);
	}
}

void	ft_tri_4_nb(t_pushswap *p)
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
		ft_if_condition_4(p, j);
	}
	ft_tri_4_nb2(p);
}

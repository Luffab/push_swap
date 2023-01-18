/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri2_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:41:10 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/16 18:04:06 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_pushswap *p, int i)
{
	int	temp;

	temp = p->pile_a[i];
	p->pile_a[i] = p->pile_a[i + 1];
	p->pile_a[i + 1] = temp;
}

void	ft_rra(t_pushswap *p)
{
	int	i;
	int	temp;
	int	last_temp;

	i = p->a_size - 2;
	temp = 0;
	last_temp = p->pile_a[p->a_size - 1];
	while (i >= 0)
	{
		temp = p->pile_a[i];
		p->pile_a[i + 1] = temp;
		i--;
	}
	p->pile_a[0] = last_temp;
}

void	ft_tri_2_nb(t_pushswap *p)
{
	if (p->pile_a[0] > p->pile_a[1])
	{
		ft_sa(p, 0);
		ft_putstr_fd("sa\n", 1);
	}
}

void	ft_tri_3_nb2(t_pushswap *p, int i)
{
	if ((p->pile_a[i + 2] > p->pile_a[i + 1])
		&& (p->pile_a[i + 2] < p->pile_a[i]))
	{
		ft_ra(p);
		ft_putstr_fd("ra\n", 1);
	}
	else if ((p->pile_a[i + 2] < p->pile_a[i + 1])
		&& (p->pile_a[i + 2] > p->pile_a[i]))
	{
		ft_sa(p, i);
		ft_ra(p);
		ft_putstr_fd("sa\n", 1);
		ft_putstr_fd("ra\n", 1);
	}
	else if ((p->pile_a[i] > p->pile_a[i + 2])
		&& (p->pile_a[i] < p->pile_a[i + 1]))
	{
		ft_rra(p);
		ft_putstr_fd("rra\n", 1);
	}
}

void	ft_tri_3_nb(t_pushswap *p)
{
	int	i;

	i = 0;
	while (p->pile_a[i] == -1)
		i++;
	if ((p->pile_a[i] > p->pile_a[i + 1])
		&& (p->pile_a[i + 1] < p->pile_a[i + 2]))
	{
		ft_sa(p, i);
		ft_putstr_fd("sa\n", 1);
	}
	else if ((p->pile_a[i] > p->pile_a[i + 1])
		&& (p->pile_a[i + 1] > p->pile_a[i + 2]))
	{
		ft_sa(p, i);
		ft_rra(p);
		ft_putstr_fd("sa\n", 1);
		ft_putstr_fd("rra\n", 1);
	}
	ft_tri_3_nb2(p, i);
}

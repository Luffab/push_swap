/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 00:10:55 by luffab            #+#    #+#             */
/*   Updated: 2021/10/11 17:07:32 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_info(t_pushswap *p)
{
	p->big_num = p->a_size - 1;
	p->big_bits = 0;
	while ((p->big_num >> p->big_bits) != 0)
		p->big_bits++;
}

void	ft_boucle_j(t_pushswap *p, int num, int i)
{
	int	j;
	int	temp;

	j = -1;
	while (++j < p->a_size)
	{
		ft_push_a_in_temp(p);
		temp = 0;
		while (p->pile_a[temp] == -1)
			temp++;
		num = p->pile_a[temp];
		if (((num >> i) & 1) == 1)
		{
			while (p->pile_a[0] == -1)
				ft_ra(p);
			ft_putstr_fd("ra\n", 1);
			ft_ra(p);
		}
		else
		{
			p->nb_in_pb++;
			ft_putstr_fd("pb\n", 1);
			ft_pb(p, temp);
		}
	}
}

void	ft_radix_sort(t_pushswap *p)
{
	int	i;
	int	num;

	i = -1;
	num = 0;
	p->nb_in_pb = -1;
	ft_get_info(p);
	while (++i < p->big_bits)
	{
		ft_boucle_j(p, num, i);
		ft_push_a_in_temp(p);
		while (p->nb_in_pb >= 0)
		{
			ft_putstr_fd("pa\n", 1);
			ft_pa(p);
			p->nb_in_pb--;
		}
	}
}

void	ft_init(t_pushswap *p)
{
	p->pile_a = NULL;
	p->pile_b = NULL;
	p->check_pile = NULL;
	p->temp_pile_a = NULL;
	p->temp = NULL;
}

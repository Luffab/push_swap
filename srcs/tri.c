/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:43:12 by luffab            #+#    #+#             */
/*   Updated: 2021/11/28 23:35:12 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_pushswap *p)
{
	int	i;
	int	temp;
	int	last_temp;

	i = 1;
	temp = 0;
	last_temp = p->pile_a[0];
	while (i < p->a_size)
	{
		temp = p->pile_a[i];
		p->pile_a[i - 1] = temp;
		i++;
	}
	p->pile_a[i - 1] = last_temp;
}

void	ft_pb(t_pushswap *p, int temp)
{
	p->pile_b[p->nb_in_pb] = p->pile_a[temp];
	p->pile_a[temp] = -1;
}

void	ft_temp_equal_pa(t_pushswap *p)
{
	int	i;

	i = 0;
	while (i < p->a_size)
	{
		p->pile_a[i] = p->temp_pile_a[i];
		i++;
	}
}

void	ft_push_a_in_temp(t_pushswap *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	p->temp_pile_a = (int *)malloc(sizeof(int) * p->a_size);
	while (i <= p->nb_in_pb)
	{
		p->temp_pile_a[i] = -1;
		i++;
	}
	while (j < p->a_size)
	{
		if (p->pile_a[j] != -1)
		{
			p->temp_pile_a[i] = p->pile_a[j];
			i++;
		}
		j++;
	}
	ft_temp_equal_pa(p);
	free(p->temp_pile_a);
}

void	ft_pa(t_pushswap *p)
{
	p->pile_a[p->nb_in_pb] = p->pile_b[p->nb_in_pb];
}

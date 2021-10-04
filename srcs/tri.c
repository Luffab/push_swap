/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luffab <luffab@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:43:12 by luffab            #+#    #+#             */
/*   Updated: 2021/09/24 03:02:17 by luffab           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_ra(t_pushswap *p)
{
	int i;
	int temp;
	int last_temp;

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

void ft_pb(t_pushswap *p, int j)
{
	p->pile_b[p->nb_in_pb] = p->pile_a[0];
	p->pile_a[0] = -1;
}




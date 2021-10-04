/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luffab <luffab@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 00:10:55 by luffab            #+#    #+#             */
/*   Updated: 2021/09/24 02:26:40 by luffab           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_get_info(t_pushswap *p)
{
	p->big_num = p->a_size - 1;
	p->big_bits = 0;
	while ((p->big_num >> p->big_bits) != 0)
		p->big_bits++;
}

void ft_radix_sort(t_pushswap *p)
{
	int i;
	int j;
	int num;

	i = 0;
	ft_get_info(p);
	while (i < p->big_bits)
	{
		j = 0;
		while (j < p->a_size)
		{
			num = p->pile_a[0];
			if ((num >> i) & 1 == 1)
				ft_ra(p);
			else
			{
				p->nb_in_pb++;
				//pb();
			}
			j++;
		}
		while (p->pile_b[0])
		{
			p->nb_in_pb--;
			//pa();
		}
		i++;
	}
}
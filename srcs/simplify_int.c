/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luffab <luffab@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:41:31 by luffab            #+#    #+#             */
/*   Updated: 2021/09/22 21:29:24 by luffab           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_search_in_temp(t_pushswap *p, int ind)
{
	int i;

	i = 0;
	//dprintf(1, "%d\n", p->size_temp);
	while (i < p->size_temp)
	{
		if (p->temp[i] == ind)
			return (0);
		i++;
	}
	return (1);
}

void ft_increment_and_assign(t_pushswap *p, int j)
{
	p->temp[p->temp_ind] = j;
	p->pile_a[j] = p->ordre;
	p->ordre++;
	p->temp_ind++;
	p->size_temp++;
}

void ft_search_min(t_pushswap *p)
{
	int i;
	int j;
	int temp_i;
	int small;

	i = 0;
	j = 0;
	while (!ft_search_in_temp(p, i))
		i++;
	temp_i = i;
	small = p->temp_pile_a[i];
	i = 1;
	while (i < p->a_size)
	{
		if (p->temp_pile_a[i] < small && ft_search_in_temp(p, i))
		{
			small = p->temp_pile_a[i];
			j = i;
		}
		i++;
	}
	if (small == p->temp_pile_a[temp_i])
		j = temp_i;
	ft_increment_and_assign(p, j);
}

void ft_simplify_int(t_pushswap *p)
{
	int i;

	i = 0;
	p->ordre = 0;
	p->temp_ind = 0;
	p->temp = (int*)malloc(sizeof(int) * (p->a_size));
	p->pile_a = (int*)malloc(sizeof(int) * (p->a_size));
	p->size_temp = 0;
	while (i < p->a_size)
	{
		ft_search_min(p);
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:59:00 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/16 18:06:39 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verify_num_av(char **av)
{
	int	i;
	int	z;
	int	j;

	i = 0;
	while (av[++i])
	{
		z = -1;
		j = 0;
		while (av[i][++z])
		{
			if (av[i][z] == '+' || av[i][z] == '-')
			{
				z++;
				j++;
			}
			if (((av[i][z] < '0' || av[i][z] > '9') || j > 1))
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
		}
	}
	return (1);
}

void	ft_putnumber(char **av, t_pushswap *p, int nb)
{
	int	i;
	int	j;

	p->check_pile = (long *)malloc(sizeof(long) * p->a_size);
	if (nb == 0)
		i = 1;
	else
		i = 0;
	j = 0;
	while (av[i])
	{
		p->check_pile[j] = ft_atoi(av[i]);
		j++;
		i++;
	}
}

int	ft_count_arg(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_is_sort(long *tab, int nb)
{
	int	i;

	i = 0;
	if (nb == 1)
		return (1);
	while (i + 1 < nb)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_double(long *tab, int nb)
{
	int	i;
	int	j;

	i = 0;
	if (nb == 1)
		return (1);
	while (i + 1 < nb)
	{
		j = 0;
		while (j < nb)
		{
			if (j == i)
				j++;
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

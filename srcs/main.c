/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luffab <luffab@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:04:58 by luffab            #+#    #+#             */
/*   Updated: 2021/09/23 00:17:10 by luffab           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_verify_num(char **av)
{
	int i;
	int z;
	int j;

	i = 0;
	while (av[++i])
	{
		z = 0;
		j = 0;
		while (av[i][z])
		{
			if (av[i][z] == '+' || av[i][z] == '-')
			{
				z++;
				j++;
			}
			if ((av[i][z] < '0' || av[i][z] > '9') || j > 1)
			{
				ft_putstr_fd("Error\nMauvais argument", 1);
				return(0);
			}
			z++;
		}
	}
	return (1);
}

void ft_putnumber(int ac, char **av, t_pushswap *p)
{
	int i;
	int j;

	p->temp_pile_a = malloc(sizeof(int) * ac - 1);
	i = 1;
	j = 0;
	while (av[i])
	{
		p->temp_pile_a[j] = ft_atoi(av[i]);
		j++;
		i++;
	}
}

int main(int ac, char **av)
{
	t_pushswap *p;

	p = malloc(sizeof(t_pushswap));
	if (ac == 1)
	{
		ft_putstr_fd("Error\nPas assez d'arguments", 1);
		return (0);
	}
	else
	{
		if (!ft_verify_num(av))
			return (0);
		else
		{
			p->a_size = ac - 1;
			ft_putnumber(ac, av, p);
			ft_simplify_int(p);
		}
	}
}


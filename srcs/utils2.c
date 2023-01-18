/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:51:31 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/16 17:11:52 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_if_main(t_pushswap *p, int ac, char **split, char **av)
{
	if (!ft_verify_pile(p, ac, split, av))
	{
		ft_free(p);
		return (0);
	}
	if (!ft_check_double(p->check_pile, p->a_size)
		|| !ft_verify_long(p->check_pile, p->a_size))
	{
		ft_free(p);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (ft_is_sort(p->check_pile, p->a_size))
	{
		ft_free(p);
		return (0);
	}
	return (1);
}

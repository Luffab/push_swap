/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:18:21 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/11 18:18:24 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct s_pushswap
{
	long	*check_pile;
	int		*temp_pile_a;
	int		*temp;
	int		*pile_a;
	int		*pile_b;
	int		a_size;
	int		temp_ind;
	int		ordre;
	int		size_temp;
	int		big_num;
	int		big_bits;
	int		nb_in_pb;
}				t_pushswap;

void	ft_simplify_int(t_pushswap *p);
void	ft_ra(t_pushswap *p);
void	ft_pb(t_pushswap *p, int temp);
void	ft_push_a_in_temp(t_pushswap *p);
void	ft_pa(t_pushswap *p);
void	ft_radix_sort(t_pushswap *p);
int		ft_is_sort(long *tab, int nb);
void	ft_tri_3_nb(t_pushswap *p);
void	ft_sa(t_pushswap *p, int i);
void	ft_tri_4_nb(t_pushswap *p);
void	ft_tri_2_nb(t_pushswap *p);
void	ft_tri_5_nb(t_pushswap *p);
void	ft_sb(t_pushswap *p);
int		ft_verify_num_av(char **av);
int		ft_verify_num_split(char **split);
void	ft_putnumber(char **av, t_pushswap *p, int nb);
int		ft_count_arg(char **str);
int		ft_check_double(long *tab, int nb);
void	ft_init(t_pushswap *p);
void	ft_free_split(char **split);
int		ft_verify_pile(t_pushswap *p, int ac, char **split, char **av);
int		ft_if_main(t_pushswap *p, int ac, char **split, char **av);
int		ft_verify_long(long *tab, int nb);
void	ft_free(t_pushswap *p);

#endif
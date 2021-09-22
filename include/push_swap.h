#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct	s_pushswap
{
	int *temp_pile_a;
	int	*temp;
	int	*pile_a;
	int *pile_b;
	int	a_size;
	int temp_ind;
	int ordre;
	int	size_temp;
}				t_pushswap;

void ft_simplify_int(t_pushswap *p);

#endif
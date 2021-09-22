/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstclear_bonus.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 14:46:13 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/19 02:14:11 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(v_list **lst, void (*del)(void *))
{
	v_list *cour;

	cour = *lst;
	while (cour)
	{
		del(cour->content);
		free(cour);
		cour = cour->next;
	}
	*lst = NULL;
}

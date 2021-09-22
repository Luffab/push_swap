/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 15:24:46 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 20:15:20 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

v_list		*ft_lstmap(v_list *lst, void *(*f)(void *))
{
	v_list	*cour;
	v_list	*deb;

	if (!(cour = malloc(sizeof(v_list))))
		return (NULL);
	deb = cour;
	while (lst)
	{
		if (lst->content)
			cour->content = f(lst->content);
		if (lst->next)
		{
			if (!(cour->next = malloc(sizeof(v_list))))
				return (NULL);
			cour = cour->next;
		}
		else
			cour->next = NULL;
		lst = lst->next;
	}
	return (deb);
}

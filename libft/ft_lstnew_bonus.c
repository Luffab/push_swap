/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 12:03:13 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 20:14:56 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

v_list	*ft_lstnew(void *content)
{
	v_list *new;

	new = malloc(sizeof(v_list));
	new->content = content;
	new->next = NULL;
	return (new);
}

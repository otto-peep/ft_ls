/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 19:01:30 by pconin            #+#    #+#             */
/*   Updated: 2015/12/13 15:27:10 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*temp;
	t_list	*chain;

	newlist = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	newlist = f(lst);
	temp = newlist;
	lst = lst->next;
	while (lst)
	{
		chain = f(lst);
		if (chain == NULL)
			return (NULL);
		temp->next = chain;
		temp = temp->next;
		lst = lst->next;
	}
	return (newlist);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:20:38 by pconin            #+#    #+#             */
/*   Updated: 2015/12/24 21:42:17 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list	*balst;

	balst = *alst;
	if (alst && new)
	{
		while (balst)
			balst = balst->next;
		balst->next = new;
		new->next = NULL;
	}
}

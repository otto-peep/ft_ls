/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 22:46:30 by pconin            #+#    #+#             */
/*   Updated: 2016/08/24 17:57:55 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_sizecmp(t_fil *cur, t_fil *new)
{
	if (cur->size < new->size || (cur->size == new->size &&
				ft_strcmp(cur->name, new->name) > 0))
		return (1);
	else
		return (0);
}

void	tri_size(t_fil **head, t_fil *new)
{
	t_fil *maillon;
	t_fil *pre;

	maillon = *head;
	pre = NULL;
	if (ft_sizecmp(maillon, new) > 0)
		insert_list(head, NULL, &new, 1);
	else
	{
		while (maillon->next)
		{
			if (ft_sizecmp(maillon, new) > 0)
			{
				insert_list(&maillon, pre, &new, 0);
				return ;
			}
			pre = maillon;
			maillon = maillon->next;
		}
		if (ft_sizecmp(maillon, new) > 0)
			insert_list(&maillon, pre, &new, 0);
		else
			maillon->next = new;
	}
}

void	no_sort(t_fil **head, t_fil *new)
{
	t_fil *maillon;

	maillon = *head;
	while (maillon->next)
		maillon = maillon->next;
	maillon->next = new;
	new->next = NULL;
}

void	ft_priority(t_mem *s)
{
	if (s->s == 1)
		s->f_sort = &(tri_size);
	if (s->t == 1)
		s->f_sort = &(tri_date);
	if (s->f == 1)
	{
		s->a = 1;
		s->f_sort = &(no_sort);
	}
	if (s->n == 1 || s->o == 1)
		s->l = 1;
}

int		ft_extract(t_mem *s, t_fil **list, char *str)
{
	t_fil	*mxt;

	mxt = *list;
	while (ft_strcmp(mxt->name, str) && mxt->next)
		mxt = mxt->next;
	if (ft_strcmp(mxt->name, str) == 0)
	{
		mxt->next = NULL;
		*list = mxt;
		return (1);
	}
	else
	{
		return (0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:22:33 by pconin            #+#    #+#             */
/*   Updated: 2016/08/20 11:43:26 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flag_r(t_fil **begin_list)
{
	t_fil	*prev;
	t_fil	*current;
	t_fil	*next;

	prev = NULL;
	current = *begin_list;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}

int		size_list(t_fil *begin_list)
{
	int count;

	count = 0;
	while (begin_list->next)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

void	insert_list(t_fil **begin_list, t_fil *maillon, t_fil **newlist, int bool)
{
	t_fil *tmp;

	tmp = NULL;
	if (bool == 1)
	{
		(*newlist)->next = *begin_list;
		*begin_list = *newlist;
		return ;
	}
	else
	{
		tmp = *begin_list;
		maillon->next = *newlist;
		(*newlist)->next = tmp;
	}
}

int		ft_timecmp(t_fil *cur, t_fil *new)
{
	if (cur->time_s < new->time_s || (cur->time_s == new->time_s && (
		cur->nanotime < new->nanotime || (cur->nanotime == new->nanotime && 
			ft_strcmp(cur->name, new->name) > 0))))
		return (1);
	else
		return (0);
}

void	tri_ascii(t_fil **head, t_fil *new)
{
	t_fil	*maillon;
	t_fil	*pre;

	maillon = *head;
	pre = NULL;
	if (ft_strcmp(maillon->name, new->name) > 0)
		insert_list(head, NULL, &new, 1);
	else
	{
		while (maillon->next)
		{
			if (ft_strcmp(maillon->name, new->name) > 0)
			{
				insert_list(&maillon, pre, &new, 0);
				return;
			}
			pre = maillon;
			maillon = maillon->next;
		}
		if (ft_strcmp(maillon->name, new->name) > 0)
			insert_list(&maillon, pre, &new, 0);
		else
			maillon->next = new;
	}
}


void	tri_date(t_fil **head, t_fil *new)
{
	t_fil	*cur;
	t_fil	*pre;

	cur = *head;
	pre = NULL;
	if (ft_timecmp(cur, new) == 1)
	{
		insert_list(head, NULL, &new, 1);
		return;
	}
	while (cur->next)
	{
		if (ft_timecmp(cur, new))
		{
			insert_list(&cur, pre, &new, 0);
			return;
		}
		pre = cur;
		cur = cur->next;
	}
	if (ft_timecmp(cur, new))
		insert_list(&cur, pre, &new, 0);
	else
		cur->next = new;
}


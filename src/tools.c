/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:08:06 by pconin            #+#    #+#             */
/*   Updated: 2016/05/12 12:00:26 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fil	*ft_fildup(t_fil *old)
{
	t_fil *new;

	new = malloc(sizeof(t_fil));
	new->path = ft_strdup(old->path);
	new->typ = old->typ;
	new->time_s = old->time_s;
	new->hide = old->hide;
	new->rgh = ft_strdup(old->rgh);
	new->name = ft_strdup(old->name);
	new->date_m = ft_strdup(old->date_m);
	new->size = old->size;
	new->us_name = ft_strdup(old->us_name);
	new->gr_name = ft_strdup(old->gr_name);
	new->links = old->links;
	new->bloc = old->bloc;
	new->next = NULL;
	return (new);
}

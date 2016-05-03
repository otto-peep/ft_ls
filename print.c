/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:17:13 by pconin            #+#    #+#             */
/*   Updated: 2016/05/03 12:18:52 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void	print_dir(t_fil *file, t_mem *s)
{
  int i;

  while (file)
    {
      if (s->a == 0 && file->hide == 1)
	;
      else
	{
	  ft_putnbr(file->links);
	  ft_putstr("\t");
	  ft_putstr(file->us_name);
	  ft_putstr("\t");
	  ft_putstr(file->gr_name);
	  ft_putstr("\t");
	  ft_putnbr(file->size);
	  ft_putstr("\t");
	  ft_putstr(file->date_m);
	  ft_putstr("\t");
	  ft_putstr(file->name);
	  ft_putstr("\n");
	}
      file = file->next;
    }
}

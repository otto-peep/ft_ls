/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:06:50 by pconin            #+#    #+#             */
/*   Updated: 2016/04/26 15:18:29 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

#include <dirent.h>
#include <unistd.h>
#include "./libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_mem
{
	char		*arg;
	int			l;
	int			R;
	int			a;
	int			r;
	int			t;
}				t_mem;

#endif

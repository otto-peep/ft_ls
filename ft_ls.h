/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:06:50 by pconin            #+#    #+#             */
/*   Updated: 2016/05/02 18:27:42 by pconin           ###   ########.fr       */
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
#include <time.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>

typedef struct		s_mem
{
	char			*arg;
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
	struct s_fil	*dat;
}					t_mem;

typedef struct		s_fil
{
	char			rgh[10];
	char			*name;
	char			*date_m;
	long long		size;
	struct s_fil	*next;
	char			*us_name;
	char			*gr_name;
}					t_fil;

#endif

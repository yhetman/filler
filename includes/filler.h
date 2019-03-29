/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:00:39 by yhetman           #+#    #+#             */
/*   Updated: 2019/03/26 02:29:45 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_filler
{
	t_coord		*coord;
	t_coord		*piece;
	t_coord		*min;
	t_coord		*map;
	char		my_char;
	char		en_char;
	char		**lines;
	char		**p_arr;
	int			**n_map;
}				t_filler;

void			new_york(t_filler *f);

#endif

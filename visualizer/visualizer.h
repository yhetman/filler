/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 21:55:12 by azavrazh          #+#    #+#             */
/*   Updated: 2019/04/07 20:50:51 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "../libft/includes/libft.h"
# include <curses.h>
# include <stdio.h>
# include <time.h>

typedef struct	s_vis
{
	char		**map;
	int			piece_x;
	int			piece_y;
	int			fin_x;
	int			fin_y;
	int			map_x;
	int			map_y;
	char		**piece;
	char		*player_1;
	char		*player_2;
	WINDOW		*win;
}				t_vis;

#endif

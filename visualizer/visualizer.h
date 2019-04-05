/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 21:55:12 by azavrazh          #+#    #+#             */
/*   Updated: 2019/04/05 17:24:03 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "../libft/includes/libft.h"
# include <ncurses.h>
# include <stdio.h>
# include <time.h>

# define UP 'w'
# define DOWN 's'
# define LEFT 'a'
# define RIGHT 'd'
# define COLOR 2
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
	WINDOW		*win_map;
	WINDOW		*win_piece;
}				t_vis;

enum			e_pcolors
{
	P1 = 10,
	P2,
	ST,
	NEU
};

void			visualize(char *line, t_vis *vis);
void			fill_with_dot(WINDOW *w, char mp);
void			clear_window(WINDOW *w, int height, int width);

#endif

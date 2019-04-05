/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yhetman_vis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 19:37:51 by azavrazh          #+#    #+#             */
/*   Updated: 2019/04/05 17:29:24 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void		clear_window(WINDOW *w, int height, int width)
{
	int			y;
	int			x;

	y = -1;
	while (++y < height)
	{
		wmove(w, y, 0);
		x = -1;
		while (++x < width)
		{
			wattron(w, COLOR_PAIR(NEU));
			wprintw(w, ". ");
			wattroff(w, COLOR_PAIR(NEU));
		}
	}
}

void		fill_with_dot(WINDOW *w, char mp)
{
	if (mp == 'o' || mp == 'O')
		wattron(w, COLOR_PAIR(P1));
	else if (mp == 'x' || mp == 'X')
		wattron(w, COLOR_PAIR(P2));
	else if (mp == '*')
		wattron(w, COLOR_PAIR(ST));
	else
		wattron(w, COLOR_PAIR(NEU));
	wprintw(w, "%c ", mp);
	if (mp == 'o' || mp == 'O')
		wattroff(w, COLOR_PAIR(P1));
	else if (mp == 'x' || mp == 'X')
		wattroff(w, COLOR_PAIR(P2));
	else if (mp == '*')
		wattroff(w, COLOR_PAIR(ST));
	else
		wattroff(w, COLOR_PAIR(NEU));
}

static void		print_results(t_vis *vis)
{
	ft_putstr("Player ");
	ft_putnbr((vis->fin_x > vis->fin_y) ? 2 : 1 );
	ft_putstr(" is the winner!!!\nWith ");
	ft_putnbr((vis->fin_x > vis->fin_y) ? vis->fin_x : vis->fin_y);
	ft_putstr(" gained points!\n");
}

static void		initialize(t_vis *vis)
{
	ft_bzero(vis, sizeof(t_vis));
	initscr();
	raw();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	curs_set(false);
	cbreak();
	noecho();
	use_default_colors();
	start_color();
	init_pair(P1, COLOR_BLACK, 225);
	init_pair(P2, COLOR_BLACK, 225);
	init_pair(ST, 211, 236);
	init_pair(NEU, 177, 236);
}

int				main(void)
{
	t_vis	vis;
	char	*line;

	initialize(&vis);
	while (get_next_line(0, &line) > 0)
		visualize(line, &vis);
	if (getmaxy(stdscr) < 15 || getmaxx(stdscr) < 20)
		ft_strerr("Window is too small, exiting\n");
	endwin();
	print_results(&vis);
	return (0);
}

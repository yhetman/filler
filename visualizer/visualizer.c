/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 19:29:30 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/07 20:10:28 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	fill_dots(WINDOW *w, char c)
{
	if (c == 'o' || c == 'O')
		wattron(w, COLOR_PAIR(1));
	else if (c == 'x' || c == 'X')
		wattron(w, COLOR_PAIR(2));
	else if (c == '*')
		wattron(w, COLOR_PAIR(3));
	else
		wattron(w, COLOR_PAIR(4));
	wprintw(w, "%c ", c);
	if (c == 'o' || c == 'O')
		wattroff(w, COLOR_PAIR(1));
	else if (c == 'x' || c == 'X')
		wattroff(w, COLOR_PAIR(2));
	else if (c == '*')
		wattroff(w, COLOR_PAIR(3));
	else
		wattroff(w, COLOR_PAIR(4));
}

static void	visualize_plateau(t_vis *vis)
{
	int			x;
	int			y;

	y = -1;
	if (vis->win == NULL)
		vis->win = newwin(vis->map_y, vis->map_x * 2, 0,
			COLS / 2 - vis->map_x);
	while (vis->map[++y] && (x = -1))
	{
		wmove(vis->win, y, 0);
		while (vis->map[y][++x])
			fill_dots(vis->win, vis->map[y][x]);
	}
	box(vis->win, 0, 0);
	wrefresh(vis->win);
	usleep(30000);
}

static void	get_plateau(char *line, t_vis *vis)
{
	int	i;

	i = -1;
	vis->map_y = 0;
	while (line[++i])
		if (line[i] == ' ' && vis->map_y == 0)
			vis->map_y = ft_atoi(line + i);
		else if (line[i] == ' ')
			vis->map_x = ft_atoi(line + i);
	if (vis->map == NULL)
		vis->map = (char**)ft_memalloc(sizeof(char*) * (vis->map_y + 1));
	get_next_line(0, &line);
	vis->map[vis->map_y] = NULL;
	i = -1;
	while (++i < vis->map_y)
	{
		if (vis->map[i] != NULL)
			free(vis->map[i] - 4);
		get_next_line(0, &line);
		vis->map[i] = line + 4;
	}
	visualize_plateau(vis);
}

static void	visualize(char *line, t_vis *vis)
{
	if (ft_strstr(line, "Plateau"))
		get_plateau(line, vis);
	else if ((vis->player_1 = ft_strstr(line, "== O fin: ")))
		vis->fin_y = ft_atoi(vis->player_1 + 9);
	else if ((vis->player_2 = ft_strstr(line, "== X fin: ")))
		vis->fin_x = ft_atoi(vis->player_2 + 9);
	free(line);
}

int			main(void)
{
	t_vis	v;
	char	*line;

	ft_bzero(&v, sizeof(t_vis));
	initscr();
	raw();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	curs_set(false);
	cbreak();
	noecho();
	use_default_colors();
	start_color();
	init_pair(1, 210, 210);
	init_pair(2, 44, 44);
	init_pair(3, 147, 147);
	init_pair(4, COLOR_WHITE, COLOR_WHITE);
	while (get_next_line(0, &line) > 0)
		visualize(line, &v);
	endwin();
	ft_printf("\n\t|My congratulations!|\n\n|Player %d won with %d points|\n\n",
		(v.fin_x > v.fin_y) ? 2 : 1,
		(v.fin_x > v.fin_y) ? v.fin_x : v.fin_y);
	return (0);
}

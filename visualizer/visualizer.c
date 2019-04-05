/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 19:29:30 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/05 17:08:20 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	visualize_plateau(t_vis *vis)
{
	int			x;
	int			y;

	if (vis->win_map == NULL)
		vis->win_map = newwin(vis->map_y, vis->map_x * 2, 0, COLS / 2 - vis->map_x);
	y = -1;
	while (vis->map[++y])
	{
		wmove(vis->win_map, y, 0);
		x = -1;
		while (vis->map[y][++x])
			fill_with_dot(vis->win_map, vis->map[y][x]);
	}
	box(vis->win_map, 0, 0);
	wrefresh(vis->win_map);
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

static void	get_piece(char *line, t_vis *vis)
{
	int	i;

	i = -1;
	vis->piece_y = 0;
	while (line[++i])
		if (line[i] == ' ' && vis->piece_y == 0)
			vis->piece_y = ft_atoi(line + i);
		else if (line[i] == ' ')
			vis->piece_x = ft_atoi(line + i);
	if (vis->piece != NULL)
	{
		i = -1;
		while (vis->piece[++i])
			free(vis->piece[i]);
		free(vis->piece);
	}
	vis->piece = (char**)malloc(sizeof(char*) * (vis->piece_y + 1));
	vis->piece[vis->piece_y] = NULL;
	i = -1;
	while (++i < vis->piece_y)
	{
		get_next_line(0, &line);
		vis->piece[i] = line;
	}
}

static void	visualize_piece(t_vis *vis)
{
	int			y;
	int			x;
	const int	height = vis->map_y / 2;
	const int	width = vis->map_x / 2;

	if (vis->win_piece == NULL)
		vis->win_piece = newwin(height, width, 0, COLS / 2 + vis->map_x);
	clear_window(vis->win_piece, height, width);
	y = -1;
	while (vis->piece[++y])
	{
		wmove(vis->win_piece, y, 0);
		x = -1;
		while (vis->piece[y][++x])
			fill_with_dot(vis->win_piece, vis->piece[y][x]);
	}
	box(vis->win_piece, 0, 0);
	wrefresh(vis->win_piece);
}

void		visualize(char *line, t_vis *vis)
{
	if (ft_strstr(line, "Plateau"))
		get_plateau(line, vis);
	else if (ft_strstr(line, "Piece"))
	{
		get_piece(line, vis);
		visualize_piece(vis);
	}
	else if ((vis->player_1 = ft_strstr(line, "== O fin: ")))
			vis->fin_y = ft_atoi(vis->player_1 + 9);
	else if ((vis->player_2 = ft_strstr(line, "== X fin: ")))
			vis->fin_x = ft_atoi(vis->player_2 + 9);
		free(line);
}

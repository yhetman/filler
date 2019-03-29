/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 19:29:30 by yhetman           #+#    #+#             */
/*   Updated: 2019/03/11 18:50:15 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	print_winner(t_map *m)
{
	ft_putstr("Player \'");
	ft_putchar((m->fin.x > m->fin.y) ? 'X' : 'O');
	ft_putstr("\' is the winner!!!\nWith ");
	ft_putnbr((m->fin.x > m->fin.y) ? m->fin.x : m->fin.y);
	ft_putstr(" gained points\n");
}

void	input_plat1(char *line, t_map *m)
{
	int	i;

	i = -1;
	m->mc.y = 0;
	while (line[++i])
		if (line[i] == ' ' && m->mc.y == 0)
			m->mc.y = ft_atoi(line + i);
		else if (line[i] == ' ')
			m->mc.x = ft_atoi(line + i);
	if (m->map == NULL)
		m->map = (char**)ft_memalloc(sizeof(char*) * (m->mc.y + 1));
	get_next_line(0, &line);
	m->map[m->mc.y] = NULL;
	i = -1;
	while (++i < m->mc.y)
	{
		if (m->map[i] != NULL)
			free(m->map[i] - 4);
		get_next_line(0, &line);
		m->map[i] = line + 4;
	}
}

void	input_piece1(char *line, t_map *m)
{
	int	i;

	i = -1;
	m->pc.y = 0;
	while (line[++i])
		if (line[i] == ' ' && m->pc.y == 0)
			m->pc.y = ft_atoi(line + i);
		else if (line[i] == ' ')
			m->pc.x = ft_atoi(line + i);
	if (m->piece != NULL)
	{
		i = -1;
		while (m->piece[++i])
			free(m->piece[i]);
		free(m->piece);
	}
	m->piece = (char**)malloc(sizeof(char*) * (m->pc.y + 1));
	m->piece[m->pc.y] = NULL;
	i = -1;
	while (++i < m->pc.y)
	{
		get_next_line(0, &line);
		m->piece[i] = line;
	}
}

void	init_vis(t_map *m)
{
	ft_bzero(m, sizeof(t_map));
	initscr();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	curs_set(false);
	cbreak();
	noecho();
	use_default_colors();
	start_color();
	init_pair(P1, 52, 236);
	init_pair(P2, 56, 236);
	init_pair(ST, 211, 236);
	init_pair(NEU, 177, 236);
}

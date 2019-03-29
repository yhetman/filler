/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:04:00 by yhetman           #+#    #+#             */
/*   Updated: 2019/03/26 02:23:03 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	set_zero(t_coord *p)
{
	p->x = 0;
	p->y = 0;
}

static void	size_of_map(t_filler *info, char *line)
{
	char	**size;

	size = ft_strsplit(line, ' ');
	info->map->x = ft_atoi(size[1]);
	info->map->y = ft_atoi(size[2]);
}

static void	get_info_map(t_filler *f)
{
	int		i;
	char	*line;
	char	*l;
	char	**size;

	i = -1;
	get_next_line(0, &line);
	while (get_next_line(0, &line) > 0
		&& !ft_strstr(line, "Piece"))
		if (++i < f->map->x)
			ft_strcpy(f->lines[i], &line[4]);
	i = -1;
	size = ft_strsplit(line, ' ');
	f->piece->x = ft_atoi(size[1]);
	f->piece->y = ft_atoi(size[2]);
	f->p_arr = (char **)malloc(sizeof(char *) * f->piece->x);
	while (++i < f->piece->x)
	{
		get_next_line(0, &l);
		f->p_arr[i] = ft_strdup(l);
	}
	new_york(f);
}

static void	initialize(t_filler *f, char *line)
{
	f->coord = (t_coord *)malloc(sizeof(t_coord));
	f->piece = (t_coord *)malloc(sizeof(t_coord));
	f->min = (t_coord *)malloc(sizeof(t_coord));
	f->map = (t_coord *)malloc(sizeof(t_coord));
	set_zero(f->coord);
	set_zero(f->piece);
	set_zero(f->min);
	set_zero(f->map);
	if (ft_strstr(line, "$$$"))
	{
		if (ft_strstr(line, "p1"))
		{
			f->my_char = 'O';
			f->en_char = 'X';
		}
		else if (ft_strstr(line, "p2"))
		{
			f->my_char = 'X';
			f->en_char = 'O';
		}
	}
}

int			main(void)
{
	t_filler	f;
	char		*line;
	int			i;

	i = -1;
	get_next_line(0, &line);
	initialize(&f, line);
	while (!ft_strstr(line, "Plateau"))
		get_next_line(0, &line);
	size_of_map(&f, line);
	f.lines = (char **)malloc(sizeof(char *) * f.map->x);
	f.n_map = (int **)malloc(sizeof(int *) * f.map->x);
	while (++i < f.map->x)
	{
		f.lines[i] = (char *)malloc(sizeof(char) * (f.map->y + 1));
		f.n_map[i] = (int *)malloc(sizeof(int) * f.map->y);
	}
	get_info_map(&f);
	while (get_next_line(0, &line))
		get_info_map(&f);
	return (0);
}

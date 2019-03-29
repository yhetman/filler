/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manhatten.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:00:34 by yhetman           #+#    #+#             */
/*   Updated: 2019/03/26 02:23:02 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	set_zero(t_coord *p)
{
	p->x = 0;
	p->y = 0;
}

static int	distance(t_filler *f, int x, int y)
{
	t_coord	*index;
	int		min;
	int		len;

	len = 0;
	min = f->map->x * f->map->y;
	index = (t_coord *)malloc(sizeof(t_coord));
	index->x = -1;
	while (++index->x < f->map->x && (index->y = -1))
		while (++index->y < f->map->y)
			if (f->n_map[index->x][index->y] == -2)
			{
				len = abs(index->x - x) + abs(index->y - y);
				if (len < min)
					min = len;
			}
	return (min);
}

static int	scoring(t_filler *f, int i, int j, int sum)
{
	t_coord	*index;
	t_coord	*cell;

	index = (t_coord *)malloc(sizeof(t_coord));
	cell = (t_coord *)malloc(sizeof(t_coord));
	set_zero(cell);
	index->x = -1;
	while (++index->x < f->piece->x && (index->y = -1))
		while (++index->y < f->piece->y)
			if (f->p_arr[index->x][index->y] == '*')
			{
				if ((index->x + i) < 0 || (index->x + i) >= f->map->x
					|| (index->y + j) < 0 || (index->y + j) >= f->map->y)
					return (0);
				if (f->n_map[index->x + i][index->y + j] == -1)
					cell->x++;
				if (f->n_map[index->x + i][index->y + j] == -2)
					cell->y++;
				sum += f->n_map[index->x + i][index->y + j];
			}
	if (cell->y || cell->x != 1)
		return (0);
	return (sum);
}

static void	placement(t_filler *f)
{
	t_coord	*i;
	int		res;
	int		distance;

	i = (t_coord *)malloc(sizeof(t_coord));
	set_zero(i);
	distance = f->map->x * f->map->y;
	i->x = -f->piece->x;
	while (++i->x < f->map->x + f->piece->x && (i->y = -f->piece->y))
		while (++i->y < f->map->y + f->piece->y)
		{
			res = 0;
			res = scoring(f, i->x, i->y, res);
			if (res != 0 && res < distance)
			{
				f->coord->x = i->x;
				f->coord->y = i->y;
				distance = res;
			}
		}
	ft_printf("%d %d\n", f->coord->x, f->coord->y);
}

void		new_york(t_filler *f)
{
	t_coord	*index;

	index = (t_coord *)malloc(sizeof(t_coord *));
	index->x = -1;
	while (++index->x < f->map->x && (index->y = -1))
		while (++index->y < f->map->y)
			if (f->lines[index->x][index->y] == '.')
				f->n_map[index->x][index->y] = 0;
			else if (f->lines[index->x][index->y] == f->my_char
				|| f->lines[index->x][index->y] == f->my_char + 32)
				f->n_map[index->x][index->y] = -1;
			else if (f->lines[index->x][index->y] == f->en_char
				|| f->lines[index->x][index->y] == f->en_char + 32)
				f->n_map[index->x][index->y] = -2;
	index->x = -1;
	while (++index->x < f->map->x && (index->y = -1))
		while (++index->y < f->map->y)
			if (f->lines[index->x][index->y] == '.')
				f->n_map[index->x][index->y] = distance(f, index->x, index->y);
	placement(f);
}
